//
// Created by Matt on 3/10/2016.
//

#include <iostream>
#include "CardDisplay.h"

namespace view {

    CardDisplay::CardDisplay() {

    }

    void CardDisplay::PrintCardDetails(CardNode *card) {
        if (card != _NULL) {
            cout << card->GetName() << " " << card->GetYear() << " " <<card->GetCondition() << " " <<card->GetValue() << endl;
            PrintCardDetails(card->nextYear);
        }
    }
}