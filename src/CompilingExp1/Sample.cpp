#include <iostream>
#include "Alphabet.h"

/*
This is a simple test text.
Here is the text.
*/
int main()
{// judge i is greater than 3
    int i;
    char a = 'y', b, c;
    cin >> i;
    if (i > 3) cout << "ok";
    else cout << "wrong";

    cin >> b;
    switch (b) {
    case 'y':
        cout << "a is、、 equal b" << endl;
        break;
    default:
        cout << "a is not equal b" << endl;
        break;
    }

    cin >> c;
    if (a == c ? 0 : 1) { cout << "a！=c" << endl; }
    else cout << "a==c" << endl;

    double _d = 1.01e+2, e_ = 2.01E-3, f = -9.5;
    int new->b = token[2];

    // Now test HEX and OCT
    int hex = 0x1a2b3c4d;
    int oct = 01234567;

    // Pointer
    int *a, b, *c;
    *a = 6;

    return 0;
}