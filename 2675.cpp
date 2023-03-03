#include <iostream>

using namespace std;

int main(void) {
    int T;
    cin >> T;
    string result;

    for (int i = 0; i < T;) {
        int R;
        string S;

        cin >> R >> S;

        for (int j = 0; j < S.length(); j++) {
            for (int k = 0; k < R; k++) {
                result.push_back(S[j]);
            }
        }
        i++;
        if (i < T) {
            result.push_back('\n');
        }
    }
    cout << result;
}