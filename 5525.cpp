#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    int N, S;
    cin >> N >> S >> input;

    // P_1 & P_2 ~ P_N
    string P = "IOI"; 
    for (int i = 2; i <= N; i++) P += "OI";

    int answer = 0;
    // 시간 복잡도 제한 有 (50점 정답)
    for (int i = 0; i <= S - P.length(); i++)
    {
        string sub_str = input.substr(i, P.length());
        
        if (sub_str == P)
            answer++;
    }

    // 중복 계산 줄이기 ("IOI"의 개수 비교를 통해)
    for (int i = 0; i < m; i++) {
		
		int k = 0; //IOI의 개수
		if (str[i] == 'O') continue;

		while (str[i + 1] == 'O' && str[i + 2] == 'I') {
			k++;

            // [핵심] 오른쪽으로 +2만큼 이동할텐데 이때 k값이 바뀌지 않게 하나 빼줌
			if (k == n) {
				answer++;
				k--; 
			}

            // 인덱스 뛰어 넘기
			i += 2;
		}
	}

    cout << answer << '\n';
}