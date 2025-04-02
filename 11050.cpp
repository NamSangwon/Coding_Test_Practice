#include <bits/stdc++.h>

using namespace std;

const int MAX_BINOMIAL_COEFFICIENT = 100;

uint64_t factorial(int n)
{
    if (n == 1) 
        return 1;

    return n * factorial(n-1);
}

// 1. 점화식 기반 분할정복 알고리즘 (DNC = Devide and Conquer)
// Memoization 적용 (dnc 배열을 통해)
// nCr = (n-1)C(r-1) + (n-1)C(r)
int dnc[MAX_BINOMIAL_COEFFICIENT][MAX_BINOMIAL_COEFFICIENT] = {0,};
int DNC_binomial(int n, int r)
{
    if (dnc[n][r] > 0) 
        return dnc[n][r];
    else if (r ==0 || n == r)
        return 1;
    else
    {
        dnc[n][r] = DNC_binomial(n-1, r-1) + DNC_binomial(n-1, r);
        return dnc[n][r];
    }
}

// 2. DP를 통한 알고리즘
int dp_binomial(int n, int r)
{
    int dp[MAX_BINOMIAL_COEFFICIENT][MAX_BINOMIAL_COEFFICIENT] = { 0, };

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= min(r, i);j++)
			if (i == j || j == 0)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];

	return dp[n][r];
}

int main() {
    int n, k;
    cin >> n >> k;

    // 1차원적인 정답
    // n과 k가 커지면 uint64_t 자료형 범위를 초과
    // nCk = N!/(K!*(N-K)!)
    cout << "default : " << factorial(n) / (factorial(k) * factorial(n-k)) << '\n';

    // 1. 점화식 기반 분할 정복 (Top-Down 방식)
    // n이 커질 수록 부분식의 중복 발생 -> 성능 저하
    // Memoization을 통해 중복 계산 문제에 대한 성능 개선 가능
    cout << "DNC : " << DNC_binomial(n, k) << '\n';

    // 2. DP (Bottom-Up 방식)
    // 부분식의 중복 발생 X
    cout << "DP : " << dp_binomial(n, k) << '\n';
}