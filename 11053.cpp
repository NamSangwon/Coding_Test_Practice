#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    // [가장 긴 증가 부분 수열의 DP 점화식(?)]
    // ※ v[i] < v[a], v[b], v[c]
    // ※ dp[i] = max(dp[a], dp[b], dp[c], ...) + 1

    // Binary Search 를 통해
    // i번째 원소를 대체할 가장 큰 원소의 인덱스 구하기
    // (위의 예에서 dp[a], dp[b], dp[c] 중 가장 큰 값을 구하는 것이다.)
    vector<int> dp;
    for (int i = 0; i < N; i++) {
        // 비어있거나 dp의 마지막 원소보다 here이 크다면 dp에 here을 추가
        if (dp.empty() || dp.back() < v[i]) {
            dp.push_back(v[i]);
        }
        // 그렇지 않다면 lower_bound를 찾아 dp 배열 갱신 
        else {
            // v[i] 이상의 수들 중 가장 작은 수 찾기
            int lower_index = lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
            dp[lower_index] = v[i];
        }
    }

    cout << dp.size() << '\n';
}