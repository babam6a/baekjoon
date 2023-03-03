#include <iostream>

using namespace std;

int main(void) {
    int N, M;
    cin >> N >> M;

    int arr[N+1] = {}; 

    for (int r = 1; r <= N; r++) {
        arr[r] = r;
    }

    for (int n = 0; n < M; n++) {
        int i, j, temp;
        cin >> i >> j;

        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    for (int index = 1; index < N; index++) {
        cout << arr[index] << " ";
    }
    cout << arr[N];
}