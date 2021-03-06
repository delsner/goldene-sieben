//
// Created by Daniel Elsner on 17.03.17.
//

#ifndef GOLDENE_SIEBEN_RULESET_H

#define GOLDENE_SIEBEN_RULESET_H


#include "draw.h"
#include "card_collection.h"

class Ruleset {
    // überprüfe summe der genommenen Karten mit gespielter Karte
    static bool check_sum_(Draw draw);

    // überprüfe ob gespielte Karte auf Hand
    static bool check_card_inventory_(Draw draw, CardCollection inventory);

    // überprüfe ob genommene Karte(n) in pool
    static bool check_card_pool_(Draw draw, CardCollection pool);

public:
    static bool validate(Draw draw, CardCollection pool, CardCollection inventory);
};

#endif //GOLDENE_SIEBEN_RULESET_H