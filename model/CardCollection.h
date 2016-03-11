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

        void InsertNode(CardNode *node);

        void DeleteNode(CardNode *node);
    };
}

#endif //CARDINTERLACER_CARDCOLLECTION_H
