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
        bool running = true;
        this->display->DisplayWelcome();
        while (running) {
            string userMenuChoice;
            this->display->DisplayMenu();
            userMenuChoice = this->getInputString();

            if (userMenuChoice.compare("1") == 0) {
                this->loadCardsFromFile();
            } else if (userMenuChoice.compare("2") == 0) {
                this->saveCardsToFile();
            } else if (userMenuChoice.compare("3") == 0) {
                CardNode *card = this->createCard();
                this->collection->InsertNode(card);
            } else if (userMenuChoice.compare("4") == 0) {
                this->deleteCardsFromCollection();
            } else if (userMenuChoice.compare("5") == 0) {
                this->displayCardsAlphabetically();
            } else if (userMenuChoice.compare("6") == 0) {
                this->displayCardReverseAlphabetically();
            } else if (userMenuChoice.compare("7") == 0) {
                this->displayCardsByYearAscending();
            } else if (userMenuChoice.compare("8") == 0) {
                this->displayCardsByYearDescending();
            } else if (userMenuChoice.compare("9") == 0) {
                this->displayCardsByConditionAscending();
            } else if (userMenuChoice.compare("10") == 0) {
                this->displayCardsByConditionDescending();
            } else if (userMenuChoice.compare("11") == 0) {
                this->display->DisplayMessage("You have quit Matt Maginniss' Baseball Card Collector");
                running = false;
            } else {
                this->display->DisplayMessage("Invalid Input");
            }
        }
    }

    void CardController::displayCardsByConditionDescending() const {
        if (collection->GetConditionHead() == 0) {
            display->DisplayMessage("There are not currently any cards in the collector.");
        } else {
            display->DisplayMessage("Printing Cards by Condition Descending");
            display->PrintCardByConditionDescending(collection->GetConditionHead(),
                                                    this->collection->GetLargestNameLength());
        }
    }

    void CardController::displayCardsByConditionAscending() const {
        if (collection->GetConditionHead() == 0) {
            display->DisplayMessage("There are not currently any cards in the collector.");
        } else {
            display->DisplayMessage("Printing Cards by Condition Ascending");
            display->PrintCardByConditionAscending(collection->GetConditionHead(),
                                                   this->collection->GetLargestNameLength());
        }
    }

    void CardController::displayCardsByYearDescending() const {
        if (collection->GetYearHead() == 0) {
            display->DisplayMessage("There are not currently any cards in the collector.");
        } else {
            display->DisplayMessage("Printing Cards by Year Descending");
            display->PrintCardByYearDescending(collection->GetYearHead(), this->collection->GetLargestNameLength());
        }
    }

    void CardController::displayCardsByYearAscending() const {
        if (collection->GetYearHead() == 0) {
            display->DisplayMessage("There are not currently any cards in the collector.");
        } else {
            display->DisplayMessage("Printing Cards by Year Ascending");
            display->PrintCardByYearAscending(collection->GetYearHead(), this->collection->GetLargestNameLength());
        }
    }

    void CardController::displayCardReverseAlphabetically() const {
        if (collection->GetNameHead() == 0) {
            display->DisplayMessage("There are not currently any cards in the collector.");
        } else {
            display->DisplayMessage("Printing Cards by Name Reverse Alphabetically");
            display->PrintCardByNameDescending(collection->GetNameHead(), this->collection->GetLargestNameLength());
        }
    }

    void CardController::displayCardsAlphabetically() const {
        if (collection->GetNameHead() == 0) {
            display->DisplayMessage("There are not currently any cards in the collector.");
        } else {
            display->DisplayMessage("Printing Cards by Name Alphabetically");
            display->PrintCardByNameAscending(collection->GetNameHead(), this->collection->GetLargestNameLength());
        }
    }

    void CardController::deleteCardsFromCollection() {
        string cardName;
        this->display->DisplayMessage("Enter the name of the card you want to delete: ");

        cardName = this->getInputString();
        CardNode *node;

        node = this->collection->FindCardNode(cardName);

        if (node != 0) {
            while (node != 0) {
                this->collection->DeleteNode(node);
                node = this->collection->FindCardNode(cardName);
            }
        } else {
            this->display->DisplayMessage(cardName + " does not exist.");
        }
    }

    void CardController::loadCardsFromFile() const {

        string filename;
        this->display->DisplayMessage("Please enter a filename containing baseball cards.");

        cin >> filename;
        ifstream ifs(filename);
        string line;

        if (!ifs.is_open() || !ifs.good()) {
            this->display->DisplayMessage("Input file does not exit.");
        } else {
            while (getline(ifs, line)) {
                vector<string> cardData;
                cardData = parseLineToData(line);
                CardNode *card = createCardFromInput(cardData);
                this->collection->InsertNode(card);
            }
        }
    }

    CardNode *CardController::createCardFromInput(vector<string> &cardData) const {
        string name = cardData.at(0);
        string year = cardData.at(1);
        string condition = cardData.at(2);
        string value = cardData.at(3);
        CardNode *card = new CardNode(name, stoi(year), condition, stoi(value));

        return card;
    }

    vector<string> CardController::parseLineToData(const string &line) const {
        stringstream lineStream(line);
        string data;
        vector<string> cardData;
        while (getline(lineStream, data, ',')) {
            cardData.push_back(data);
        }
        return cardData;
    }

    void CardController::saveCardsToFile() const {
        string filename;

        this->display->DisplayMessage("Please enter a filename to save the card collection to: ");
        cin >> filename;
        ifstream infile(filename);
        if (infile.good()) {
            this->display->DisplayMessage(filename + " already exists and has been overwritten.");
        }
        infile.close();
        ofstream out(filename);
        streambuf *coutbuf = cout.rdbuf();
        cout.rdbuf(out.rdbuf());
        this->display->PrintCardsForFileFormat(collection->GetNameHead());
        cout.rdbuf(coutbuf);
        out.close();
    }

    CardNode *CardController::createCard() {
        string cardName;
        int cardYear;
        string cardCondition;
        int cardValue;

        this->display->DisplayMessage("Enter Player Name: ");
        cardName = this->getInputString();

        this->display->DisplayMessage("Enter Card Year: ");
        cardYear = this->getInputInt();

        this->display->DisplayMessage("Enter Card Condition(Pristine, Mint, Excellent, Good, Poor): ");
        cardCondition = this->getInputString();


        this->display->DisplayMessage("Enter Card Value: ");
        cardValue = this->getInputInt();

        CardNode *card;
        card = this->checkForCardInputValidity(cardName, cardYear, cardCondition, cardValue);


        return card;
    }

    CardNode *CardController::checkForCardInputValidity(const string &cardName, int cardYear, string &cardCondition,
                                                        int cardValue) {
        CardNode *card;
        bool valid = false;
        while (!valid) {
            try {
                card = new CardNode(cardName, cardYear, cardCondition, cardValue);
                valid = true;
            } catch (string errorCode) {
                if (errorCode.compare("Invalid Year") == 0) {
                    this->display->DisplayMessage("Card year is invalid. Must be after 1860.");
                    this->display->DisplayMessage("Please enter the card year: ");
                    cardYear = this->getInputInt();
                }
                if (errorCode.compare("Invalid Condition") == 0) {
                    display->DisplayMessage(cardCondition + " is an invalid Condition.");
                    display->DisplayMessage("Enter Card Condition(Pristine, Mint, Excellent, Good, Poor): ");
                    cardCondition = this->getInputString();
                }
                if (errorCode.compare("Invalid Value") == 0) {
                    display->DisplayMessage("Card Value is not valid. Must be a number greater than 0.");
                    display->DisplayMessage("Please enter the card value: ");
                    cardValue = this->getInputInt();
                }
            }
        }
        return card;
    }

    int CardController::getInputInt() {
        string input;
        cin >> input;
        int value;
        try {
            value = stoi(input);
        } catch (...) {
            value = -1;
        }
        return value;
    }

    string CardController::getInputString() {
        string value;
        ws(cin);
        getline(cin, value);
        return value;
    }

    CardController::~CardController() {
        delete (this->collection);
        delete (this->display);
        this->collection = 0;
        this->display = 0;
    }
}