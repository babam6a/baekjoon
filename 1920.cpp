#include <iostream>

using namespace std;

void quick_sort(int A[], long long l, long long r) {
    long long m = (l + r) / 2;
    int pivot = A[m];
    long long i = l;
    long long j = r;

    while (i <= j) {
        while (A[i] < pivot) {
            i++;
        }
        while (A[j] > pivot) {
            j--;
        }
        if (i <= j) {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
            j--;
        }
    }

    if (l < j) {
        quick_sort(A, l, j);
    }
    if (i < r) {
        quick_sort(A, i, r);
    }
}

bool binary_search (int A[], long long l, long long r, int M) {
    long long m = (l + r) / 2;
    if (A[m] == M) {
        return true;
    } else if (l == r) {
        return false;
    } else if (A[m] > M) {
        return binary_search(A, l, m, M);
    } else {
        return binary_search(A, m + 1, r, M);
    }
}

int main(void) {
    int N, M;
    cin >> N;

    int A[N];

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    quick_sort(A, 0, N-1);
    
    cin >> M;
    int B[M];

    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    for (int j = 0; j < M; j++) {
        bool result = true;
        if (A[N-1] < B[j] || B[j] < A[0]) {
            result = false;
        } else {
            if (!binary_search(A, 0, N-1, B[j])) {
                result = false;
            }
        }
        if (result) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
}