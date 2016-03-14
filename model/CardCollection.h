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

        void insertCardByName(CardNode *node, CardNode *previousNameNode);

        void insertCardByYear(CardNode *node, CardNode *previousYearNode);

        void insertCardByCondition(CardNode *node, CardNode *previousConditionNode);

    public:
        CardCollection();

        CardNode *GetNameHead();

        CardNode *GetYearHead();

        CardNode *GetConditionHead();

        void InsertNode(CardNode *node);

        void DeleteNode(CardNode *node);

    };
}

#endif //CARDINTERLACER_CARDCOLLECTION_H
