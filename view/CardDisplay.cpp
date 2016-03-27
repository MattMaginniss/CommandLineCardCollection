//
// Created by Matt on 3/10/2016.
//

#include <iostream>
#include <iomanip>
#include "CardDisplay.h"

namespace view {
    void CardDisplay::PrintCardByNameAscending(const CardNode *card) {
        if (card != 0) {
            this->displayCardDataConsoleFormat(card);
            this->PrintCardByNameAscending(card->GetNextName());
        }
    }

    void CardDisplay::PrintCardByYearAscending(const CardNode *card) {
        if (card != 0) {
            this->displayCardDataConsoleFormat(card);
            this->PrintCardByYearAscending(card->GetNextYear());
        }
    }

    void CardDisplay::PrintCardByConditionAscending(const CardNode *card) {
        if (card != 0) {
            this->displayCardDataConsoleFormat(card);
            this->PrintCardByConditionAscending(card->GetNextCondition());
        }
    }

    void CardDisplay::PrintCardByNameDescending(const CardNode *card) {
        if (card != 0) {
            this->PrintCardByNameDescending(card->GetNextName());
            this->displayCardDataConsoleFormat(card);
        }

    }

    void CardDisplay::PrintCardByYearDescending(const CardNode *card) {
        if (card != 0) {
            this->PrintCardByYearDescending(card->GetNextYear());
            this->displayCardDataConsoleFormat(card);
        }

    }

    void CardDisplay::PrintCardByConditionDescending(const CardNode *card) {
        if (card != 0) {
            this->PrintCardByConditionDescending(card->GetNextCondition());
            this->displayCardDataConsoleFormat(card);
        }
    }

    void CardDisplay::PrintCardsForFileFormat(const CardNode *card) {
        if (card != 0) {
            this->displayCardDataFileFormat(card);
            this->PrintCardsForFileFormat(card->GetNextName());
        }
    }

    void CardDisplay::DisplayMenu() {
        cout << " " << endl;
        cout << "Please enter the desired action:" << endl;
        cout << "\t1. Load File" << endl;
        cout << "\t2. Save File" << endl;
        cout << "\t3. Insert Card" << endl;
        cout << "\t4. Delete Card" << endl;
        cout << "\t5. Print Alphabetic" << endl;
        cout << "\t6. Reverse Alphabetic" << endl;
        cout << "\t7. Year Ascending" << endl;
        cout << "\t8. Year Descending" << endl;
        cout << "\t9. Condition Ascending" << endl;
        cout << "\t10. Condition Descending" << endl;
        cout << "\t11. Quit" << endl;
        cout << " " << endl;
        cout << "Enter Action >";
    }

    void CardDisplay::displayCardDataFileFormat(const CardNode *card) {
        cout << card->GetName() << "," << card->GetYear() << "," << card->GetCondition() << "," << card->GetValue() <<
        endl;
    }

    void CardDisplay::DisplayMessage(const string &message) {
        cout << message << endl;
    }

    void CardDisplay::DisplayWelcome() {
        cout << "" << endl;
        cout << "Welcome to Matt Maginniss' Baseball Card Collector" << endl;
        cout << "--------------------------------------------------" << endl;
    }

    void CardDisplay::displayCardDataConsoleFormat(const CardNode *card) {
        string value = "$" + to_string(card->GetValue()) + ".00";
        cout << setw(25) << left << card->GetName() << setw(6) << left << card->GetYear() << setw(12) << left <<
        card->GetCondition() << setw(15) << right << value << endl;

    }

}