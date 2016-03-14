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

inline std::ostream& operator<<( std::ostream& os, const Condition& enumCondition )
{
    switch( enumCondition )
    {
        case Poor: os << "Poor"; break;
        case Good: os << "Good"; break;
        case Excellent: os << "Excellent"; break;
        case Mint: os << "Mint"; break;
        case Pristine: os << "Pristine"; break;
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

        void setCondition(const string &condition);

    public:
        CardNode *nextName;
        CardNode *nextYear;
        CardNode *nextCondition;

        CardNode(string name, int year, string condition, int value);

        string GetName() const;

        int GetYear() const;

        Condition GetCondition() const;

        int GetValue() const;

        void SetNextName(CardNode *nextName);

        void SetNextYear(CardNode *nextYear);

        void SetNextCondition(CardNode *nextCondition);

    };
}

#endif //CARDINTERLACER_CARDNODE_H
