#include <bits/stdc++.h>

using namespace std;

int main()
{
    // 다음 코드를 통한 입출력 최적화
    // 입출력 최적화를 하지 않았을 때는 오답이었지만,
    // 해당 코드를 추가하니 정답이었다.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    unordered_map<int, bool> inputs;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        inputs[num] = true;
    }

    cin >> M;
    for(int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        cout << int(inputs.find(num) != inputs.end()) << '\n';
    }
}