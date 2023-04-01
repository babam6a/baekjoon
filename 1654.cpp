#include <iostream>
#include <cmath>

using namespace std;

int K, N;
int arr[10000];

bool is_right_length(unsigned int length) {
    unsigned long long count = 0;
    for (int i = 0; i < K; i++) {
        count += arr[i] / length;
    }
    return count >= N;
}

int binary_search(unsigned long long l, unsigned long long r) {
    unsigned long long mid = (l + r) / 2;
    if (l == r)
        return l;
    if (l == r - 1) {
        if (is_right_length(r))
            return r;
        else
            return l;
    }
    if (is_right_length(mid))
        return binary_search(mid, r);
    else
        return binary_search(l, mid);
}

int main(void) {
    cin >> K >> N;

    for (int i = 0; i < K; i++)
        cin >> arr[i];

    cout << binary_search(1, pow(2, 31) - 1);
}