#include <iostream>

using namespace std;

int main(void) {
    int N, M;
    cin >> N >> M;

    int arr[N+1] = {}; 

    for (int n = 0; n < M; n++) {
        int i, j, k;
        cin >> i >> j >> k;

        for (int p = i; p <= j; p++) {
            arr[p] = k;
        }
    }

    for (int index = 1; index < N; index++) {
        cout << arr[index] << " ";
    }
    cout << arr[N];
}