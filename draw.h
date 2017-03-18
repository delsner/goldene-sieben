//
// Created by Daniel Elsner on 17.03.17.
//

#ifndef GOLDENE_SIEBEN_ZUG_H
#define GOLDENE_SIEBEN_ZUG_H

#include <iostream>
#include <vector>
#include "card.h"

class Draw {
public:
    Draw(const Card &card_played, const vector<Card> &cards_taken);

    Card card_played;
    std::vector<Card> cards_taken;
};


#endif //GOLDENE_SIEBEN_ZUG_H
