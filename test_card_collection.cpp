//
// Created by Daniel Elsner on 17.03.17.
//

#include <iostream>
#include "card.h"
#include "card_collection.h"

using namespace std;

int main() {
    Card card1(Color::HERZ, 2);
    Card card2(Color::KARO, 3);
    Card card3(Color::KREUZ, 4);

    CardCollection cards;
    cards.add_card_to_collection(card1);
    cards.add_card_to_collection(card2);
    cards.add_card_to_collection(card3);

    cards.remove_card_from_collection(card2);

    cout << "card2 in cards: " << cards.contains(card2) << endl;
    cout << "card1 in cards: " << cards.contains(card1) << endl;

    return 0;
}