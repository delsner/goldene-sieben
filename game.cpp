//
// Created by Daniel Elsner on 17.03.17.
//

#include <iostream>
#include "player.h"
#include "game.h"

using namespace std;

void Game::shuffle_cards_() {
    rest_stack_.shuffle_cards();
}

// returns true if game is to be continued because the stack still isn
void Game::deal_cards_() {
    if (players_.size() == 2) {
        if (rest_stack_.length() == 40) {
            // first round of dealing
            // get first 9 cards and reduce rest_stack by 9
            for (int i = 0; i < players_.size(); i++) {
                players_[i].add_cards_to_inventory(rest_stack_.get_first_cards(9));
            }
            // 4 in pool
            std::vector<Card> pool_cards = rest_stack_.get_first_cards(4);
            for (int i = 0; i < pool_cards.size(); i++) {
                pool_.add_card_to_collection(pool_cards[i]);
            }
        } else if (rest_stack_.length() == 18) {
            // second round of dealing
            // get next 6 cards and reduce rest_stack by 6
            for (int i = 0; i < players_.size(); i++) {
                players_[i].add_cards_to_inventory(rest_stack_.get_first_cards(6));
            }
        } else if (rest_stack_.length() == 6) {
            // third round of dealing
            // get next 3 cards and reduce rest_stack by 3
            for (int i = 0; i < players_.size(); i++) {
                players_[i].add_cards_to_inventory(rest_stack_.get_first_cards(3));
            }
        } else {
            // all done
        }
    } else {
        // TODO: implement game for 3 players
    }
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
    std::vector<Color> all_colors = {Color::KARO, Color::HERZ, Color::PIK, Color::KREUZ};
    std::vector<CardValue> all_values = {CardValue::ASS, CardValue::ZWEI, CardValue::DREI, CardValue::VIER,
                                         CardValue::FUENF, CardValue::SECHS, CardValue::SIEBEN, CardValue::BUBE,
                                         CardValue::DAME, CardValue::KOENIG};
    for (int i = 0; i < all_colors.size(); i++) {
        for (int j = 0; j < all_values.size(); j++) {
            rest_stack_.add_card_to_collection(Card(all_colors[i], all_values[i]));
        }
    }
}

void Game::start() {
    cout << "Starting new Game of Goldene 7" << endl;

    // create 2-3 players
    create_players_(2);

    // create card deck
    create_card_deck_();

    // shuffle
    shuffle_cards_();

    // loop
    // play round
    while (rest_stack_.length() != 0) {
        // deal cards
        deal_cards_();

        // while still inventory > 0 keep requesting rounds
        while (players_[0].getInventory_().length() > 0) {
            // play round
            for (int p = 0; p < players_.size(); p++) {
                play_round_(players_[p]);
            }
        }

        // give last player that got a stich everything that is left !
        // && pool_.length() != 0
    }

    // evaluate round - prints which player has won the game and their scores

    // reset
}

void Game::reset() {

}
