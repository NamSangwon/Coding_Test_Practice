#include <bits/stdc++.h>

using namespace std;

int main()
{
    // ※ 자료형의 범위 확인 必 
    unsigned long long r = 1;
    unsigned long long M = 1234567891;

    int L;
    cin >> L;

    unsigned long long hash = 0;
    for(int i = 0; i < L; i++)
    {
        char ch;
        cin >> ch;

        // 계산 실수 
		// (급수 계산 시, 값이 초과할 수 있기 때문에 mod 연산 必)
        hash = (hash + r * (ch - 'a' + 1)) % M;
        // (r을 i제곱하면서 값이 초과할 수 있기 때문에 mod 연산 必) 
        r = (r * 31) % M;
    }

    cout << hash << '\n';
}