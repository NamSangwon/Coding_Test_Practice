#include <bits/stdc++.h>

using namespace std;

int main()
{
    int rooms[15][15]; // (층, 호수)

    // 0층 & n층 1호 초기화
    for(int i = 1; i < 15; i++)
    {
        rooms[0][i] = i;
        rooms[i][1] = 1;
    }

    // 모든 층 & 호수 초기화
    for (int i = 1; i < 15; i++)
        for (int j = 2; j < 15; j++)
            rooms[i][j] = rooms[i-1][j] + rooms[i][j-1];

    int T;
    cin >> T;
    while(T--)
    {
        int k, n;
        cin >> k;
        cin >> n;

        cout << rooms[k][n] << '\n';
    }
}