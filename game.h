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
    std::vector<Player> players_;

    // shuffle cards
    void shuffle_cards_();

    // deal cards
    void deal_cards_();

    // play round
    void play_round_(Player &player);

    // evaluation of round
    void evaluate_round_();

    // create players
    void create_players_(int amount);

    // create gaming card deck
    void create_card_deck_();

public:
    // start new game
    void start();

    // reset game
    void reset();
};


#endif //GOLDENE_SIEBEN_GAME_H
