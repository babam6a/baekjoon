#include <iostream>
#include <queue>
#include <stack>
#include <functional>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int k;
        cin >> k;
        priority_queue<int> q;

        for (int j = 0; j < k; j++) {
            char command;
            int n;
            cin >> command >> n;

            switch (command) {
                case 'I':
                    q.push(n);
                    break;
                case 'D':
                    if (!q.empty()) {
                        if (n == 1) {
                            q.pop();
                        } else {
                            stack<int> temp;
                            while (!q.empty()) {
                                temp.push(q.top());
                                q.pop();
                            }
                            temp.pop();
                            while(!temp.empty()) {
                                q.push(temp.top());
                                temp.pop();
                            }
                        }
                    }
                    break;
                default :
                    break;
            }
        }

        if (q.empty()) {
            cout << "EMPTY" << "\n";
        } else {
            cout << q.top() << " ";
            int top;
            while (!q.empty()) {
                top = q.top();
                q.pop();
            }
            cout << top;
        }
    }
}