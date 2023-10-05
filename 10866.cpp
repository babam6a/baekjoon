#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    deque<int> s;

    for (int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;
        if (!cmd.compare("push_front")) {
            int X;
            cin >> X;
            s.push_front(X);
        }
        else if (!cmd.compare("push_back")) {
            int X;
            cin >> X;
            s.push_back(X);
        }
        else if (!cmd.compare("pop_front")) {
            if (s.empty()) {
                cout << -1 << "\n";
            } else {
                cout << s.front() << "\n";
                s.pop_front();
            }
        }
        else if (!cmd.compare("pop_back")) {
            if (s.empty()) {
                cout << -1 << "\n";
            } else {
                cout << s.back() << "\n";
                s.pop_back();
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