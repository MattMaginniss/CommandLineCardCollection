//
// Created by Matt on 3/10/2016.
//

#include "CardCollection.h"
#include <algorithm>

namespace model {

    CardCollection::CardCollection() {
        this->NameHead = 0;
        this->YearHead = 0;
        this->ConditionHead = 0;
    }

    void CardCollection::InsertNode(CardNode *node) {
        if (this->NameHead == 0 || this->YearHead == 0 || this->ConditionHead == 0) {
            this->NameHead = node;
            this->YearHead = node;
            this->ConditionHead = node;
            this->largestNameLength = (int) node->GetName().size();
        } else {
            CardNode *previousNameNode = this->NameHead;
            CardNode *previousYearNode = this->YearHead;
            CardNode *previousConditionNode = this->ConditionHead;

            this->insertCardByName(node, previousNameNode);
            this->insertCardByYear(node, previousYearNode);
            this->insertCardByCondition(node, previousConditionNode);

            if ((int) node->GetName().size() > this->largestNameLength) {
                this->largestNameLength = (int) node->GetName().size();
            }
        }
    }

    void CardCollection::DeleteNode(CardNode *node) {
        CardNode *previousNameNode = this->NameHead;
        CardNode *previousYearNode = this->YearHead;
        CardNode *previousConditionNode = this->ConditionHead;

        this->deleteCardByName(node, previousNameNode);
        this->deleteCardByYear(node, previousYearNode);
        this->deleteCardByCondition(node, previousConditionNode);

        delete (node);
    }

    void CardCollection::insertCardByName(CardNode *node, CardNode *previousNameNode) {
        if (node->GetLowerName() <= this->NameHead->GetLowerName()) {
            node->SetNextName(this->NameHead);
            this->NameHead = node;
        } else if (previousNameNode->GetNextName() == 0) {
            previousNameNode->SetNextName(node);
        } else if (node->GetLowerName() <=
                   previousNameNode->GetNextName()->GetLowerName()) {
            node->SetNextName(previousNameNode->GetNextName());
            previousNameNode->SetNextName(node);
        } else {
            this->insertCardByName(node, previousNameNode->GetNextName());
        }
    }

    void CardCollection::insertCardByYear(CardNode *node, CardNode *previousYearNode) {
        if (node->GetYear() <= this->YearHead->GetYear()) {
            node->SetNextYear(this->YearHead);
            this->YearHead = node;
        } else if (previousYearNode->GetNextYear() == 0) {
            previousYearNode->SetNextYear(node);
        } else if (node->GetYear() <= previousYearNode->GetNextYear()->GetYear()) {
            node->SetNextYear(previousYearNode->GetNextYear());
            previousYearNode->SetNextYear(node);
        } else {
            this->insertCardByYear(node, previousYearNode->GetNextYear());
        }
    }

    void CardCollection::insertCardByCondition(CardNode *node, CardNode *previousConditionNode) {
        if (node->GetCondition() <= this->ConditionHead->GetCondition()) {
            node->SetNextCondition(this->ConditionHead);
            this->ConditionHead = node;
        } else if (previousConditionNode->GetNextCondition() == 0) {
            previousConditionNode->SetNextCondition(node);
        } else if (node->GetCondition() <= previousConditionNode->GetNextCondition()->GetCondition()) {
            node->SetNextCondition(previousConditionNode->GetNextCondition());
            previousConditionNode->SetNextCondition(node);
        } else {
            this->insertCardByCondition(node, previousConditionNode->GetNextCondition());
        }
    }

    CardNode *CardCollection::GetYearHead() {
        return this->YearHead;
    }

    CardNode *CardCollection::GetNameHead() {
        return this->NameHead;
    }

    CardNode *CardCollection::GetConditionHead() {
        return this->ConditionHead;
    }

    CardNode *CardCollection::FindCardNode(string cardName) {
        string name = cardName;
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        CardNode *node = this->NameHead;
        CardNode *correctNode = 0;
        while (node != 0) {
            if (name.compare(node->GetLowerName()) == 0) {
                correctNode = node;
                node = 0;
            } else {
                node = node->GetNextName();
            }
        }
        return correctNode;
    }

    void CardCollection::deleteCardByName(CardNode *node, CardNode *previousNameNode) {
        bool deleted = false;
        if (node == this->NameHead) {
            this->NameHead = node->GetNextName();
            deleted = true;
        }
        while (!deleted) {
            if (previousNameNode->GetNextName() == node) {
                previousNameNode->SetNextName(node->GetNextName());
                deleted = true;
            } else {
                previousNameNode = previousNameNode->GetNextName();
            }
        }
    }

    void CardCollection::deleteCardByYear(CardNode *node, CardNode *previousYearNode) {
        bool deleted = false;
        if (node == this->YearHead) {
            this->YearHead = node->GetNextYear();
            deleted = true;
        }
        while (!deleted) {
            if (previousYearNode->GetNextYear() == node) {
                previousYearNode->SetNextYear(node->GetNextYear());
                deleted = true;
            } else {
                previousYearNode = previousYearNode->GetNextYear();
            }
        }
    }

    void CardCollection::deleteCardByCondition(CardNode *node, CardNode *previousConditionNode) {
        bool deleted = false;
        if (node == this->ConditionHead) {
            this->ConditionHead = node->GetNextCondition();
            deleted = true;
        }
        while (!deleted) {
            if (previousConditionNode->GetNextCondition() == node) {
                previousConditionNode->SetNextCondition(node->GetNextCondition());
                deleted = true;
            } else {
                previousConditionNode = previousConditionNode->GetNextCondition();
            }
        }
    }

    CardCollection::~CardCollection() {
        CardNode *currentNode = this->YearHead;

        while (currentNode != 0) {
            CardNode *nextNode = currentNode->GetNextYear();
            delete (currentNode);
            currentNode = nextNode;
        }
        this->NameHead = 0;
        this->YearHead = 0;
        this->ConditionHead = 0;
    }

    int CardCollection::GetLargestNameLength() {
        return this->largestNameLength;
    }
}