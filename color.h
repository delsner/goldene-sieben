//
// Created by Daniel Elsner on 17.03.17.
//

#ifndef GOLDENE_SIEBEN_COLOR_H
#define GOLDENE_SIEBEN_COLOR_H

#include <iostream>

using namespace std;

class Color {
    int value_;
    string name_;
public:
    Color(int value_, const string &name_);

    int getValue_() const;

    const string &getName_() const;

    static Color KARO;
    static Color HERZ;
    static Color PIK;
    static Color KREUZ;

    static int compare(Color c1, Color c2);

    bool operator==(const Color &rhs) const;

    bool operator!=(const Color &rhs) const;

    friend ostream &operator<<(ostream &os, const Color &color);
};


#endif //GOLDENE_SIEBEN_COLOR_H
