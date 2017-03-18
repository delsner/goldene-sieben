// Created by Jan on 18.03.2017.
//


#include "player.h"

using namespace std;

int main() {
    Player player1;

    Card card1(Color::KARO,CardValue::ASS);
    Card card2(Color::KARO,CardValue::BUBE);
    Card card3(Color::KARO,CardValue::SIEBEN);
    Card card4(Color::HERZ,CardValue::DAME);
    Card card5(Color::HERZ,CardValue::FUENF);
    Card card6(Color::PIK,CardValue::SIEBEN);

    Card cards[]={card1,card2,card3};

    player1.add_cards_to_inventory(cards);
    cout << "player cards in inventory: " << endl;
    player1.print_inventory();


    Card cardsrm[]={card1};
    player1.remove_cards_from_inventory(cardsrm);
    cout << "player cards in inventory after remove: " << endl;
    player1.print_inventory();


    Card cards2[]={card4,card5,card6};
    player1.add_cards_to_stack(cards2);
    cout << "player cards in stack: " << endl;
    player1.print_stack();

    cout << "player NUM of CARDS in stack: " << player1.count_cards() <<  endl;

    cout << "player NUM of PICTURES in stack: " << player1.count_pictures() <<  endl;

    cout << "player NUM of KAROS in stack: " << player1.count_karo() <<  endl;


    Card cardsC7[]={card3};
    player1.add_cards_to_stack(cardsC7);
    cout << "player cards in stack with C7: " << endl;
    player1.print_stack();


    cout << "player NUM of ExtraPoint: " << player1.getExtra_points_() <<  endl;

    player1.increment_extra_points();

    cout << "player NUM of ExtraPoint, after add 1 PoolExtraPoint: " << player1.getExtra_points_() <<  endl;


    player1.reset();
    cout << "player cards in inventory after reset: " << endl;
    player1.print_inventory();
    cout << "player cards in stack after reset: " << endl;
    player1.print_inventory();
    cout << "player NUM of ExtraPoint after reset: " << player1.getExtra_points_() <<  endl;

    return 0;
}//

