//
// Created by Matt on 3/10/2016.
//

#include <iostream>
#include "CardDisplay.h"

namespace view {

    CardDisplay::CardDisplay() {

    }


    void CardDisplay::PrintCardByNameAscending(const CardNode *card) {
        cout << card->GetName() << " " << card->GetYear() << " " << card->GetCondition() << " " << card->GetValue() << endl;
        PrintCardByNameAscending(card->nextName);
    }

    void CardDisplay::PrintCardByYearAscending(const CardNode *card) {
        cout << card->GetName() << " " << card->GetYear() << " " << card->GetCondition() << " " << card->GetValue() << endl;
        PrintCardByYearAscending(card->nextYear);
    }

    void CardDisplay::PrintCardByConditionAscending(const CardNode *card) {
        cout << card->GetName() << " " << card->GetYear() << " " << card->GetCondition() << " " << card->GetValue() << endl;
        PrintCardByConditionAscending(card->nextCondition);
    }

}