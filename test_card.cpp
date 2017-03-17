#include <iostream>
#include "card.h"

using namespace std;

int main() {
    Color color = Color::HERZ;
    int value = 5;

    // create card with color and value
    Card card(color, value);

    // change value to 1
    cout << "after init: " << card.getValue_() << endl;
    card.setValue_(1);
    cout << "after setting to: " << card.getValue_() << endl;

    // change color to PIK
    cout << "after init: " << card.getColor_() << endl;
    card.setColor_(Color::PIK);
    cout << "after setting to: " << card.getColor_() << endl;

    // compare to other card with higher value
    Card higher_card(Color::KREUZ, 10);
    cout << "card1 is lower than card2: " << Card::compare(card, higher_card) << endl;

    return 0;
}