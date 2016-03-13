//
// Created by Matt on 3/10/2016.
//

#ifndef CARDINTERLACER_CARDNODE_H
#define CARDINTERLACER_CARDNODE_H

#include <string>

using namespace std;

namespace model {
    class CardNode {
    private:
        string name;
        int year;
        string condition;
        float value;


    public:
        CardNode *nextName;
        CardNode *nextYear;
        CardNode *nextCondition;

        CardNode(string name, int year, string condition, float value);

        string GetName() const;

        int GetYear() const;

        string GetCondition() const;

        float GetValue() const;

        void SetNextName(CardNode *nextName);

        void SetNextYear(CardNode *nextYear);

        void SetNextCondition(CardNode *nextCondition);
    };
}

#endif //CARDINTERLACER_CARDNODE_H
