#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    int arr[N];
    int sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr + N, greater<int>());

    cout << (int)(round((float)sum / N)) << "\n";
    cout << arr[(N - 1) / 2] << "\n";

    int max_freq = 0;
    stack<int> res;

    for (int i = 0; i < N;) {
        int freq = 0;
        for (int j = i; j < N; j++) {
            if (arr[i] == arr[j]) {
                freq++;
            } else {
                break;
            }
        }
        if (freq > max_freq) {
            max_freq = freq;
            while (!res.empty()){
                res.pop();
            }
            res.push(arr[i]);
        }
        else if (freq == max_freq) {
            res.push(arr[i]);
        }
        i += freq;
    }
    if (res.size() == 1) {
        cout << res.top() << "\n";
    } else {
        res.pop();
        cout << res.top() << "\n";
    }

    cout << arr[0] - arr[N-1] << "\n";
}