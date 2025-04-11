#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    /*
        27을 예로 들면, 27보다 작은 제곱수는 1, 4, 9, 16, 25이다.

        27에서 이 제곱수들을 빼면 26, 23, 18, 11, 2이고

        이 수들의 최소 개수의 제곱수 합 중 최소값에 1을 더해준 값이 27의 최소 개수의 제곱수 합이다.
    */
    int dp[50001] = {0, };
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        int cnt = 300;
        // 제곱수를 뺀 나머지 중 최소값 구하기
        /*
            ex) 27
                j = 1   2   3   4   5
            i-j*j = 26, 23, 18, 11, 2

            ex) 12
                j = 1   2   3
            i-j*j = 11  8   3

            dp[3] = 3 (1^2 * 3)
            dp[8] = 2 (2^2 * 2) <== Selected
            dp[11] = 3 (3^2 + 1^2 + 1^2)

            dp[12] = dp[8] + 1 = 3
        */
        for(int j = 1; j * j <= i; j++)
        {
            cnt = min(cnt, dp[i - j * j]);
        }

        dp[i] = cnt + 1;
    }

    cout << dp[N] << '\n';
}