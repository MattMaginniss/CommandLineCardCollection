//
// Created by Matt on 3/10/2016.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

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
        int values[] = {456245, 124, 9342, 1000, 24234, 1000000, 4240242, 12392, 429};

        for (int i = 0; i < 9; i++) {
            CardNode *card = new CardNode(names[i], years[i], conditions[i], values[i]);
            this->collection->InsertNode(card);
        }
        bool running = true;
        this->display->DisplayWelcome();
        while (running) {
            string userMenuChoice;

            this->display->DisplayMenu();
            userMenuChoice = this->getInputString();

            if (userMenuChoice.compare("1") == 0) {
                cout << "Load File!" << endl;
                string filename;

                this->display->DisplayMessage("Please enter a filename containing baseball cards.");
                cin >> filename;

                ifstream ifs(filename);
                string line;


                if (!ifs.is_open() || !ifs.good()) {
                    this->display->DisplayMessage("Input file does not exit.");
                } else {

                    while (getline(ifs, line)) {
                        stringstream lineStream(line);
                        string data;
                        vector<string> cardData;
                        while (getline(lineStream, data, ',')) {
                            cardData.push_back(data);
                        }

                        string name = cardData.at(0);
                        string year = cardData.at(1);;
                        string condition = cardData.at(2);;
                        string value = cardData.at(3);;
                        CardNode *card = new CardNode(name, stoi(year), condition, stoi(value));
                        this->collection->InsertNode(card);
                    }

                }
            } else if (userMenuChoice.compare("2") == 0) {
                this->saveCardsToFile();
            } else if (userMenuChoice.compare("3") == 0) {
                CardNode *card = this->createCard();
                this->collection->InsertNode(card);
            } else if (userMenuChoice.compare("4") == 0) {
                cout << "Delete Card!" << endl;
            } else if (userMenuChoice.compare("5") == 0) {
                this->display->DisplayMessage("Printing Cards by Name Alphabetically");
                this->display->PrintCardByNameAscending(this->collection->GetNameHead());
            } else if (userMenuChoice.compare("6") == 0) {
                this->display->DisplayMessage("Printing Cards by Name Reverse Alphabetically");
                this->display->PrintCardByNameDescending(this->collection->GetNameHead());
            } else if (userMenuChoice.compare("7") == 0) {
                this->display->DisplayMessage("Printing Cards by Year Ascending");
                this->display->PrintCardByYearAscending(this->collection->GetYearHead());
            } else if (userMenuChoice.compare("8") == 0) {
                this->display->DisplayMessage("Printing Cards by Year Descending");
                this->display->PrintCardByYearDescending(this->collection->GetYearHead());
            } else if (userMenuChoice.compare("9") == 0) {
                this->display->DisplayMessage("Printing Cards by Condition Ascending");
                this->display->PrintCardByConditionAscending(this->collection->GetConditionHead());
            } else if (userMenuChoice.compare("10") == 0) {
                this->display->DisplayMessage("Printing Cards by Condition Descending");
                this->display->PrintCardByConditionDescending(this->collection->GetConditionHead());
            } else if (userMenuChoice.compare("11") == 0) {
                cout << "Quit" << endl;
                running = false;
            } else {
                cout << "Invalid Input" << endl;
            }
        }


    }

    void CardController::saveCardsToFile() const {
        cout << "Save File!" << endl;
        string filename;

        display->DisplayMessage("Please enter a filename to save the card collection to: ");
        cin >> filename;

        ofstream out(filename);
        streambuf *coutbuf = cout.rdbuf();
        cout.rdbuf(out.rdbuf());
        display->PrintCardsForFileFormat(collection->GetNameHead());
        cout.rdbuf(coutbuf);
        out.close();
    }

    CardNode *CardController::createCard() {
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
        getline(cin, value);
        return value;
    }

    CardController::~CardController() {
        cout << "In Controller Deconstructor" << endl;
        delete (this->collection);
        delete (this->display);
        this->collection = 0;
        this->display = 0;
    }
}