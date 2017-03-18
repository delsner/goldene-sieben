//
// Created by Jan on 18.03.2017.
//

#include "draw.h"
#include "card_collection.h"
#include "ruleset.h"
#include <iostream>

using namespace std;

int main() {

    CardCollection inventory;
    Card card1(Color::HERZ, CardValue::KOENIG);
    Card card2(Color::KARO, CardValue::FUENF);

    inventory.add_card_to_collection(card1);

    CardCollection pool;
    Card card3(Color::PIK, CardValue::ZWEI);
    Card card4(Color::KREUZ, CardValue::ASS);
    Card card5(Color::KARO, CardValue::SIEBEN);

    std::vector<Card> cards = {card3, card4, card5};
    for (int i = 0; i < cards.size(); i++) {
        pool.add_card_to_collection(cards[i]);
    }

    std::vector<Card> cards_taken = {Card(Color::KARO, CardValue::SIEBEN), Card(Color::KREUZ, CardValue::ASS),
                                     Card(Color::PIK, CardValue::ZWEI)};
    Draw draw1(Card(Color::HERZ, CardValue::KOENIG),cards_taken);


    cout << Ruleset::validate(draw1, pool, inventory) << endl;
}