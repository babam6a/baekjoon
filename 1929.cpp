#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    int M, N;
    cin >> M >> N;
    bool *arr = new bool[N+1]; // 0 ~ N
    for (int i = 0; i < N+1; i++) {
        arr[i] = false;
    }
    for (int i = 2; i < sqrt(N)+1; i++) {
        if (arr[i] == false) { // false is prime
            for (int j = i+1; j < N+1; j++) {
                if (arr[j] == false && j % i == 0) {
                    arr[j] = true;
                }
            }
        }
    }
    
    for (int i = max(M, 2); i < N+1; i++) {
        if (arr[i] == false) {
            cout << i << "\n";
        }
    }
}