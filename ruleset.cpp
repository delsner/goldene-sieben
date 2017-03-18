//
// Created by Daniel Elsner on 17.03.17.
//

#include "draw.h"
#include "card_collection.h"
#include "ruleset.h"

bool Ruleset::check_sum_(Draw draw) {
    int sum = 0;

    if (draw.cards_taken.size() == 0) {
        return true;
    }

    for (int i = 0; i < draw.cards_taken.size(); i++) {
        sum = sum + draw.cards_taken[i].getValue_().getValue_();
    }

    if (draw.card_played.getValue_().getValue_() == sum) {
        return true;
    }

    return false;
}

bool Ruleset::check_card_inventory_(Draw draw, CardCollection inventory) {
    return inventory.contains(draw.card_played);
}

bool Ruleset::check_card_pool_(Draw draw, CardCollection pool) {
    for (int i = 0; i < draw.cards_taken.size(); i++) {
        if (!pool.contains(draw.cards_taken[i])) {
            return false;
        };
    }
    return true;
}

bool Ruleset::validate(Draw draw, CardCollection pool, CardCollection inventory) {
    return Ruleset::check_card_inventory_(draw, inventory) && Ruleset::check_sum_(draw) &&
           Ruleset::check_card_pool_(draw, pool);
}
