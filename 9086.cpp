#include <iostream>

using namespace std;

int main(void) {
    int T;
    cin >> T;

    string result = "";
    int i = 0;

    while (true) {
        string s;
        cin >> s;

        result.push_back(s.front());
        result.push_back(s.back());
        i++;
        if (i == T) {
            break;
        }
        else {
            result.push_back('\n');
        }
    }

    cout << result;
}