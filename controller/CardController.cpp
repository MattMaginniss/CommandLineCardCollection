//
// Created by Matt on 3/10/2016.
//

#include <iostream>
#include <fstream>

#include "CardController.h"

namespace controller {

    CardController::CardController() {
        this->collection = new CardCollection();
        this->display = new CardDisplay();
    }

    void CardController::Run() {
        int years[] = {1970, 1925, 2016, 1969, 1950, 1921, 1968, 2014, 2013};
        string names[] = {"Bobby", "Alex", "Smith", "Zander", "Jack", "Michael", "Matt", "Ryan", "Zach"};
        string conditions[] = {"Mint", "Poor", "Pristine", "Pristine", "Excellent", "Poor", "Good", "Good", "Mint"};

        for (int i = 0; i < 9; i++) {
            CardNode *card = new CardNode(names[i], years[i], conditions[i], 1000);
            this->collection->InsertNode(card);
        }
        bool running = true;
        this->display->DisplayWelcome();
        while (running) {
            int userMenuChoice;

            this->display->DisplayMenu();
            userMenuChoice = this->getInputInt();

            if (userMenuChoice == 1) {
                cout << "Load File!" << endl;
                string filename;

                this->display->DisplayMessage("Please enter a filename containing baseball cards.");
                cin >> filename;

                ifstream ifs(filename);

                if (!ifs.is_open() || !ifs.good()) {
                    this->display->DisplayMessage("Input file does not exit.");
                } else {
                    string value;
                    getline(ifs, value, ',');
                    cout << value << endl;
                }
            } else if (userMenuChoice == 2) {
                cout << "Save File!" << endl;
//                ofstream out(this->outfile);
//                streambuf *coutbuf = cout.rdbuf();
//                cout.rdbuf(out.rdbuf());
//                this->display->PrintCardByNameAscending(this->collection->GetNameHead());
//                cout.rdbuf(coutbuf);
//                out.close();
            } else if (userMenuChoice == 3) {
                CardNode* card = this->createCard();
                this->collection->InsertNode(card);
                cout << "Insert Card!" << endl;
            } else if (userMenuChoice == 4) {
                cout << "Delete Card!" << endl;
            } else if (userMenuChoice == 5) {
                this->display->PrintCardByNameAscending(this->collection->GetNameHead());
            } else if (userMenuChoice == 6) {
                this->display->PrintCardByNameDescending(this->collection->GetNameHead());
            } else if (userMenuChoice == 7) {
                this->display->PrintCardByYearAscending(this->collection->GetYearHead());
            } else if (userMenuChoice == 8) {
                this->display->PrintCardByYearDescending(this->collection->GetYearHead());
            } else if (userMenuChoice == 9) {
                this->display->PrintCardByConditionAscending(this->collection->GetConditionHead());
            } else if (userMenuChoice == 10) {
                this->display->PrintCardByConditionDescending(this->collection->GetConditionHead());
            } else if (userMenuChoice == 11) {
                cout <<"Quit" << endl;
                running = false;
            } else {
                cout << "Invalid Input" << endl;
            }
        }


    }

    CardNode* CardController::createCard() {
        string cardName;
        int cardYear;
        string cardCondition;
        int cardValue;
        display->DisplayMessage("Enter Player Name: ");
        cardName = this->getInputString();

        display->DisplayMessage("Enter Card Year: ");
        cardYear = this->getInputInt();

        display->DisplayMessage("Enter Card Condition(Pristine, Mint, Excellent, Good, Poor): ");
        cardCondition = this->getInputString();

        display->DisplayMessage("Enter Card Value: ");
        cardValue = this->getInputInt();

        CardNode *card = new CardNode(cardName, cardYear, cardCondition, cardValue);
        return card;
    }

    int CardController::getInputInt() {
        int value;
        cin >> value;
        return value;
    }

    string CardController::getInputString() {
        string value;
        ws(cin);
        getline(cin,value);
        return value;
    }

    CardController::~CardController() {
        cout << "In Controller Deconstructor" << endl;
        delete(this->collection);
        delete(this->display);
        this->collection = 0;
        this->display = 0;
    }
}