//
// Created by Daniel Elsner on 17.03.17.
//
#include <iostream>
#include "card.h"

using namespace std;

Card::Card(const Color &color_, int value_) {
    cout << "Create new card." << endl;
    Card::color_ = color_;
    Card::value_ = value_;
}

int Card::getValue_() {
    return value_;
}

void Card::setValue_(int value_) {
    Card::value_ = value_;
}

const Color &Card::getColor_() {
    return color_;
}

void Card::setColor_(const Color &color_) {
    Card::color_ = color_;
}

int Card::compare(Card c1, Card c2) {
    if (c1.value_ > c2.value_) {
        return 1;
    } else if (c1.value_ < c2.value_) {
        return -1;
    } else {
        return 0;
    }
}

bool Card::equals(Card c1, Card c2) {
    return c1.getValue_() == c2.getValue_() && c1.color_ == c2.color_;
}
