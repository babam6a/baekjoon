#include <iostream>

using namespace std;

int main(void) {
    int X, N;
    int result = 0;
    cin >> X;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        result += a * b;
    }
    string nresult = (X == result) ? "Yes" : "No";
    cout << nresult;
}