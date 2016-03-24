//
// Created by Matt on 3/10/2016.
//

#include "CardNode.h"


namespace model {


    CardNode::CardNode(string name, int year, string condition, int value) {
        this->name = name;
        this->year = year;
        this->setCondition(condition);
        this->value = value;
        this->nextName = 0;
        this->nextYear = 0;
        this->nextCondition = 0;
    }

    void CardNode::setCondition(const string &condition) {
        string value = convertToLower(condition);

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
            throw 0;
        }
    }

    string CardNode::convertToLower(const string &condition) const {
        locale loc;
        string value = condition;
        for (basic_string::size_type i = 0; i < value.length(); ++i)
            value[i] = tolower(value[i], loc);

        value;
        return value;
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
        cout << "Deleting: " << this->name << " " << this->year << " " << this->condition << " " << this->value << endl;
        this->nextName = 0;
        this->nextYear = 0;
        this->nextCondition = 0;

    }
}