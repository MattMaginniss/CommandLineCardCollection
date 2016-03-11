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

        CardNode *nextName;
        CardNode *nextYear;
        CardNode *nextCondition;


    public:
        CardNode(string name, int year, string condition, float value);
    };
}

#endif //CARDINTERLACER_CARDNODE_H
