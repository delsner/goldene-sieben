//
// Created by Daniel Elsner on 17.03.17.
//

#include <iostream>
#include "player.h"
#include "game.h"

using namespace std;

void Game::shuffle_cards_() {

}

void Game::deal_cards_() {

}

void Game::play_round_(Player &player) {

}

void Game::evaluate_round_() {

}

void Game::create_players_(int amount) {
    // default amount of players is 2
    if (amount < 2 || amount > 3) {
        amount = 2;
    }

    // create players
    for (int i = 0; i < amount; i++) {
        players_.push_back(Player());
    }
}

void Game::create_card_deck_() {
    /*for (Color color = Color::KARO; color != Color::KREUZ; color++) {
        for (CardValue value = CardValue::ASS; value != CardValue::KOENIG; value++) {
            cout << "Creating new card, color: " << color << ", value: " << value << endl;
            rest_stack_.add_card_to_collection(Card(color, value));
        }
    }*/
}

void Game::start() {
    cout << "Starting new Game of Goldene 7" << endl;

    // create 2-3 players
    create_players_(2);

    // create card deck
    create_card_deck_();

    // shuffle

    // deal

    // loop
    // play round

    // evaluate round

    // reset
}

void Game::reset() {

}
