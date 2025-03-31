#include <bits/stdc++.h>

using namespace std;

// 유클리드 호제법 (gcd(a, b) = gcd(b, a%b))
int GCD(int a, int b)
{
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main()
{
    int a, b;
    cin >> a >> b;

    // [최대 공약수 (GCD)]
    // 1. Bruteforce - O(N) [생략]
    // 2. 유클리드 호제법 (gcd(a, b) = gcd(b, a%b))
    int gcd = GCD(a, b);

    // [최소 공배수 (LCM)]
    // 공식 : 두 수의 곱 / 최대 공약수
    int lsm = a * b / gcd;

    printf("%d\n%d\n", gcd, lsm);
}