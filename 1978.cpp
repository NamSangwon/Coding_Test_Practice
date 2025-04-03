#include <bits/stdc++.h>

using namespace std;

bool IsPrime(int n)
{
    if (n <= 1) return false;

    for(int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) 
            return false;

    return true;
}

int main()
{
    int N;
    cin >> N;

    int result = 0;

    // 소수 판별 (최대 100 * 1,000 만큼 수행되므로 반복문을 사용해도 무관)
    // 1. 2 ~ (n-1) 까지 나누어 떨어지는 수 찾기 (O(N))
    // 2. 제곱근을 통한 중복 계산 제거 후 찾기 (O(sqrt(N))
    // 3. 에라토스테네스의 체 (배수 제거) (O(N*log(logN)))
    // 참고 : https://khu98.tistory.com/227
    // 개선 알고리즘 = (제곱근을 통한 중복 계산 제거)
    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if (IsPrime(num))
            result++;
    }

    cout << result << '\n';
}