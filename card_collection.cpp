
//
// Created by Daniel Elsner on 17.03.17.
//

#include <iostream>
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
        if (cards_[i].getValue_().getValue_() > value.getValue_()) {
            sum++;
        }
    }
    return sum;
}

int CardCollection::amount_of_color(Color color) {
    int sum = 0;
    for (int i = 0; i < cards_.size(); i++) {
        if (cards_[i].getColor_() == color) {
            sum++;
        }
    }
    return sum;
}

void CardCollection::print_all_cards() {
    for (int i = 0; i < cards_.size(); i++) {
        cout << "Karte an Index " << i << ": " << cards_[i].getColor_() << cards_[i].getValue_() << endl;
    }
}

int get_random_number_(int i) {
    return std::rand() % i;
}

void CardCollection::shuffle_cards() {
    std::random_shuffle(cards_.begin(), cards_.end(), get_random_number_);
}

std::vector<Card> CardCollection::get_first_cards(int amount) {

    // erstelle subvektor der zurückgegeben
    std::vector<Card> subvector;
    copy(cards_.begin(), cards_.begin() + amount, std::back_inserter(subvector));

    // reduce vector
    cards_.erase(cards_.begin(), cards_.begin() + amount);

    return subvector;
}

vector<Card> CardCollection::getCards_() {
    return cards_;
}
