#include <bits/stdc++.h>

using namespace std;

void plus_one_two_three(int& result, int num)
{
    if (num == 0) 
        result++;

    for (int i = 1; i <= 3; i++)
    {
        if (num >= i)
        {
            plus_one_two_three(result, num - i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;

        // 1. 재귀 함수로 구현
        //    => 메모리 및 속도 성능이 DP보다 현저히 낮음
        int recur_answer = 0;
        plus_one_two_three(recur_answer, N);

        // 2. DP 점화식으로 구현
        // ★ dp[n] = dp[n-1] + dp[n-2] + dp[n-3] ★
        /*
            1) 1을 더하는 경우 -> dp[n-1]의 방법의 수에 각각 1을 더하는 경우의 수 = dp[n-1]개
            2) 2를 더하는 경우 -> dp[n-2]의 방법의 수에 각각 2를 더하는 경우의 수 = dp[n-2]개
            3) 3을 더하는 경우 -> dp[n-3]의 방법의 수에 각각 3을 더하는 경우의 수 = dp[n-3]개
        */
        int dp[31];
        dp[1] = 1; // 1 = 1
        dp[2] = 2; // 2 = (1 + 1) or (2)
        dp[3] = 4; // 3 = (1+1+1) or (1+2) or (2+1) or (3)
        for (int i = 4; i <= N; i++)
        {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        cout << "Recursion Answer = " << recur_answer << '\n';
        cout << "DP Answer = " << dp[N] << '\n';
    }
}