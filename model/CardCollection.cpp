//
// Created by Matt on 3/10/2016.
//

#include "CardCollection.h"

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
        } else {
            CardNode *previousYearNode = this->YearHead;
            CardNode *previousNameNode = this->NameHead;
            CardNode *previousConditionNode = this->ConditionHead;

            this->insertCardByName(node, previousNameNode);
            this->insertCardByYear(node, previousYearNode);
            this->insertCardByCondition(node, previousConditionNode);
        }
    }

    void CardCollection::DeleteNode(CardNode *node) {
        CardNode *previousNameNode = this->NameHead;
        CardNode *previousYearNode = this->YearHead;
        CardNode *previousConditionNode = this->ConditionHead;

        this->deleteCardByName(node, previousNameNode);
        this->deleteCardByYear(node, previousYearNode);
        this->deleteCardByCondition(node, previousConditionNode);
    }

    void CardCollection::insertCardByName(CardNode *node, CardNode *previousNameNode) {
        if (this->convertToLower(node->GetName()) <= this->convertToLower(this->NameHead->GetName())) {
            node->nextName = this->NameHead;
            this->NameHead = node;
        } else if (previousNameNode->nextName == 0) {
            previousNameNode->nextName = node;
        } else if (this->convertToLower(node->GetName()) <=
                   this->convertToLower(previousNameNode->nextName->GetName())) {
            node->SetNextName(previousNameNode->nextName);
            previousNameNode->SetNextName(node);
        } else {
            this->insertCardByName(node, previousNameNode->nextName);
        }
    }

    void CardCollection::insertCardByYear(CardNode *node, CardNode *previousYearNode) {
        if (node->GetYear() <= this->YearHead->GetYear()) {
            node->nextYear = this->YearHead;
            this->YearHead = node;
        } else if (previousYearNode->nextYear == 0) {
            previousYearNode->nextYear = node;
        } else if (node->GetYear() <= previousYearNode->nextYear->GetYear()) {
            node->SetNextYear(previousYearNode->nextYear);
            previousYearNode->SetNextYear(node);
        } else {
            this->insertCardByYear(node, previousYearNode->nextYear);
        }
    }

    void CardCollection::insertCardByCondition(CardNode *node, CardNode *previousConditionNode) {
        if (node->GetCondition() <= this->ConditionHead->GetCondition()) {
            node->nextCondition = this->ConditionHead;
            this->ConditionHead = node;
        } else if (previousConditionNode->nextCondition == 0) {
            previousConditionNode->nextCondition = node;
        } else if (node->GetCondition() <= previousConditionNode->nextCondition->GetCondition()) {
            node->SetNextCondition(previousConditionNode->nextCondition);
            previousConditionNode->SetNextCondition(node);
        } else {
            this->insertCardByCondition(node, previousConditionNode->nextCondition);
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
        string name = this->convertToLower(cardName);
        CardNode *node = this->NameHead;
        CardNode *correctNode = 0;
        while (node != 0) {
            string currentNodeName = this->convertToLower(node->GetName());
            if (name.compare(currentNodeName) == 0) {
                correctNode = node;
                node = 0;
            } else {
                node = node->nextName;
            }
        }
        return correctNode;
    }

    string CardCollection::convertToLower(const string &toBeConverted) const {
        locale loc;
        string value = toBeConverted;
        for (string::size_type i = 0; i < value.length(); ++i)
            value[i] = tolower(value[i], loc);
        return value;
    }

    void CardCollection::deleteCardByName(CardNode *node, CardNode *previousNameNode) {
        bool deleted = false;
        if (node == this->NameHead) {
            this->NameHead = node->nextName;
            deleted = true;
        }
        while (!deleted) {
            if (previousNameNode->nextName == node) {
                previousNameNode->nextName = node->nextName;
                deleted = true;
            } else {
                previousNameNode = previousNameNode->nextName;
            }
        }
    }

    void CardCollection::deleteCardByYear(CardNode *node, CardNode *previousYearNode) {
        bool deleted = false;
        if (node == this->YearHead) {
            this->YearHead = node->nextYear;
            deleted = true;
        }
        while (!deleted) {
            if (previousYearNode->nextYear == node) {
                previousYearNode->nextYear = node->nextYear;
                deleted = true;
            } else {
                previousYearNode = previousYearNode->nextYear;
            }
        }
    }

    void CardCollection::deleteCardByCondition(CardNode *node, CardNode *previousConditionNode) {
        bool deleted = false;
        if (node == this->ConditionHead) {
            this->ConditionHead = node->nextCondition;
            deleted = true;
        }
        while (!deleted) {
            if (previousConditionNode->nextCondition == node) {
                previousConditionNode->nextCondition = node->nextCondition;
                deleted = true;
            } else {
                previousConditionNode = previousConditionNode->nextCondition;
            }
        }
    }

    CardCollection::~CardCollection() {
        CardNode *currentNode = this->YearHead;

        while (currentNode != 0) {
            CardNode *nextNode = currentNode->nextYear;
            delete (currentNode);
            currentNode = nextNode;
        }
        this->NameHead = 0;
        this->YearHead = 0;
        this->ConditionHead = 0;
    }
}