//
// Created by Matt on 3/10/2016.
//

#ifndef CARDINTERLACER_CARDDISPLAY_H
#define CARDINTERLACER_CARDDISPLAY_H

#include "CardNode.h"

using namespace model;

namespace view {
    class CardDisplay {
    private:

    public:
        CardDisplay();


        void PrintCardByNameAscending(const CardNode *card);

        void PrintCardByYearAscending(const CardNode *card);

        void PrintCardByConditionAscending(const CardNode *card);

        void PrintCardByNameDescending(const CardNode *card);

        void PrintCardByYearDescending(const CardNode *card);

        void PrintCardByConditionDescending(const CardNode *card);

        void DisplayMenu();

    };

}


#endif //CARDINTERLACER_CARDDISPLAY_H
