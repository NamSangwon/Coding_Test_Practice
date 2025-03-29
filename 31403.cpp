#include <bits/stdc++.h>

using namespace std;

int main()
{
    // 줄바꿈을 포함하여 값을 입력 받을 시, buffer에 유의
    // cin >> num[0] >> num[1] >> num[2]와 같이 작성할 시, 오류 발생
    int num[3];
    for (int i = 0; i < 3; i++) 
        cin >> num[i];

    // A, B, C를 수로 생각할 시
    cout << num[0] + num[1] - num[2] << endl;
    
    // A, B, C를 문자열로 생각할 시
    string str = to_string(num[0]) + to_string(num[1]);
    cout << stoi(str) - num[2] << '\n';
}