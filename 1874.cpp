#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    stack<int> s;
    string ans;
    int max = 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (s.empty()) {
            for (int j = max; j <= x; j++, max++){
                s.push(j);
                ans.append("+\n");
            }
            s.pop();
            ans.append("-\n");
        } else {
            if (s.top() > x) {
                cout << "NO" << endl;
                return 0;
            }
            else {
                for (int j = max; j <= x; j++, max++){
                    s.push(j);
                    ans.append("+\n");
                }
                s.pop();
                ans.append("-\n");
            }
        }
    }
    cout << ans;
}