//
// Created by Daniel Elsner on 17.03.17.
//
#include <iostream>
#include "card.h"

using namespace std;


Card::Card(const Color &color_, CardValue value_) : color_(color_), value_(value_) {}

const Color &Card::getColor_() {
    return color_;
}

void Card::setColor_(const Color &color_) {
    Card::color_ = color_;
}

int Card::compare(Card c1, Card c2) {
    if (CardValue::compare(c1.getValue_(), c2.getValue_()) == 1) {
        return 1;
    } else if (CardValue::compare(c1.getValue_(), c2.getValue_()) == -1) {
        return -1;
    } else {
        return 0;
    }
}

bool Card::equals(Card c1, Card c2) {
    return c1.getValue_() == c2.getValue_() && c1.getColor_() == c2.getColor_();
}

CardValue Card::getValue_() const {
    return value_;
}

void Card::setValue_(CardValue value_) {
    Card::value_ = value_;
}
