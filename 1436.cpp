#include <iostream>

using namespace std;

int main(void) {
    int N;

    cin >> N;
    
    int result = 666;
    while (N != 0) {
        int temp = result;
        while (temp) {
            if (temp % 1000 == 666) {
                N--;
                break;
            }
            temp /= 10;
        }
        result++;
    }
    cout << result - 1;
}