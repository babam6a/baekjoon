#include <iostream>
#include <stack>
#include <cmath>
#define MAX 1000000000

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    bool arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = true;
    }
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        arr[a] = false;
    }

    int min_number, max_number;

    for (int i = 0; i < 10; i++) {
        if (arr[i]) {
            min_number = i;
            break;
        }
    }

    for (int i = 9; i >=0; i--) {
        if (arr[i]) {
            max_number = i;
            break;
        }
    }

    int count = 0;
    stack<int> s;

    int temp_N = N;

    while (temp_N > 0) {
        s.push (temp_N % 10);
        temp_N /= 10;
    }
    if (N == 0) {
        s.push(0);
    }

    int length = s.size();

    while (!s.empty()) {
        int a = s.top();
        s.pop();
        if (arr[a]) {
            count++;
            length--;
        } else {
            count += length;

            int target = 0;
            int temp_length = length;
            target += a * pow(10, temp_length - 1);
            temp_length--;

            while (!s.empty()) {
                target += s.top() * pow(10, temp_length - 1);
                s.pop();
                temp_length--;
            }
            cout << "target: " << target << endl;

            int lower = -1;
            int higher = -1;
            for (int i = a+1; i < 10; i++) {
                if (arr[i]) {
                    higher = i;
                    break;
                }
            }
            for (int i = a-1; i >= 0; i--) {
                if (arr[i]) {
                    lower = i;
                    break;
                }
            }
            if (higher == -1) { // low only
                int temp = 0;
                for (int i = 0; i < length - 1; i++) {
                    temp += max_number * pow(10, i);
                }
                temp += lower * pow(10, length - 1);
                int temp2 = temp + lower * pow(10, length);
                cout << "low_temp: " << temp << " " << temp2 << endl;
                if ((target - temp) < (temp2 - target)) {
                    count += (target - temp);
                } else {
                    count += (temp2 - target);
                    count++;
                }
            } else if (lower == -1) { // high only
                int temp = 0;
                for (int i = 0; i < length - 1; i++) {
                    temp += min_number * pow(10, i);
                }
                int temp2 = temp;
                temp += higher * pow(10, length - 1);
                cout << "high_temp: " << temp << " " << temp2 << endl;
                if ((target - temp2) < (temp - target)) {
                    count += (target - temp2);
                    count--;
                } else {
                    count += (temp - target);
                }
            } else { // both
                int low_temp = 0;
                int high_temp = 0;
                for (int i = 0; i < length - 1; i++) {
                    low_temp += max_number * pow(10, i);
                    high_temp += min_number * pow(10, i);
                }
                low_temp += lower * pow(10, length - 1);
                int low_temp2 = low_temp + lower * pow(10, length);
                int high_temp2 = high_temp;
                high_temp += higher * pow(10, length - 1);
                cout << "low_temp: " << low_temp << endl;
                cout << "high_temp: " << high_temp << endl;
                count += min(target - low_temp, high_temp - target);
            }
        }
    }
    cout << count << endl;
    cout << min(count, abs(100 - N)) << "\n";
}