#include <iostream>
#include <queue>

using namespace std;

bool arr[50][50];
bool visited[50][50];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int M, N, K;
        cin >> M >> N >> K;

        queue<pair<int, int>> baechu;

        for (int j = 0; j < M; j++) {
            for (int k = 0; k < N; k++) {
                arr[j][k] = false;
                visited[j][k] = false;
            }
        }
        
        for (int j = 0; j < K; j++) {
            int x, y;
            cin >> x >> y;
            baechu.push(make_pair(x, y));
            arr[x][y] = true;
        }

        queue<pair<int, int>> q;
        int count = 0;

        while (!baechu.empty()) {
            pair<int, int> p = baechu.front();
            baechu.pop();
            if (!visited[p.first][p.second]) {
                q.push(p);
                visited[p.first][p.second] = true;
                while(!q.empty()) {
                    pair<int, int> p = q.front();
                    q.pop();

                    // up
                    if (p.first > 0 && arr[p.first - 1][p.second] && !visited[p.first - 1][p.second]) {
                        q.push(make_pair(p.first - 1, p.second));
                        visited[p.first - 1][p.second] = true;
                    }
                    //down
                    if (p.first < M - 1 && arr[p.first + 1][p.second] && !visited[p.first + 1][p.second]) {
                        q.push(make_pair(p.first + 1, p.second));
                        visited[p.first+1][p.second] = true;
                    }
                    //left
                    if (p.second > 0 && arr[p.first][p.second - 1] && !visited[p.first][p.second - 1]) {
                        q.push(make_pair(p.first, p.second - 1));
                        visited[p.first][p.second-1] = true;
                    }
                    //right
                    if (p.second < N - 1 && arr[p.first][p.second + 1] && !visited[p.first][p.second + 1]) {
                        q.push(make_pair(p.first, p.second + 1));
                        visited[p.first][p.second+1] = true;
                    }
                }
                count++;
            }
        }
        cout << count << "\n";
    }
}