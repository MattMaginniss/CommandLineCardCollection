//
// Created by Matt on 3/10/2016.
//

#ifndef CARDINTERLACER_CARDCONTROLLER_H
#define CARDINTERLACER_CARDCONTROLLER_H

#include "CardCollection.h"
#include "CardNode.h"
#include <vector>

using namespace model;

#include "CardDisplay.h"

using namespace view;


namespace controller {
    class CardController {
    private:
        CardCollection *collection;

        CardDisplay *display;

        string getInputString();

        int getInputInt();

        CardNode *createCard();

        void saveCardsToFile() const;

        vector<string> parseLineToData(const string &line) const;

        CardNode *createCardFromInput(vector<string> &cardData) const;

        void loadCardsFromFile() const;

        void deleteCardsFromCollection();

        void displayCardsAlphabetically() const;

        void displayCardReverseAlphabetically() const;

        void displayCardsByYearAscending() const;

        void displayCardsByYearDescending() const;

        void displayCardsByConditionAscending() const;

        void displayCardsByConditionDescending() const;

        CardNode *checkForCardInputValidity(const string &cardName, int cardYear, string &cardCondition, int cardValue);


    public:
        // Constructor for a CardController object.
        CardController();

        // Destructor for a CardController object.
        virtual ~CardController();

        // This method is primary running loop of the program.
        void Run();

    };

}


#endif //CARDINTERLACER_CARDCONTROLLER_H
