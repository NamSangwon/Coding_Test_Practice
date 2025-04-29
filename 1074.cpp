#include <bits/stdc++.h>

using namespace std;

int N, r, c;

int solve(int x, int y, int line_num)
{
    if (line_num <= 0 || (x==c && y==r)) return 0;

    int line_half = line_num / 2;
    int quad_cnt = line_half * line_half;

    int count = 0;
    int next_x = 0;
    int next_y = 0;
    if (r < y + line_half && c < x + line_half) {
        next_x = x;
        next_y = y;
    }
    else if (r < y+line_half && c >= x + line_half) {
        count = quad_cnt;
        next_x = x + line_half;
        next_y = y;
    }
    else if (r >= y+line_half && c < x + line_half) {
        count = quad_cnt * 2;
        next_x = x;
        next_y = y + line_half;
    }
    else {
        count = quad_cnt * 3;
        next_x = x + line_half;
        next_y = y + line_half;
    }

    return count + solve(next_x, next_y, line_half);
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> r >> c;
    
    int line_len = pow(2, N);

    cout << solve(0, 0, line_len) << '\n';
}