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
        int largestNameLength = 0;

        void insertCardByName(CardNode *node, CardNode *previousNameNode);

        void insertCardByYear(CardNode *node, CardNode *previousYearNode);

        void insertCardByCondition(CardNode *node, CardNode *previousConditionNode);

        void deleteCardByName(CardNode *node, CardNode *previousNameNode);

        void deleteCardByYear(CardNode *node, CardNode *previousNameNode);

        void deleteCardByCondition(CardNode *node, CardNode *previousNameNode);

    public:
        // Constructor for a CardCollection object.
        CardCollection();

        // Deconstructor for a CardCollection object.
        virtual ~CardCollection();

        // Getter for the Name head of the list.
        CardNode *GetNameHead();

        // Getter for the Year head of the list.
        CardNode *GetYearHead();

        // Getter for the Condition head of the list.
        CardNode *GetConditionHead();

        // This method will insert a node into the list.
        // @param *node the node to be inserted into the list.
        void InsertNode(CardNode *node);

        // This method will removed the node from the list.
        // @param *node the node to be removed from the list.
        void DeleteNode(CardNode *node);

        // This will find a card node in the list by name and return the location of the node.
        // @param cardName the name of the card to be found within the list.
        CardNode *FindCardNode(string cardName);

        // This will return the length of the largest
        int GetLargestNameLength();

    };
}

#endif //CARDINTERLACER_CARDCOLLECTION_H
