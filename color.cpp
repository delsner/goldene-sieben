//
// Created by Daniel Elsner on 17.03.17.
//

#include <iostream>
#include "color.h"

using namespace std;

Color::Color(int value_, const string &name_) : value_(value_), name_(name_) {}

Color Color::KARO = Color(1, "KARO");
Color Color::HERZ = Color(2, "HERZ");
Color Color::PIK = Color(3, "PIK");
Color Color::KREUZ = Color(4, "KREUZ");

int Color::compare(Color c1, Color c2) {
    if (c1.value_ > c2.value_) {
        return 1;
    } else if (c1.value_ < c2.value_) {
        return -1;
    } else {
        return 0;
    }
}

int Color::getValue_() const {
    return value_;
}

const string &Color::getName_() const {
    return name_;
}

bool Color::operator==(const Color &rhs) const {
    return value_ == rhs.value_;
}

bool Color::operator!=(const Color &rhs) const {
    return value_ != rhs.value_;
}

ostream &operator<<(ostream &os, const Color &color) {
    os << color.name_ << " ";
    return os;
}
