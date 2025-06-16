#include <bits/stdc++.h>

using namespace std;

struct Node {
    int sum;
    int row;
    int col;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int board[500][500] = {0, };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> board[i][j];
        }
    }

    /*
        dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) (0 < j < i)
        dp[i][j] = dp[i-1][j] (j == 0)
        dp[i][j] = dp[i-1][j-1] (j == i)
    */
   int answer = board[0][0];
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) 
                board[i][j] = board[i-1][j] + board[i][j];
            else if (j == i) 
                board[i][j] = board[i-1][j-1] + board[i][j];
            else 
                board[i][j] = max(board[i-1][j-1], board[i-1][j]) + board[i][j];

            answer = max(answer, board[i][j]);
        }
    }

    cout << answer << '\n';
}