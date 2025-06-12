#include <bits/stdc++.h>

using namespace std;

const int INF = 1000 * 1000 + 1; // 충분히 큰 값

enum COLOR { R, G, B };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    int houses[1000][3]; // N이 1000이면 인덱스 0~999 사용
    for (int i = 0; i < N; i++) {
        cin >> houses[i][COLOR::R] >> houses[i][COLOR::G] >> houses[i][COLOR::B];
    }

    int answer = INT_MAX; // 최종 최소 비용

    // 1번 집의 시작 색상을 0(R), 1(G), 2(B)로 고정하여 각각 DP 수행
    for (int start_color = 0; start_color < 3; start_color++) {
        int dp[1000][3]; // 각 케이스마다 DP 테이블 초기화

        // 첫 번째 집 (0번 인덱스) 초기화
        dp[0][COLOR::R] = (start_color == COLOR::R) ? houses[0][COLOR::R] : INF;
        dp[0][COLOR::G] = (start_color == COLOR::G) ? houses[0][COLOR::G] : INF;
        dp[0][COLOR::B] = (start_color == COLOR::B) ? houses[0][COLOR::B] : INF;

        // 두 번째 집부터 N번째 집까지 (1번 인덱스부터 N-1번 인덱스까지) DP 계산
        for (int j = 1; j < N; j++) {
            dp[j][COLOR::R] = houses[j][COLOR::R] + min(dp[j-1][COLOR::G], dp[j-1][COLOR::B]);
            dp[j][COLOR::G] = houses[j][COLOR::G] + min(dp[j-1][COLOR::R], dp[j-1][COLOR::B]);
            dp[j][COLOR::B] = houses[j][COLOR::B] + min(dp[j-1][COLOR::G], dp[j-1][COLOR::R]);
        }

        // 각 start_color 케이스에 대한 최종 비용을 answer에 반영
        // N번 집의 색상은 N-1번 집의 색상과 달라야 한다는 조건은 이미 DP 점화식에 포함됨
        // N번 집의 색상은 1번 집의 색상과 같을 수도 있으므로, 모든 dp[N-1][color]를 고려
        answer = min({answer, dp[N-1][COLOR::R], dp[N-1][COLOR::G], dp[N-1][COLOR::B]});
    }
    
    cout << answer << '\n';

    return 0;
}