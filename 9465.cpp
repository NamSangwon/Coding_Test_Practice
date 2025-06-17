#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;

        int board[2][100001];
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> board[i][j];
            }
        }

        /*
            [1, 2, 3]
            [4, 5, 6]
            
            위 배열에서 3번의 값이 정해지는 두 가지 경우
                1. 1 -> 5 -> 3
                2. 4 -> 3
            다음 두 가지 경우에 대해서만 비교 (1, 2, 4, 5 는 이미 정해짐)
        */
        int dp[2][100001];		
        dp[0][0] = 0;
        dp[1][0] = 0;
        dp[0][1] = board[0][1];
        dp[1][1] = board[1][1];

        for (int j = 2; j <= N; j++) {
            dp[0][j] = max(dp[1][j - 2], dp[1][j - 1]) + board[0][j];
            dp[1][j] = max(dp[0][j - 2], dp[0][j - 1]) + board[1][j];
        }

        cout << max(dp[0][N], dp[1][N]) << '\n';
    }
}