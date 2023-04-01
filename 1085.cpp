#include <iostream>

using namespace std;

int main(void) {
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    cout << min(min(min(x, y), w-x), h-y);
}