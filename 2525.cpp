#include <iostream>

using namespace std;

int main(void) {
    int h, m, t, cal_m, cal_h;

    cin >> h >> m;
    cin >> t;

    cal_m = m + (t % 60);

    if (cal_m / 60) {
        cal_m = cal_m % 60;
        cal_h = (1 + h + (t / 60)) % 24;
    }
    else {
        cal_h = (h + (t / 60)) % 24;
    }

    cout << cal_h << " " << cal_m;
}