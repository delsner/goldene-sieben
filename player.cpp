//
// Created by Daniel Elsner on 17.03.17.
//

#include <iostream>
#include <sstream>
#include "card.h"
#include "draw.h"
#include "player.h"

using namespace std;

Player::Player() {
    pool_cleared_ = 0;
    score_ = 0;
}

void Player::add_cards_to_inventory(std::vector<Card> cards) {
    for (int i = 0; i < cards.size(); i++) {
        inventory_.add_card_to_collection(cards[i]);
    }
}

void Player::remove_cards_from_inventory(std::vector<Card> cards) {
    for (int i = 0; i < cards.size(); i++) {
        inventory_.remove_card_from_collection(cards[i]);
    }
}

void Player::add_cards_to_stack(std::vector<Card> cards) {
    for (int i = 0; i < cards.size(); i++) {
        stack_.add_card_to_collection(cards[i]);
    }
}

void Player::increment_extra_points() {
    pool_cleared_++;
}

void Player::add_amount_to_score(int amount) {
    score_ += amount;
}

void Player::reset() {
    // Reset Extrapoints, stack and inventory for new game
    pool_cleared_ = 0;

    inventory_ = *(new CardCollection);
    stack_ = *(new CardCollection);
}

Draw Player::request(CardCollection pool) {
    cout << "Karten auf der Hand: " << endl;
    print_inventory();
    cout << "Karten im Pool: " << endl;
    pool.print_all_cards();

    Card card_played = inventory_.getCards_()[request_card_played(
            inventory_.length() - 1)]; // länge 5 -> index -> höchstens 4
    std::vector<int> cards_taken_indices = request_cards_taken(pool.length() - 1);
    std::vector<Card> cards_taken = {};

    // doppelte löschen
    std::sort(cards_taken_indices.begin(), cards_taken_indices.end());
    auto last = std::unique(cards_taken_indices.begin(), cards_taken_indices.end());
    cards_taken_indices.erase(last, cards_taken_indices.end());

    for (int i : cards_taken_indices) { // für alle i in cards_taken_indices
        cards_taken.push_back(pool.getCards_()[i]);
    }

    return Draw(card_played, cards_taken);
}

int Player::request_card_played(int max_index) {
    int input_var;
    cout << "Welche Handkarte möchtest du spielen (index): ";

    while (true) {
        if (!(cin >> input_var) || !(input_var <= max_index && input_var >= 0)) {
            cout << "Bitte eine gültige Zahl eingeben: ";
            input_var = -1;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        break;
    }

    cout << "Gewählter index: " << input_var << endl;

    return input_var;
}

std::vector<int> Player::request_cards_taken(int max_index) {
    vector<int> cards_taken = {};
    int input_var;
    char choice;
    bool run = true;

    while (run) {
        cout << "Willst du eine weitere Karte aus dem Pool nehmen? (Y/N): ";
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            cout << "Welche Poolkarte möchtest du nehmen (index): ";
            while (true) {
                if (!(cin >> input_var) || !(input_var <= max_index && input_var >= 0)) {
                    cout << "Bitte eine gültige Zahl eingeben: ";
                    input_var = -1;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }
                cards_taken.push_back(input_var);
                break;
            }
        } else {
            run = false;
        }
    }

    return cards_taken;
}

int Player::getExtra_points_() {
    return pool_cleared_ + stack_.contains(Card(Color::KARO, CardValue::SIEBEN));
}

int Player::count_cards() {
    return stack_.length();
}

int Player::count_pictures() {
    return stack_.amount_larger_than_number(CardValue::SIEBEN);
}

int Player::count_karo() {
    return stack_.amount_of_color(Color::KARO);
}

void Player::print_inventory() {
    inventory_.print_all_cards();
}

void Player::print_stack() {
    stack_.print_all_cards();
}

CardCollection Player::getInventory_() {
    return inventory_;
}

ostream &operator<<(ostream &os, const Player &player) {
    os << "score_: " << player.score_;
    return os;
}
