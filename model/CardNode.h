//
// Created by Matt on 3/10/2016.
//

#ifndef CARDINTERLACER_CARDNODE_H
#define CARDINTERLACER_CARDNODE_H

#include <string>
#include <iostream>

using namespace std;
enum Condition {
    Poor,
    Good,
    Excellent,
    Mint,
    Pristine
};

inline std::ostream &operator<<(std::ostream &os, const Condition &enumCondition) {
    switch (enumCondition) {
        case Poor:
            os << "Poor";
            break;
        case Good:
            os << "Good";
            break;
        case Excellent:
            os << "Excellent";
            break;
        case Mint:
            os << "Mint";
            break;
        case Pristine:
            os << "Pristine";
            break;
    }
    return os;
}

namespace model {
    class CardNode {
    private:
        string name;
        int year;
        Condition condition;
        int value;
        CardNode *nextName;
        CardNode *nextYear;
        CardNode *nextCondition;

        void setCondition(const string &condition);

        string convertToLower(const string &toBeConverted) const;

    public:

        // Constructor for a CardNode object.
        // @param name the name of the card node object.
        // @param year the year of the card node object.
        // @param condition the condition of the card node object.
        // @param value the value of the card node object.
        CardNode(string name, int year, string condition, int value);

        // Deconstructor for CardNode object.
        virtual ~CardNode();

        // Getter for the name of the card.
        string GetName() const;

        // Getter for the year of the card.
        int GetYear() const;

        // Getter for the condition of the card.
        Condition GetCondition() const;

        // Getter for the value of the card.
        int GetValue() const;

        // Getter for the next name card object.
        CardNode *GetNextName() const;

        // Getter for the next year card object.
        CardNode *GetNextYear() const;

        // Getter for the next condition card object.
        CardNode *GetNextCondition() const;

        // Setter for the next name card object.
        // @param *nextName the card object to be set as the next name.
        void SetNextName(CardNode *nextName);

        // Setter for the next year card object.
        // @param *nextYear the card object to be set as the next year.
        void SetNextYear(CardNode *nextYear);

        // Setter for the next condition card object.
        // @param *nextCondition the card object to be set as the next condition.
        void SetNextCondition(CardNode *nextCondition);

    };
}

#endif //CARDINTERLACER_CARDNODE_H
