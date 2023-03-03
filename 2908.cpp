#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string A, B;

    cin >> A >> B;

    int i = 0;
    int j = A.length() - 1;
    char temp;

    for (i,j; i <= j; i++, j--) {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;    
    }
    
    i = 0;
    j = B.length() - 1;
    for (i,j; i <= j; i++, j--) {
        temp = B[i];
        B[i] = B[j];
        B[j] = temp;    
    }

    int a = stoi(A);
    int b = stoi(B);

    cout << max(a,b);
}