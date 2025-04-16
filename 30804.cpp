#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> board(N);
    for (int i = 0; i < N; i++) cin >> board[i];

    // ★★★ Two Pointer Algorithm ★★★
    // ※ 과일의 종류가 2 이하면, 오른쪽을 옮겨서 길이를 늘리고
    // ※ 과일의 종류가 2를 초과하면, 왼쪽을 옮겨서 길이를 줄인다
    int fruit_type_cnt = 1;
    int answer = 0;
    int left = 0, right = 0;
    vector<int> num_count(10, 0);
    num_count[board[0]]++;
    while(right < N)
    {
        // ※ 과일의 종류가 2를 초과하면, 왼쪽을 옮겨서 길이를 줄인다
        if (fruit_type_cnt > 2)
        {
            // 탕후루 내의 해당 타입 과일(1 ~ 9) 개수 감소
            num_count[board[left]]--;

            // 탕후루 내의 과일 종류 업데이트
            if (num_count[board[left]] == 0)
                fruit_type_cnt--;

            // 포인터 이동
            left++;
        }
        // ※ 과일의 종류가 2 이하면, 오른쪽을 옮겨서 길이를 늘리고
        else
        {
            // 결과를 위한 최댓값 업데이트
            answer = max(answer, right-left+1);

            // 포인터 이동
            right++;

            // 탕후루 내의 과일 종류 업데이트
            if (num_count[board[right]] == 0)
                fruit_type_cnt++;

            // 탕후루 내의 해당 타입 과일(1 ~ 9) 개수 증가
            num_count[board[right]]++;
        }
    }

    cout << answer << '\n';
}