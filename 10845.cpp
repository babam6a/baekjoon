#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    queue<int> s;

    for (int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;
        if (!cmd.compare("push")) {
            int X;
            cin >> X;
            s.push(X);
        }
        else if (!cmd.compare("pop")) {
            if (s.empty()) {
                cout << -1 << "\n";
            } else {
                cout << s.front() << "\n";
                s.pop();
            }
        }
        else if (!cmd.compare("size")) {
            cout << s.size() << "\n";
        }
        else if (!cmd.compare("empty")) {
            cout << s.empty() << "\n";
        }
        else if (!cmd.compare("front")) {
            if (s.empty()) {
                cout << -1 << "\n";
            } else {
                cout << s.front() << "\n";
            }
        }
        else if (!cmd.compare("back")) {
            if (s.empty()) {
                cout << -1 << "\n";
            } else {
                cout << s.back() << "\n";
            }
        }
    }
}