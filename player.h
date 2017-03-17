//
// Created by Daniel Elsner on 17.03.17.
//

#ifndef GOLDENE_SIEBEN_PLAYER_H
#define GOLDENE_SIEBEN_PLAYER_H

#include "card.h"
#include "card_collection.h"
#include "draw.h"

using namespace std;

class Player {
    // Handkarten
    CardCollection inventory_;

    // Stiche
    CardCollection stack_;

    // Extra-Punkte
    int extra_points_;
public:
    // Handkarten spielen oder erhalten
    void add_cards_to_inventory(Card cards[]);

    void remove_cards_from_inventory(Card cards[]);

    // Stiche
    void add_cards_to_stack(Card cards[]); // for(i in cards){ stack_.add_card_to_collection(cards[i]); }

    // Extrapunkte erhöhen
    void increment_extra_points();

    // Handkarten, Stiche und Extrapunkte reset
    void reset();

    // Anfrage an Spieler eine Karte zu spielen
    Draw request();

    // Rechne Stiche zusammen
    int count_score();

};


#endif //GOLDENE_SIEBEN_PLAYER_H
