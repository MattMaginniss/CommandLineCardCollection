//
// Created by Matt on 3/10/2016.
//

#include "CardNode.h"


namespace model {


    CardNode::CardNode(string name, int year, string condition, float value) {
        this->name = name;
        this->year = year;
        this->condition = condition;
        this->value = value;
        this->nextName = _NULL;
        this->nextYear = _NULL;
        this->nextCondition = _NULL;
    }


    int CardNode::GetYear()const {
        return this->year;
    }

    void CardNode::SetNextYear(CardNode *nextYear) {
        this->nextYear = nextYear;
    }

    string CardNode::GetName() const {
        return this->name;
    }

    string CardNode::GetCondition() const {
        return this->condition;
    }

    float CardNode::GetValue() const {
        return this->value;
    }
}