#include <iostream>

using namespace std;
char arr[50][50];

int is_right_chess(int a, int b) {
    char base = arr[a][b];
    int count = 0;
    int oppose_count = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2) {
                if (arr[a+i][b+j] == base)
                    count++;
                else
                    oppose_count++;
            } else {
                if (arr[a+i][b+j] != base)
                    count++;
                else
                    oppose_count++;
            }
        }
    }

    return min(count, oppose_count);
}

int main(void) {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];
    }

    int min_count = 9999;

    for (int i = 0; i < N-7; i++) {
        for (int j = 0; j < M-7; j++) {
            int count = is_right_chess(i,j);
            if (min_count > count)
                min_count = count;
        }
    }
    cout << (min_count % 9999);
}