#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;

    while(T--) {
        string commands;
        cin >> commands;

        int N;
        cin >> N;

        string inputs;
        cin >> inputs;

        // deque를 사용한 pop_front(), pop_back() 사용
        deque<int> nums;
        string num = "";
        for (char ch : inputs) {
            if (isdigit(ch)) {
                num += ch;
            } else if (!num.empty()) {
                nums.push_back(stoi(num));
                num = "";
            }
        }

        bool isReverse = false; // 이를 통해 reverse() 연산 제거하여, 시간 초과 해결
        string result = "";
        for (char command : commands) {
            if (!result.empty()) break;

            switch (command) {
                case 'R':
                    isReverse = !isReverse;
                    break;
                case 'D':
                    if (nums.empty()) {
                        result += "error\n";
                        break;
                    }
                    else {
                        if (isReverse) 
                            nums.pop_back();
                        else
                            nums.pop_front();
                    }
                    
                    break;
            }
        }

        if (result.empty()) {
            // 마지막 출력 전, reverse 여부 판단 후 연산 진행
            if (isReverse) 
                reverse(nums.begin(), nums.end());

            result = '[';
            for (int i = 0; i < nums.size(); i++) {
                result += to_string(nums[i]);
                if (i + 1 < nums.size()) result += ',';
            }
            result += "]\n";
        }

        cout << result;
    }
}

