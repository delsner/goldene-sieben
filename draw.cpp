//
// Created by Daniel Elsner on 17.03.17.
//

#include <vector>
#include "card.h"
#include "draw.h"

Draw::Draw(const Card &card_played, const std::vector <Card, std::allocator<Card>> &cards_taken) : card_played(
        card_played), cards_taken(cards_taken) {}
