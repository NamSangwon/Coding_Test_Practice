#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short N, M;
    cin >> N >> M;

    // 그래프 문제로 해석 가능 (position -> next_position)
    vector<short> board(101);
    for(short i = 1; i < board.size(); i++) {
        board[i] = i;
    }

    for (short i = 0; i < N; i++){
        short start, end;
        cin >> start >> end;
        board[start] = end;
    }

    for (short i = 0; i < M; i++) {
        short start, end;
        cin >> start >> end;
        board[start] = end;
    }

    // 방문 여부 확인은 조건이 아닌 최적화를 위해 사용
    // 뱀 타고 내려가더라도 방문했던 위치는 최단 거리가 아니므로 계산 생략 가능
    vector<bool> visited(101, false);
    queue<pair<short, short>> q; // {pos, level}
    q.push({1, 0});
    while(!q.empty()) {
        pair<short,short> curr = q.front();
        q.pop();

        if (curr.first == 100) {
            cout << curr.second << '\n';
            break;
        }

        for (short i = 6; i >= 1; i--) {
            if (curr.first + i > 100) continue;

            short next_pos = board[curr.first + i];

            if (!visited[next_pos]) {
                visited[next_pos] = true;
                q.push({next_pos, curr.second + 1});
            }
        }
    }
}