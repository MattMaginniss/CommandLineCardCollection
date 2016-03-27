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

    void CardCollection::InsertNode(CardNode *insertingNode) {
        if (this->NameHead == 0 || this->YearHead == 0 || this->ConditionHead == 0) {
            this->NameHead = insertingNode;
            this->YearHead = insertingNode;
            this->ConditionHead = insertingNode;
            this->largestNameLength = (int) insertingNode->GetName().size();
        } else {
            CardNode *previousNameNode = this->NameHead;
            CardNode *previousYearNode = this->YearHead;
            CardNode *previousConditionNode = this->ConditionHead;

            this->insertCardByName(insertingNode, previousNameNode);
            this->insertCardByYear(insertingNode, previousYearNode);
            this->insertCardByCondition(insertingNode, previousConditionNode);

            if ((int) insertingNode->GetName().size() > this->largestNameLength) {
                this->largestNameLength = (int) insertingNode->GetName().size();
            }
        }
    }

    void CardCollection::insertCardByName(CardNode *insertingNode, CardNode *previousNameNode) {
        if (insertingNode->GetLowerName() <= this->NameHead->GetLowerName()) {
            insertingNode->SetNextName(this->NameHead);
            this->NameHead = insertingNode;
        } else if (previousNameNode->GetNextName() == 0) {
            previousNameNode->SetNextName(insertingNode);
        } else if (insertingNode->GetLowerName() <=
                   previousNameNode->GetNextName()->GetLowerName()) {
            insertingNode->SetNextName(previousNameNode->GetNextName());
            previousNameNode->SetNextName(insertingNode);
        } else {
            this->insertCardByName(insertingNode, previousNameNode->GetNextName());
        }
    }

    void CardCollection::insertCardByYear(CardNode *insertingNode, CardNode *previousYearNode) {
        if (insertingNode->GetYear() <= this->YearHead->GetYear()) {
            insertingNode->SetNextYear(this->YearHead);
            this->YearHead = insertingNode;
        } else if (previousYearNode->GetNextYear() == 0) {
            previousYearNode->SetNextYear(insertingNode);
        } else if (insertingNode->GetYear() <= previousYearNode->GetNextYear()->GetYear()) {
            insertingNode->SetNextYear(previousYearNode->GetNextYear());
            previousYearNode->SetNextYear(insertingNode);
        } else {
            this->insertCardByYear(insertingNode, previousYearNode->GetNextYear());
        }
    }

    void CardCollection::insertCardByCondition(CardNode *insertingNode, CardNode *previousConditionNode) {
        if (insertingNode->GetCondition() <= this->ConditionHead->GetCondition()) {
            insertingNode->SetNextCondition(this->ConditionHead);
            this->ConditionHead = insertingNode;
        } else if (previousConditionNode->GetNextCondition() == 0) {
            previousConditionNode->SetNextCondition(insertingNode);
        } else if (insertingNode->GetCondition() <= previousConditionNode->GetNextCondition()->GetCondition()) {
            insertingNode->SetNextCondition(previousConditionNode->GetNextCondition());
            previousConditionNode->SetNextCondition(insertingNode);
        } else {
            this->insertCardByCondition(insertingNode, previousConditionNode->GetNextCondition());
        }
    }


    void CardCollection::DeleteNode(CardNode *deletingNode) {
        CardNode *previousNameNode = this->NameHead;
        CardNode *previousYearNode = this->YearHead;
        CardNode *previousConditionNode = this->ConditionHead;

        this->deleteCardByName(deletingNode, previousNameNode);
        this->deleteCardByYear(deletingNode, previousYearNode);
        this->deleteCardByCondition(deletingNode, previousConditionNode);

        delete (deletingNode);
    }

    void CardCollection::deleteCardByName(CardNode *deletingNode, CardNode *previousNameNode) {
        bool deleted = false;
        if (deletingNode == this->NameHead) {
            this->NameHead = deletingNode->GetNextName();
            deleted = true;
        }
        while (!deleted) {
            if (previousNameNode->GetNextName() == deletingNode) {
                previousNameNode->SetNextName(deletingNode->GetNextName());
                deleted = true;
            } else {
                previousNameNode = previousNameNode->GetNextName();
            }
        }
    }

    void CardCollection::deleteCardByYear(CardNode *deletingNode, CardNode *previousYearNode) {
        bool deleted = false;
        if (deletingNode == this->YearHead) {
            this->YearHead = deletingNode->GetNextYear();
            deleted = true;
        }
        while (!deleted) {
            if (previousYearNode->GetNextYear() == deletingNode) {
                previousYearNode->SetNextYear(deletingNode->GetNextYear());
                deleted = true;
            } else {
                previousYearNode = previousYearNode->GetNextYear();
            }
        }
    }

    void CardCollection::deleteCardByCondition(CardNode *deletingNode, CardNode *previousConditionNode) {
        bool deleted = false;
        if (deletingNode == this->ConditionHead) {
            this->ConditionHead = deletingNode->GetNextCondition();
            deleted = true;
        }
        while (!deleted) {
            if (previousConditionNode->GetNextCondition() == deletingNode) {
                previousConditionNode->SetNextCondition(deletingNode->GetNextCondition());
                deleted = true;
            } else {
                previousConditionNode = previousConditionNode->GetNextCondition();
            }
        }
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

    CardNode *CardCollection::GetYearHead() {
        return this->YearHead;
    }

    CardNode *CardCollection::GetNameHead() {
        return this->NameHead;
    }

    CardNode *CardCollection::GetConditionHead() {
        return this->ConditionHead;
    }

    int CardCollection::GetLargestNameLength() {
        return this->largestNameLength;
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

}