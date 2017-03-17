//
// Created by Daniel Elsner on 17.03.17.
//

#ifndef GOLDENE_SIEBEN_CARD_COLLECTION_H
#define GOLDENE_SIEBEN_CARD_COLLECTION_H

#include "card.h"

const int kMaxLength = 40;

class CardCollection {
    Card cards_[kMaxLength];
public:
    void add_card_to_collection(Card card);

    void remove_card_from_collection(Card card);
};


#endif //GOLDENE_SIEBEN_CARD_COLLECTION_H
