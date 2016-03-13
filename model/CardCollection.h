//
// Created by Matt on 3/10/2016.
//

#ifndef CARDINTERLACER_CARDCOLLECTION_H
#define CARDINTERLACER_CARDCOLLECTION_H


#include "CardNode.h"

namespace model {
    class CardCollection {
    private:
        CardNode *NameHead;
        CardNode *YearHead;
        CardNode *ConditionHead;


    public:
        CardCollection();

        CardNode* GetNameHead();
        CardNode* GetYearHead();
        CardNode* GetConditionHead();

        void InsertNode(CardNode *node);

        void DeleteNode(CardNode *node);

        void insertCardByYear(CardNode *node, CardNode *previousYearNode);
    };
}

#endif //CARDINTERLACER_CARDCOLLECTION_H
