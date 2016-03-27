//
// Created by Matt on 3/10/2016.
//

#include <iostream>
#include <iomanip>
#include "CardDisplay.h"

namespace view {
    void CardDisplay::PrintCardByNameAscending(const CardNode *card, int nameWidth) {
        if (card != 0) {
            this->displayCardDataConsoleFormat(card, nameWidth);
            this->PrintCardByNameAscending(card->GetNextName(), nameWidth);
        }
    }

    void CardDisplay::PrintCardByNameDescending(const CardNode *card, int nameWidth) {
        if (card != 0) {
            this->PrintCardByNameDescending(card->GetNextName(), nameWidth);
            this->displayCardDataConsoleFormat(card, nameWidth);
        }

    }

    void CardDisplay::PrintCardByYearAscending(const CardNode *card, int nameWidth) {
        if (card != 0) {
            this->displayCardDataConsoleFormat(card, nameWidth);
            this->PrintCardByYearAscending(card->GetNextYear(), nameWidth);
        }
    }

    void CardDisplay::PrintCardByYearDescending(const CardNode *card, int nameWidth) {
        if (card != 0) {
            this->PrintCardByYearDescending(card->GetNextYear(), nameWidth);
            this->displayCardDataConsoleFormat(card, nameWidth);
        }

    }

    void CardDisplay::PrintCardByConditionAscending(const CardNode *card, int nameWidth) {
        if (card != 0) {
            this->displayCardDataConsoleFormat(card, nameWidth);
            this->PrintCardByConditionAscending(card->GetNextCondition(), nameWidth);
        }
    }

    void CardDisplay::PrintCardByConditionDescending(const CardNode *card, int nameWidth) {
        if (card != 0) {
            this->PrintCardByConditionDescending(card->GetNextCondition(), nameWidth);
            this->displayCardDataConsoleFormat(card, nameWidth);
        }
    }

    void CardDisplay::displayCardDataConsoleFormat(const CardNode *card, int nameWidth) {
        string value = "$" + to_string(card->GetValue()) + ".00";
        cout << setw(nameWidth + 1) << left << card->GetName() << setw(5) << left << card->GetYear() << setw(10) <<
        left << card->GetCondition() << setw(15) << right << value << endl;

    }

    void CardDisplay::PrintCardsForFileFormat(const CardNode *card) {
        if (card != 0) {
            this->displayCardDataFileFormat(card);
            this->PrintCardsForFileFormat(card->GetNextName());
        }
    }

    void CardDisplay::displayCardDataFileFormat(const CardNode *card) {
        cout << card->GetName() << "," << card->GetYear() << "," << card->GetCondition() << "," << card->GetValue() <<
        endl;
    }

    void CardDisplay::DisplayWelcome() {
        cout << "" << endl;
        cout << "Welcome to Matt Maginniss' Baseball Card Collector" << endl;
        cout << "--------------------------------------------------" << endl;
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

    void CardDisplay::DisplayMessage(const string &message) {
        cout << message << endl;
    }


}