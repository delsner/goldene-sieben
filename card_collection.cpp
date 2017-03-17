
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

int CardCollection::length() {
    return cards_.size();
}

// Zum Zählen der Buben, Damen, Könige
int CardCollection::amount_larger_than_number(CardValue value) {
    int sum = 0;
    for (int i = 0; i < cards_.size(); i++) {
        if (cards_[i].getValue_() > value) { sum++;}
    }
    return sum;
}

int CardCollection::amount_of_color(Color color) {
    int sum = 0;
    for (int i = 0; i < cards_.size(); i++) {
        if (cards_[i].getColor_() == color) { sum++;}
    }
    return sum;
}
