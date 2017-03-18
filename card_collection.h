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
    vector <Card> getCards_();

    void add_card_to_collection(Card card);

    void remove_card_from_collection(Card card);

    int length();

    int amount_larger_than_number(CardValue value);

    int amount_of_color(Color color);

    bool contains(Card card);

    // Für die Ausgabe der Karten in Konsole
    void print_all_cards();

    void shuffle_cards();

    std::vector<Card> get_first_cards(int amount);
};


#endif //GOLDENE_SIEBEN_CARD_COLLECTION_H
