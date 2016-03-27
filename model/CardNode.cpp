//
// Created by Matt on 3/10/2016.
//

#include "CardNode.h"
#include <algorithm>

namespace model {


    CardNode::CardNode(string name, int year, string condition, int value) {
        if (year < 1960) {
            throw string("Invalid Year");
        }
        if (value <= 0) {
            throw string("Invalid Value");
        }
        this->name = name;
        this->year = year;
        this->setCondition(condition);
        this->value = value;
        this->nextName = 0;
        this->nextYear = 0;
        this->nextCondition = 0;
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        this->lowerName = name;
    }

    void CardNode::setCondition(const string &condition) {
        string value = condition;
        transform(value.begin(), value.end(), value.begin(), ::tolower);

        if (value.compare("poor") == 0) {
            CardNode::condition = Poor;
        } else if (value.compare("good") == 0) {
            CardNode::condition = Good;
        } else if (value.compare("excellent") == 0) {
            CardNode::condition = Excellent;
        } else if (value.compare("mint") == 0) {
            CardNode::condition = Mint;
        } else if (value.compare("pristine") == 0) {
            CardNode::condition = Pristine;
        } else {
            throw string("Invalid Condition");
        }
    }


    int CardNode::GetYear() const {
        return this->year;
    }

    void CardNode::SetNextName(CardNode *nextName) {
        this->nextName = nextName;
    }

    void CardNode::SetNextYear(CardNode *nextYear) {
        this->nextYear = nextYear;
    }

    void CardNode::SetNextCondition(CardNode *nextCondition) {
        this->nextCondition = nextCondition;
    }

    string CardNode::GetName() const {
        return this->name;
    }

    Condition CardNode::GetCondition() const {
        return this->condition;
    }

    int CardNode::GetValue() const {
        return this->value;
    }

    CardNode::~CardNode() {
        this->nextName = 0;
        this->nextYear = 0;
        this->nextCondition = 0;

    }

    CardNode *CardNode::GetNextName() const {
        return this->nextName;
    }

    CardNode *CardNode::GetNextYear() const {
        return this->nextYear;
    }

    CardNode *CardNode::GetNextCondition() const {
        return this->nextCondition;
    }

    string CardNode::GetLowerName() {
        return this->lowerName;
    }
}