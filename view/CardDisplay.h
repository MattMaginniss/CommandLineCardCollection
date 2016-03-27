//
// Created by Matt on 3/10/2016.
//

#ifndef CARDINTERLACER_CARDDISPLAY_H
#define CARDINTERLACER_CARDDISPLAY_H

#include "CardNode.h"

using namespace model;

namespace view {
    class CardDisplay {
    private:
        void displayCardDataFileFormat(const CardNode *card);

        void displayCardDataConsoleFormat(const CardNode *card, int nameWidth);

    public:
        // This will recursively print out all cards by their name in
        // alphabetical order formatted for the console.
        // @param *card the card to have its details printed to the console.
        void PrintCardByNameAscending(const CardNode *card, int nameWidth);

        // This will recursively print out all cards by their year in
        // ascending order formatted for the console.
        // @param *card the card to have its details printed to the console.
        void PrintCardByYearAscending(const CardNode *card, int nameWidth);

        // This will recursively print out all cards by their condition in
        // ascending order formatted for the console.
        // @param *card the card to have its details printed to the console.
        void PrintCardByConditionAscending(const CardNode *card, int nameWidth);

        // This will recursively print out all cards by their name in
        // reverse alphabetical order formatted for the console.
        // @param *card the card to have its details printed to the console.
        void PrintCardByNameDescending(const CardNode *card, int nameWidth);

        // This will recursively print out all cards by their year in
        // descending order formatted for the console.
        // @param *card the card to have its details printed to the console.
        void PrintCardByYearDescending(const CardNode *card, int nameWidth);

        // This will recursively print out all cards by their condition in
        // descending order formatted for the console.
        // @param *card the card to have its details printed to the console.
        void PrintCardByConditionDescending(const CardNode *card, int nameWidth);

        // This will recursively print out all cards by their name in
        // alphabetical order formatted specifically for an output file.
        // @param *card the card to have its details printed to the file.
        void PrintCardsForFileFormat(const CardNode *card);

        // This will display the menu to the console to instruct them how
        // to interact with the program
        void DisplayMenu();

        // This will display the message passed in to the console.
        // @param message the message to be displayed.
        void DisplayMessage(const string &message);

        // This will display the introduction to the program to the console.
        void DisplayWelcome();
    };

}


#endif //CARDINTERLACER_CARDDISPLAY_H
