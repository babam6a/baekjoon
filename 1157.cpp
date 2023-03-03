#include <iostream>
#include <map>

using namespace std;

int main(void) {
    map<char, int> m;
    string s;

    getline(cin, s);

    for (int i = 0; i < s.length(); i++) {
        char s_n = toupper(s[i]);
        if (m.find(s_n) == m.end()) {
            m[s_n] = 1;
        }
        else {
            m[s_n] += 1;
        }
    }
    
    int max = 0;
    char result;
    bool same = false;

    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second > max) {
            max = it->second;
            result = it->first;
            same = false;
        }
        else if (it->second == max) {
            same = true;
        }
    }

    if (same) {
        cout << "?";
    }
    else {
        cout << result;
    }
}