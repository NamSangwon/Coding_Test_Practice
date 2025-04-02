#include <bits/stdc++.h>

using namespace std;

int main()
{
    // [메모리 초과]를 고려해야하는 문제!!
    // 숫자 입력 갯수 (N) : 10,000,000개 => 자료형 int
    // 입력 받는 숫자 : 10,000 이하의 자연수 => 자료형 short
    int nums[10001] = {0,};

    int N;
    cin >> N;

    // Counting Sort 사용
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