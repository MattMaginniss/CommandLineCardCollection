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
        this->nextName = _NULL;
        this->nextYear = _NULL;
        this->nextCondition = _NULL;
    }

    void CardNode::setCondition(const string &condition) {
        if (condition.compare("Poor") == 0) {
            CardNode::condition = Poor;
        } else if (condition.compare("Good") == 0) {
            CardNode::condition = Good;
        } else if (condition.compare("Excellent") == 0) {
            CardNode::condition = Excellent;
        } else if (condition.compare("Mint") == 0) {
            CardNode::condition = Mint;
        } else if (condition.compare("Pristine") == 0) {
            CardNode::condition = Pristine;
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

}