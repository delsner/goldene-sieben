//
// Created by Daniel Elsner on 17.03.17.
//

#ifndef GOLDENE_SIEBEN_GAME_H
#define GOLDENE_SIEBEN_GAME_H


#include "card_collection.h"
#include "player.h"

class Game {
    // Pool (Karten in der Mitte)
    CardCollection pool_;

    // Stapel unausgeteilter Karten
    CardCollection rest_stack_;

    // Mitspieler
    Player players_[];
public:
    // start new game
    void start();

    // reset game
    void reset();

    // shuffle cards
    void shuffle_cards();

    // deal cards
    void deal_cards();

    // play round
    void play_round(Player &player);

    // evaluation of round
    void evaluate_round();
};


#endif //GOLDENE_SIEBEN_GAME_H
