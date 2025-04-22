#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b)
{
    if (b == 0)
        return a;

    return GCD(b, a % b);
}

int LCM(int a, int b)
{
    return (a * b / GCD(a, b));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        // [중국인의 나머지 정리]를 이용한 문제 풀이도 가능
        int M, N, x, y;
        cin >> M >> N >> x >> y;

        // ※ 문제 파악 실수
        // 최대 N과 M의 최소공배수까지 가능
        // (최대 40000 x 39999 = 1599960000까지 가능함)
        int max_num = LCM(M, N);

        int answer = -1;
        // x와 y를 분리해서 for문을 돌리면 시간 초과 발생 (최대 약 30억번 내외의 연산)
        // [ (x + M) / N == y ]의 성질을 이용하여 한 번의 for문만 진행하도록 함
        for(int i = x; i <= max_num; i = i + M)
        {
            // (x + M) / N == y
            if ((i - 1) % N + 1 == y)
            {
                answer = i;
                break;
            }
        }

        cout << answer << '\n';
    }
}