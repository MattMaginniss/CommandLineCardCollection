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
        void PrintCardDetails(CardNode *card);

    };

}


#endif //CARDINTERLACER_CARDDISPLAY_H
