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

    // Extra-Punkte für Pool geleert
    int pool_cleared_;

public:
    // Initialisiere Extrapoints auf 0
    Player();

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

    // Rechne Karten zusammen
    int count_cards();

    // Rechne Bilder zusammen
    int count_pictures();

    // Rechne Karos zusammen
    int count_karo();

    // Hole Extrapunkte
    int getExtra_points_();

    // Print Inventory
    void print_inventory();

    // Print Stack
    void print_stack();


};


#endif //GOLDENE_SIEBEN_PLAYER_H
