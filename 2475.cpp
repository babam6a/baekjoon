#include <iostream>

using namespace std;

int main(void) {
    int arr[5];

    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    int result = 0;

    for (int i = 0; i < 5; i++) {
        result += (arr[i]*arr[i]);
    }

    cout << (result % 10);
}