#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> stairs(N+1);
    for (int i = 1; i <= N; i++)
        cin >> stairs[i];
    
    // ★ DP[i] = max(DP[i - 2] + arr[i], DP[i - 3] + arr[i - 1] + arr[i]);
    int dp[301];
    dp[0] = 0;
    dp[1] = stairs[1];
    dp[2] = stairs[1] + stairs[2];
    for (int i = 3; i <= N; i++)
    {
        // ex. (1 -> 3) or (0 -> 2 -> 3) 값 비교
        dp[i] = max(dp[i-2]+stairs[i], dp[i-3]+stairs[i-1]+stairs[i]);
    }

    cout << dp[N] << '\n';
}