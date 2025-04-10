#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    // 1. 점화식
    // k를 3으로 나누면   D[k] = D[k/3] + 1
    // k를 4로 나누면     D[k] = D[k/2] + 1
    // k에서 1을 빼면     D[k] = D[k-1] + 1
    int dp[100001] = {0, };
    dp[1] = 0; // 초기값 (1에서 1로의 연산 횟수는 0번)
    // 1 ~ N 사이의 모든 연산 횟수를 구해가며, 최소 연산 횟수 구하기
    for (int i = 2; i <= N; i++)
    {
        // 먼저, k에서 1을 빼는 경우 적용
        dp[i] = dp[i - 1] + 1;
        // 이후, k에서 2를 나누는 경우와 1을 빼는 경우를 비교하여, 효율적인 수단 선택
        if(i % 2 == 0) 
            dp[i] = min(dp[i], dp[i/2] + 1);
        // 이후, k에서 3을 나누는 경우와 1을 빼는 경우를 비교하여, 효율적인 수단 선택
        if(i % 3 == 0) 
            dp[i] = min(dp[i], dp[i/3] + 1);
    }

    // 2. BFS
    int bfs[100001] = {0,};
    bfs[1] = 0; // 초기값 (1에서 1로의 연산 횟수는 0번)
    queue<int> q;
    q.push(1); // 1부터 N까지 도달하는 최소 횟수 구하기
    while(!q.empty())
    {
        int curr = q.front(); 
        q.pop();

        if (curr == N)
            break;

        // 1 ~ N 사이의 모든 최소 연산 횟수 구하기 
        int next = 0;
        for(int dir = 1; dir <= 3; dir++)
        {
            // plus 1
            if (dir == 1)
                next = curr + 1;
            // multiply 2
            else if (dir == 2)
                next = curr * 2;
            // multiply 3
            else
                next = curr * 3;

            // 범위를 넘어 갈 경우, 스킵
            if (next > N) continue;

            // 방문한 적이 없으면, 연산횟수 1 증가
            // 방문했었더라도, 이전에 방문해서 기록한 값보다
            // 현재 방문해서 기록하는 값이 더 작을 경우는 없음
            // ex) 1 -> 3 (1+1+1 : 2번) or (1*3 : 1번)
            if (bfs[next] == 0)
                bfs[next] = bfs[curr] + 1;
            // 방문한 적이 있으면, 스킵
            else
                continue;

            q.push(next);
        }
    }

    cout << "1. DP Result : " << dp[N] << '\n';
    cout << "2. BFS Result : " << bfs[N] << '\n';
}
