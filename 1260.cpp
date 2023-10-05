#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(void) {
    int N, M, V;
    cin >> N >> M >> V;

    bool matrix[N+1][N+1] = {false, };

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        matrix[a][b] = true;
        matrix[b][a] = true;
    }

    bool visited[N+1] = {false, };

    // DFS
    stack<int> s;
    
    s.push(V);
    
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        if (visited[top]){
            continue;
        }

        visited[top] = true;

        cout << top << " ";

        for (int i = N; i > 0; i--) {
            if (matrix[top][i] && !visited[i]) {
                s.push(i);
            }
        }
    }
    cout << "\n";

    for (int i = 0; i < N+1; i++) {
        visited[i] = false;
    }

    // BFS
    queue<int> q;

    q.push(V);

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        if (visited[top]){
            continue;
        }
        visited[top] = true;

        cout << top << " ";

        for (int i = 1; i < N+1; i++) {
            if (matrix[top][i] && !visited[i]) {
                q.push(i);
            }
        }
    }
}