#include <iostream>
#include <bitset>

using namespace std;

int main(void) {
    bitset<30> b;

    for (int i = 0; i < 28; i++) {
        int n;
        cin >> n;
        b.flip(n-1);
    }

    bool first = true;

    for (int i = 0; i < 30; i++) {
        if (!b.test(i)) {
            cout << (i+1) << ((first) ? "\n" : "");
            first = false;
        }
    }
}