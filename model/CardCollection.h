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

        string convertToLower(const string &toBeConverted) const;

        void deleteCardByName(CardNode *node, CardNode *previousNameNode);

        void deleteCardByYear(CardNode *node, CardNode *previousNameNode);

        void deleteCardByCondition(CardNode *node, CardNode *previousNameNode);

    public:
        CardCollection();

        virtual ~CardCollection();

        CardNode *GetNameHead();

        CardNode *GetYearHead();

        CardNode *GetConditionHead();

        void InsertNode(CardNode *node);

        void DeleteNode(CardNode *node);

        CardNode *FindCardNode(string cardName);

    };
}

#endif //CARDINTERLACER_CARDCOLLECTION_H
