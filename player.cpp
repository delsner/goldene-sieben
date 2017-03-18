//
// Created by Daniel Elsner on 17.03.17.
//

#include "card.h"
#include "player.h"

Player::Player() {
    pool_cleared_ = 0;
}

void Player::add_cards_to_inventory(Card cards[]) {
    for (int i = 0; i < sizeof(cards); i++) {
        inventory_.add_card_to_collection(cards[i]);
    }
}

void Player::remove_cards_from_inventory(Card cards[]) {
    for (int i = 0; i < sizeof(cards); i++) {
        inventory_.remove_card_from_collection(cards[i]);
    }
}

void Player::add_cards_to_stack(Card cards[]) {
    for (int i = 0; i < sizeof(cards); i++) {
        stack_.add_card_to_collection(cards[i]);
    }
}

void Player::increment_extra_points() {
    pool_cleared_++;
}

void Player::reset() {
    // Reset Extrapoints, stack and inventory for new game
    pool_cleared_ = 0;

    inventory_ = *(new CardCollection);
    stack_ = *(new CardCollection);
}

/*Draw Player::request() {
    return Draw();
}*/

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
