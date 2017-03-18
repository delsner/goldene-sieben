//
// Created by Daniel Elsner on 17.03.17.
//

#include <iostream>
#include "player.h"
#include "game.h"
#include "ruleset.h"

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
            // all done last player who won a trick gets rest of pool and remove from pool
            last_trick_taken_.add_cards_to_stack(pool_.get_first_cards(pool_.length())); // TODO: be aware of indices (get_first_cards amount - 1 ?)
        }
    } else {
        // TODO: implement game for 3 players
    }
}

void Game::play_round_(Player &player) {
    Draw d = player.request();
    while (!Ruleset::validate(d, pool_, player.getInventory_())) {
        cout << "requesting again" << endl;
        d = player.request();
    }
    play_draw_(d, player);

}

void Game::play_draw_(Draw d, Player &player) {
    // entferne karten aus pool
    for (int i = 0; i < d.cards_taken.size(); i++) {
        pool_.remove_card_from_collection(d.cards_taken[i]);
    }

    // speichere den Spieler der als letztes Karten aus dem Pool genommen hat
    if (d.cards_taken > 0) {
        last_trick_taken_ = player;
    }

    // nehme karten aus pool + selbst gespielte karte und lege sie in eigenen Stich-stapel
    std::vector<Card> cards_to_stack = d.cards_taken; //speichere karten aus pool
    cards_to_stack.push_back(d.card_played); // fuege dem vector gespielte karte hinzu
    player.add_cards_to_stack(cards_to_stack); // fuege den gesamten vector auf Stich-stapel hinzu

    // entferne gespielte Karte aus Hand
    std::vector<Card> cards_from_inventory = {d.card_played};
    player.remove_cards_from_inventory(cards_from_inventory);
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
    while (rest_stack_.length() != 0 && pool_.length() != 0) {
        // deal cards
        deal_cards_();

        // while still inventory > 0 keep requesting rounds
        while (players_[0].getInventory_().length() > 0) {
            // play round
            for (int p = 0; p < players_.size(); p++) {
                play_round_(players_[p]);
            }
        }
    }

    // evaluate round - prints which player has won the game and their scores

    // reset
}

void Game::reset() {

}
