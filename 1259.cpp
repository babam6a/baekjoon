#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
    while (true) {
        string str;

        cin >> str;

        if (str.compare("0") == 0)
            break;
        

        string result = "yes";
        int l = 0;
        int r = str.length() - 1;
        while (l < r) {
            if (str[l] != str[r]){
                result = "no";
                break;
            }
            l++;
            r--;
        }
        cout << result << "\n";
    }
}