#include <bits/stdc++.h>

using namespace std;

// // 다음 아이디어는 SUM(nCr) (n = N, r = 0 ... (N/2)) 이다. 
// // 시간 및 공간 복잡도가 크게 증가하여, 효율적이지 못함.
 
// const int MAX_N = 100;
// int C(int n, int r)
// {
//     int dp[MAX_N][MAX_N] = { 0, };

// 	for (int i = 0; i <= n; i++)
//         // r 이상은 찾을 필요 X
// 		for (int j = 0; j <= min(r, i); j++) 
// 			if (i == j || j == 0)
// 				dp[i][j] = 1;
// 			else
// 				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];

// 	return dp[n][r];
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int N;
//     cin >> N;

//     // nHr = n+r-1Cr
//     // n = '|' 자 타일 사이의 개수 (ex. 2개의 '|' 타일 사이의 개수 = 3)
//     //      -> 'ㅡ'자 타일 2개 묶음('=')이 놓일 수 있는 위치 개수
//     // r = 'ㅡ'자 타일 2개 묶음('=')의 개수
//     int answer = 0; // 모두 세로인 경우의 수, +1

//     // '|' 자 타일 n+1개 사이에 '=' 타일 묶음 r개가 들어갈 조합
//     // 9        => 9개 사이 및 양 끝에 들어감 => 10H0 = 9C0 = 1
//     // 9-2      => 7개 사이 및 양 끝에 들어감 => 8H1 = 8C1 = 8
//     // 9-(2*2)  => 5개 사이 및 양 끝에 들어감 => 6H2 = 7C2 = 21
//     // 9-(2*3)  => 3개 사이 및 양 끝에 들어감 => 4H3 = 6C3 = 20
//     // 9-(2*4)  => 1개 사이 및 양 끝에 들어감 => 2H4 = 5C4 = 5
//     // sum(nCr) (n = N, r = 0 ... (N/2)) 
//     for(int i = 0; i <= N / 2; i++)
//     {
//         // nHr = n+r-1Cr 
//         answer += C(N-i, i);
//     }

//     cout << answer << '\n';
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    // dp[i] = dp[i-1] + dp[i-2]
    //  -> dp[i-1]에 세로 타일 하나를 추가한 경우
    //  -> dp[i-2]에 가로 타일 두 개를 추가한 경우
    //  ==> 이는, 피보나치 수열이다.
    int dp[N+1] = {0,};
    dp[0] = 1; dp[1] = 1;
    for(int i = 2; i <= N; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }

    cout << dp[N] << '\n';
}