#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, B;
    cin >> N >> M >> B;

    int board[501][501] = {0,};
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    }

    // ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
    // [500 * 500 * 257 < 75,000,000] 이므로 C++로 1초 안에 충분히 가능하다.
    // 시간복잡도를 가볍게 여기지 말고 확인해보자
    // ★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★

    // 최종 높이를 0 ~ 256까지 모두 확인하기
    int min_time = INT_MAX;
    int result_height = 0;
    for (int h = 0; h <= 256; h++)
    {
        int build_cnt = 0;
        int remove_cnt = 0;

        // 쌓아야 할 블럭 개수 & 지워야 할 블럭 개수 계산
        for(int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                int height = board[i][j] - h;
				if (height > 0) remove_cnt += height;
				else if (height < 0) build_cnt -= height;
            }
        }

        // 블럭 개수가 충분하다면, 시간 계산
        if (remove_cnt + B >= build_cnt)
        {
            int time = remove_cnt * 2 + build_cnt;
            if (min_time >= time)
            {
                min_time = time;
                result_height = h;
            }  
        }
    }

    cout << min_time << ' ' << result_height << '\n';
}