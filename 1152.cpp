#include <iostream>

using namespace std;

int main(void) {
    string s;
    getline(cin, s);

    if (s.front() == ' ') {
        s.erase(0,1);
    }
    if (s.back() == ' ') {
        s.pop_back();
    }
    
    int result = (s.length() != 0) ? 1 : 0;
    for (auto it = s.begin(); it != s.end(); it++) {
        if (*it == ' ') {
            result++;
        }
    }
    cout << result;
}