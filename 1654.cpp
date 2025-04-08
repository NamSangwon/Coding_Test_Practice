#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 랜선의 길이는 231-1보다 작거나 같은 자연수
    // 따라서, 랜선의 길이를 저장하는 변수는 
    // 4Byte 이상의 크기를 가지는 데이터 타입을 사용한다.
    // int는 부호 크기를 제외한 2^31 크기를 지니기 떄문에 사용이 불가하다.
    // 사용 가능한 타입 : unsigned int 이상부터 가능
    int N, K;
    cin >> N >> K;

    vector<unsigned int> lines;
    unsigned int max = 0;
    for(int i = 0; i < N; i++)
    {
        unsigned int num;
        cin >> num;
        lines.push_back(num);
        max = (max < num) ? (num) : (max);
    }

    // 이분 탐색 사용 必
    // (한번에 떠올리지 못함. 주의하자!!)
    unsigned int answer = 0;
    unsigned int left = 1;
    unsigned int right = max;
    unsigned int mid = 0;
    while(left <= right)
    {
        mid = (right + left) / 2;

        unsigned int split_line_num = 0;
        for (auto line : lines)
        {
            split_line_num += line / mid;
        }

        if (split_line_num >= K)
        {
            left = mid + 1;
            answer = (answer > mid) ? (answer) : (mid);
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << answer << '\n';
}