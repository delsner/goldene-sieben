//
// Created by Daniel Elsner on 17.03.17.
//

#ifndef GOLDENE_SIEBEN_CARD_H
#define GOLDENE_SIEBEN_CARD_H

#include <iostream>
#include "color.h"

using namespace std;

class Card {
    Color color_;
    int value_;
public:
    Card(const Color &color_, int value_);

    const Color &getColor_();

    void setColor_(const Color &color_);

    int getValue_();

    void setValue_(int value_);

    // compare method (1 first higher, 0 equal, -1 second higher)
    static int compare(Card c1, Card c2);
};

#endif //GOLDENE_SIEBEN_CARD_H
