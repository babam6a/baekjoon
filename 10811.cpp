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

        for (i,j; i <= j; i++, j--) {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }

    for (int index = 1; index < N; index++) {
        cout << arr[index] << " ";
    }
    cout << arr[N];
}