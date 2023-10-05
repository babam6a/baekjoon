#include <iostream>

using namespace std;

int count(int N, int x, int y, int r, int c, int ans) {
    if (N == 1) {
        if (x == r && y == c) {
            return ans;
        } else if (x == r && y + 1 == c) {
            return ans + 1;
        } else if (x+1 == r && y == c) {
            return ans + 2;
        } else if (x+1 == r && y+1 == c) {
            return ans + 3;
        } else {
            return ans + 4;
        }
    } else {
        int new_x = (1<<(N-1));
        int new_y = (1<<(N-1));
        if (x + new_x > r && y + new_y > c) {
            return count(N - 1, x, y, r, c, ans);
        }
        else if (x + new_x > r && y + new_y <= c) {
            return count(N - 1, x, y + new_y, r, c, ans + new_x * new_y);
        }
        else if (x + new_x <= r && y + new_y > c) {
            return count(N - 1, x + new_x, y, r, c, ans + 2 * new_x * new_y);
        }
        else {
            return count(N - 1, x + new_x, y + new_y, r, c, ans + 3 * new_x * new_y);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, r, c;
    cin >> N >> r >> c;
    cout << count(N, 0, 0, r, c, 0) << "\n";
}