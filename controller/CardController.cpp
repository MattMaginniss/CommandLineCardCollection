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
                this->display->DisplayMessage("You have quit Matt Maginniss' Baseball Card Collector");
                running = false;
            } else {
                this->display->DisplayMessage("Invalid Input");
            }
        }
    }

    void CardController::deleteCardsFromCollection() {
        this->display->DisplayMessage("Delete Card!");
        string cardName;
        this->display->DisplayMessage("Enter the name of the card you want to delete: ");

        cardName = this->getInputString();
        CardNode *node;

        node = this->collection->FindCardNode(cardName);

        if (node != 0) {
            while (node != 0) {
                this->collection->DeleteNode(node);
                delete (node);
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
        string year = cardData.at(1);;
        string condition = cardData.at(2);;
        string value = cardData.at(3);;
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
        cout << "Save File!" << endl;
        string filename;

        this->display->DisplayMessage("Please enter a filename to save the card collection to: ");
        cin >> filename;

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