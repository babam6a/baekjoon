#include <iostream>

using namespace std;

int main(void) {
    int arr[100];

    int N, v;
    int result = 0;
    cin >> N;

    int i = 0;
    for (i; i < N; i++) {
        cin >> arr[i];
    }

    cin >> v;

    for (int j = 0; j < i; j++) {
        if (arr[j] == v) {
            result += 1;
        }
    }

    cout << result;
}