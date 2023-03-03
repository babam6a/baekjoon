#include <iostream>

using namespace std;

int main(void) {
    int a, b, c, result;

    cin >> a >> b >> c;

    if (a == b && b == c) {
        result = 10000 + a * 1000;
    }
    else if (a != b && b != c && a != c) {
        result = max(max(a, b), c) * 100;
    }
    else {
        if (a == b) {
            result = 1000 + a*100;
        }
        else {
            result = 1000 + c*100;
        }
    }

    cout << result;
}