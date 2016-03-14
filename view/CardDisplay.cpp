//
// Created by Matt on 3/10/2016.
//

#include <iostream>
#include "CardDisplay.h"

namespace view {

    CardDisplay::CardDisplay() {

    }


    void CardDisplay::PrintCardByNameAscending(const CardNode *card) {
        if (card != _NULL) {
            cout << card->GetName() << " " << card->GetYear() << " " << card->GetCondition() << " " << card->GetValue() << endl;
            this->PrintCardByNameAscending(card->nextName);
        }
    }

    void CardDisplay::PrintCardByYearAscending(const CardNode *card) {
        if (card != _NULL) {
            cout << card->GetName() << " " << card->GetYear() << " " << card->GetCondition() << " " << card->GetValue() << endl;
            this->PrintCardByYearAscending(card->nextYear);
        }
    }

    void CardDisplay::PrintCardByConditionAscending(const CardNode *card) {
        if (card != _NULL) {
            cout << card->GetName() << " " << card->GetYear() << " " << card->GetCondition() << " " << card->GetValue() << endl;
            this->PrintCardByConditionAscending(card->nextCondition);
        }
    }

    void CardDisplay::PrintCardByNameDescending(const CardNode *card) {
        if (card != _NULL) {
            this->PrintCardByNameDescending(card->nextName);
            cout << card->GetName() << " " << card->GetYear() << " " << card->GetCondition() << " " << card->GetValue() << endl;
        }

    }

    void CardDisplay::PrintCardByYearDescending(const CardNode *card) {
        if (card != _NULL) {
            this->PrintCardByYearDescending(card->nextYear);
            cout << card->GetName() << " " << card->GetYear() << " " << card->GetCondition() << " " << card->GetValue() << endl;
        }

    }

    void CardDisplay::PrintCardByConditionDescending(const CardNode *card) {
        if (card != _NULL) {
            this->PrintCardByConditionDescending(card->nextCondition);
            cout << card->GetName() << " " << card->GetYear() << " " << card->GetCondition() << " " << card->GetValue() << endl;
        }
    }
}