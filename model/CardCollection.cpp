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
            insertCardByYear(node, previousYearNode);
        }
    }

    void CardCollection::insertCardByYear(CardNode *node, CardNode *previousYearNode) const {
        if (previousYearNode->nextYear == _NULL) {
            previousYearNode->nextYear == node;
        } else if (node->GetYear() <= previousYearNode->nextYear->GetYear()) {
            node->SetNextYear(previousYearNode->nextYear);
            previousYearNode->SetNextYear(node);
        } else {
            this->insertCardByYear(node, previousYearNode->nextYear);
        }
    }
}