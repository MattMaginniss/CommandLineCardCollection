//
// Created by Matt on 3/10/2016.
//

#ifndef CARDINTERLACER_CARDCONTROLLER_H
#define CARDINTERLACER_CARDCONTROLLER_H

#include "CardCollection.h"
#include "CardNode.h"

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

        string convertToLower(const string &string) const;

    public:
        CardController();

        virtual ~CardController();

        void Run();

        void loadCardsFromFile() const;

    };

}


#endif //CARDINTERLACER_CARDCONTROLLER_H
