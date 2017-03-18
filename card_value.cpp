//
// Created by Jan on 17.03.2017.
//

#include <iostream>
#include "card_value.h"

using namespace std;

CardValue::CardValue(int value_, const string &name_) : value_(value_), name_(name_) {}

CardValue CardValue::ASS = CardValue(1, "ASS");
CardValue CardValue::ZWEI = CardValue(2, "ZWEI");
CardValue CardValue::DREI = CardValue(3, "DREI");
CardValue CardValue::VIER = CardValue(4, "VIER");
CardValue CardValue::FUENF = CardValue(5, "FUENF");
CardValue CardValue::SECHS = CardValue(6, "SECHS");
CardValue CardValue::SIEBEN = CardValue(7, "SIEBEN");
CardValue CardValue::BUBE = CardValue(8, "BUBE");
CardValue CardValue::DAME = CardValue(9, "DAME");
CardValue CardValue::KOENIG = CardValue(10, "KOENIG");

int CardValue::compare(CardValue c1, CardValue c2) {
    if (c1.value_ > c2.value_) {
        return 1;
    } else if (c1.value_ < c2.value_) {
        return -1;
    } else {
        return 0;
    }
}

int CardValue::getValue_() const {
    return value_;
}

const string &CardValue::getName_() const {
    return name_;
}

bool CardValue::operator==(const CardValue &rhs) const {
    return value_ == rhs.value_;
}

bool CardValue::operator!=(const CardValue &rhs) const {
    return value_ != rhs.value_;
}

ostream &operator<<(ostream &os, const CardValue &value) {
    os << value.name_ << " ";
    return os;
}
