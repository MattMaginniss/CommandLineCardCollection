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

        CardNode* createCard();

        void saveCardsToFile() const;
    public:
        CardController();
        virtual ~CardController();

        void Run();

    };

}


#endif //CARDINTERLACER_CARDCONTROLLER_H
