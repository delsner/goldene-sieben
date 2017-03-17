//
// Created by Daniel Elsner on 17.03.17.
//

#ifndef GOLDENE_SIEBEN_CARD_COLLECTION_H
#define GOLDENE_SIEBEN_CARD_COLLECTION_H

#include <iostream>
#include <vector>
#include "card.h"

class CardCollection {
    std::vector<Card> cards_;
public:
    void add_card_to_collection(Card card);

    void remove_card_from_collection(Card card);

    bool contains(Card card);
};


#endif //GOLDENE_SIEBEN_CARD_COLLECTION_H
