#include <iostream>
#include "card.h"

using namespace std;

int main() {
    Color color = Color::HERZ;
    CardValue value = CardValue::KOENIG;

    // create card with color and value
    Card card(color, value);

    // change value to Bube
    cout << "after init: " << card.getValue_().getName_() << endl;
    card.setValue_(CardValue::BUBE);
    cout << "after setting to: " << card.getValue_().getName_() << endl;

    // change color to PIK
    cout << "after init: " << card.getColor_().getName_() << endl;
    card.setColor_(Color::PIK);
    cout << "after setting to: " << card.getColor_().getName_() << endl;

    // compare to other card with higher value
    Card higher_card(Color::KREUZ, CardValue::KOENIG);
    cout << "card1 is lower than card2: " << Card::compare(card, higher_card) << endl;


    return 0;
}