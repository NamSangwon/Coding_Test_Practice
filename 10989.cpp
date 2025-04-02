#include <bits/stdc++.h>

using namespace std;

int main()
{
    // [메모리 초과]를 고려해야하는 문제!!
    int nums[10001] = {0,};

    int N;
    cin >> N;

    // 계수 정렬 사용
    for (int i = 0; i < N; i++)
    {
        short num;
        cin >> num;
        nums[num]++;
    }

    for (int i = 0; i < 10001; i++)
    {
        for (int j = 0; j < nums[i]; j++)
            cout << i << '\n';
    }
}