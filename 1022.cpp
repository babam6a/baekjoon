#include <iostream>
#include <vector>

using namespace std;

int cal_point_inside_val(int f, int s);

int main(void) {
    int r1, c1, r2, c2;

    cin >> r1 >> c1 >> r2 >> c2;

    int arr[r2 - r1 + 1][c2 - c1 + 1] = {{0}};

    vector<pair<int, int>> point_inside;
    vector<pair<int, int>> point_outside;

    int base_row = r1;
    int base_col = c1;

    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            if (abs(i) == abs(j)) {
                point_inside.push_back(make_pair(i, j));
            }
        }
    }

    int max_r = max(abs(min(r1, r2)), abs(max(r1, r2)));
    int max_c = max(abs(min(c1, c2)), abs(max(c1, c2)));

    for (int i = min(max_r, max_c) + 1; i <= max(max_r, max_c); i++) {
        if (-i >= r1 || i <= c2) {
            point_outside.push_back(make_pair(-i, i));
        }
        if (i <= r2 || -i >= c1) {
            point_outside.push_back(make_pair(i, -i));
        }
    }

    
    // if we have point_inside, fill with it
    while (!point_inside.empty()) {
        pair<int, int> p = point_inside.back();
        point_inside.pop_back();

        int f = p.first;
        int s = p.second;
        int p_val = cal_point_inside_val(f, s);

        // printf("%d %d %d\n",f,s,p_val);

        // right below
        if (f > 0 && s > 0) {
            // make upside
            int temp_p_val = p_val;
            if (s + 1 <= c2) {
                for (int j = f; j >= max(-f, base_row); j--) {
                    arr[j-base_row][s-base_col+1] = ++temp_p_val;
                }
            }
            temp_p_val = p_val;
            // make left side
            for (int j = s; j >= max(-s, base_col); j--) {
                arr[f-base_row][j-base_col] = temp_p_val--;
            }
        }

        // left below
        else if (f > 0 && s < 0) {
            int temp_p_val = p_val;
            // make right side
            for (int i = s; i <= min(-s, c2); i++) {
                arr[f-base_row][i-base_col] = temp_p_val++;
            }
            //make upside
            temp_p_val = p_val;
            for (int j = f; j >= max(-f, base_row); j--) {
                arr[j-base_row][s-base_col] = temp_p_val--;
            }
        }

        // right upper
        else if (f < 0 && s > 0) {
            int temp_p_val = p_val;
            // make left side
            for (int i = s; i >= max(-s, base_col); i--) {
                arr[f-base_row][i-base_col] = temp_p_val++;
            }
            temp_p_val = p_val;
            // make downside
            for (int j = f; j <= min(-f, r2); j++) {
                if (j != -f) {
                    arr[j-base_row][s-base_col] = temp_p_val--;
                }
            }
        }
        // left upper
        else if (f < 0 && s < 0) {
            int temp_p_val = p_val;
            // make right side
            for (int i = s; i <= min(-s, c2); i++) {
                arr[f-base_row][i-base_col] = temp_p_val--;
            }
            temp_p_val = p_val;
            // make downside
            for (int j = f; j <= min(-f, r2); j++) {
                arr[j-base_row][s-base_col] = temp_p_val++;
            }
        }
        else if (f == 0 && s == 0) {
            arr[f-base_row][s-base_col] = 1;
        }

        // for (auto &row : arr)
        // {
        //     for (auto &column : row)
        //     {
        //         cout << column << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
    }

    while (!point_outside.empty()) {
        bool is_calculated = false;

        pair<int, int> p = point_outside.back();
        point_outside.pop_back();

        int f = p.first;
        int s = p.second;
        int p_val = cal_point_inside_val(f, s);
        int overflowed;

        printf("%d %d %d\n",f,s,p_val);

        // right upper
        if (f < 0) {
            // make down
            int temp_p_val = p_val;
            if (base_row > f) {
                overflowed = f;
                while (overflowed < base_row) {
                    overflowed++;
                    temp_p_val--;
                }
                for (int j = overflowed; j <= min(-f, r2); j++) {
                    if (j != -f) {
                        arr[j-base_row][s-base_col] = temp_p_val--;
                    }
                }
            }
            // make left
            else if (c2 < s) {
                overflowed = s;
                while (overflowed > c2) {
                    overflowed--;
                    temp_p_val++;
                }
                for (int i = overflowed; i >= max(-s, base_col); i--) {
                    arr[f-base_row][i-base_col] = temp_p_val++;
                }
            }
        }
        else {
            int temp_p_val = p_val;
            
            // make up
            if (r2 < f) {
                overflowed = f;
                while (overflowed > r2) {
                    overflowed--;
                    temp_p_val--;
                }
                for (int j = overflowed; j >= max(-f, base_row); j--) {
                    arr[j-base_row][s-base_col] = temp_p_val--;
                }
            }
            // make right
            else if (base_col > s) {
                temp_p_val = p_val;
                overflowed = s;
                while (overflowed < base_col) {
                    overflowed++;
                    temp_p_val++;
                }
                for (int i = overflowed; i <= min(-s, c2); i++) {
                    arr[f-base_row][i-base_col] = temp_p_val++;
                }
            }
        }
        // for (auto &row : arr)
        // {
        //     for (auto &column : row)
        //     {
        //         cout << column << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
    }
    int max_num = max(max(max(arr[0][0], arr[0][c2-c1]), arr[r2-r1][0]), arr[r2-r1][c2-c1]);
    int count = 0;
    while (max_num > 0) {
        max_num /= 10;
        count++;
    }

    for (int i = 0; i < r2 - r1; i++)
    {
        for (int j = 0; j < c2 - c1 + 1; j++)
        {
            cout.width(count);
            cout.fill(' ');
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    for (int j = 0; j < c2 - c1; j++)
    {
        cout.width(count);
        cout.fill(' ');
        cout << arr[r2-r1][j] << " ";
    }
    cout.width(count);
    cout.fill(' ');
    cout << arr[r2-r1][c2-c1];
}

int cal_point_inside_val(int f, int s) {
    int n = abs(f) + 1;

    if (f > 0 && s > 0) {
        return 4*n*(n-1) + 1;
    }
    else if (f > 0 && s < 0) {
        return 2*(n-1)*(2*n-1) + 1;
    }
    else if (f < 0 && s > 0) {
        return 2*(n-1)*(2*n -3) + 1;
    }
    else if (f < 0 && s < 0) {
        return 4*(n-1)*(n-1) + 1;
    }
    else if (f == 0 && s == 0) {
        return 1;
    }
    return 0;
}