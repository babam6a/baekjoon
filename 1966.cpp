#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) {
    int cases;
    cin >> cases;
    int ans[cases];

    for (int i = 0; i < cases; i++) {
        int N, M;
        cin >> N >> M;
        queue<pair<int, int>> q;
        int priorities[N];

        for (int j = 0; j < N; j++) {
            int priority;
            cin >> priority;
            priorities[j] = priority;
            q.push(make_pair(j,priority));
        }
        sort(priorities, priorities + N, greater<int>());

        int count = 0;
        while (!q.empty()) {
            int max_priority = priorities[count];
            pair<int, int> top = q.front();
            q.pop();
            if (top.second == max_priority) {
                count++;
                if (top.first == M) {
                    ans[i] = count;
                    break;
                }
            } else if (top.second < max_priority) {
                q.push(top);
            } else {
                cout << "Error" << "\n";
            }
        }
    }
    for (int i = 0; i < cases; i++) {
        cout << ans[i] << "\n";
    }
}