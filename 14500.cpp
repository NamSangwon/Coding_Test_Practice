#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[500][500];
bool visited[500][500];
int dx[4] = {-1, 0, 1, 0}; // 상우하좌
int dy[4] = {0, 1, 0, -1};
int answer = 0;

void dfs(int x, int y, int depth, int sum) {
    if (depth == 4) {
        answer = max(answer, sum);
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (visited[nx][ny]) continue;

        visited[nx][ny] = true;
        dfs(nx, ny, depth + 1, sum + board[nx][ny]);
        visited[nx][ny] = false;
    }
}

// 'ㅗ', 'ㅜ', 'ㅓ', 'ㅏ' 모양 처리
void check_extra(int x, int y) {
    // 중심 포함 + 3방향
    int center = board[x][y];
    for (int i = 0; i < 4; i++) {
        int sum = center;
        bool is_valid = true;
        for (int j = 0; j < 3; j++) {
            int dir = (i + j) % 4;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                is_valid = false;
                break;
            }
            sum += board[nx][ny];
        }
        if (is_valid)
            answer = max(answer, sum);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = true;
            dfs(i, j, 1, board[i][j]);
            visited[i][j] = false;
            check_extra(i, j); // 특수모양 체크
        }
    }

    cout << answer << '\n';
    return 0;
}
