#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b;
    while(true) 
    {
        // ※ cin이 아닌 scanf를 사용하여 입력 예제의 끝을 판별하여 종료하도록 함
        if(scanf("%d %d", &a, &b) == EOF) break;
        
        printf("%d\n", a+b);
    }
}