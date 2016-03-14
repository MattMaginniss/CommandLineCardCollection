//
// Created by Matt on 3/10/2016.
//

#include "CardCollection.h"

namespace model {

    CardCollection::CardCollection() {
        this->NameHead = _NULL;
        this->YearHead = _NULL;
        this->ConditionHead = _NULL;
    }

    void CardCollection::InsertNode(CardNode *node) {
        if (this->NameHead == _NULL || this->YearHead == _NULL || this->ConditionHead == _NULL) {
            this->NameHead = node;
            this->YearHead = node;
            this->ConditionHead = node;
        } else {
            CardNode *previousYearNode = this->YearHead;
            CardNode *previousNameNode = this->NameHead;
            CardNode *previousConditionNode = this->ConditionHead;

            insertCardByName(node, previousNameNode);
            insertCardByYear(node, previousYearNode);
            insertCardByCondition(node, previousConditionNode);
        }
    }

    void CardCollection::insertCardByName(CardNode *node, CardNode *previousNameNode) {
        if (node->GetName() <= this->NameHead->GetName()) {
            node->nextName = this->NameHead;
            this->NameHead = node;
        } else if (previousNameNode->nextName == _NULL) {
            previousNameNode->nextName = node;
        } else if (node->GetName() <= previousNameNode->nextName->GetName()) {
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
        } else if (previousYearNode->nextYear == _NULL) {
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
        } else if (previousConditionNode->nextCondition == _NULL) {
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

}