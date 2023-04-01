#include <iostream>

using namespace std;

int main(void) {
    int arr[8];

    for (int i = 0; i < 8; i++) {
        cin >> arr[i];
    }

    int diff = arr[1] - arr[0];
    bool ascend = true;

    for (int i = 0; i < 7; i++) {
        int new_diff = arr[i+1] - arr[i];
        if (diff * new_diff < 0) {
            cout << "mixed";
            return 0;
        }
    }
    if (diff > 0) {
        cout << "ascending";
    }
    else {
        cout << "descending";
    }
}