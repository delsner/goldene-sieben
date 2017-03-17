//
// Created by Daniel Elsner on 17.03.17.
//

#include "card.h"
#include "card_collection.h"

void CardCollection::add_card_to_collection(Card card) {
    cards_.push_back(card);
}

void CardCollection::remove_card_from_collection(Card card) {
    for (int i = 0; i < cards_.size(); i++) {
        if (Card::equals(cards_[i], card)) {
            cards_.erase(cards_.begin() + i);
            return;
        }
    }
}

bool CardCollection::contains(Card card) {
    for (int i = 0; i < cards_.size(); i++) {
        if (Card::equals(cards_[i], card)) {
            return true;
        }
    }
    return false;
}
