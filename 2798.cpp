#include <bits/stdc++.h>

using namespace std;

int cards[101];
int max_score = 0;
int N, M;

void dfs(int l, int c, long long sum){
    if (c==3){
        if (max_score < sum && sum <= M) 
            max_score = sum;

        return;
    }
    for (int i = l; i < N; ++i){
        dfs(i+1, c+1, sum+cards[i]);
    }
}

int main()
{
    cin >> N >> M;

    for(int i = 0; i < N; i++) 
        cin >> cards[i];

    // DFS를 활용 (O(N^3) But, 중복된 계산을 피할 수 있는 여지 有)
    dfs(0, 0, 0);

    cout << max_score << '\n';
}