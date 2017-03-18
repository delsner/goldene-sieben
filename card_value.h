//
// Created by Jan on 17.03.2017.
//

#ifndef GOLDENE_SIEBEN_CARD_VALUE_H
#define GOLDENE_SIEBEN_CARD_VALUE_H

#include <iostream>

using namespace std;

class CardValue {
    int value_;
    string name_;
public:
    CardValue(int value_, const string &name_);

    int getValue_() const;

    const string &getName_() const;

    static CardValue ASS;
    static CardValue ZWEI;
    static CardValue DREI;
    static CardValue VIER;
    static CardValue FUENF;
    static CardValue SECHS;
    static CardValue SIEBEN;
    static CardValue BUBE;
    static CardValue DAME;
    static CardValue KOENIG;

    static int compare(CardValue c1, CardValue c2);

    bool operator==(const CardValue &rhs) const;

    bool operator!=(const CardValue &rhs) const;

    friend ostream &operator<<(ostream &os, const CardValue &value);
};


#endif //GOLDENE_SIEBEN_CARD_VALUE_H
