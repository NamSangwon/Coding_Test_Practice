#include <bits/stdc++.h>

using namespace std;

// 숫자를 왼쪽으로 한 칸 쉬프트하는 함수 (예: 1234 -> 2341)
int shift_L(int num) {
    int left_num = num / 1000;      // 천의 자리 숫자
    int right_nums = num % 1000;    // 나머지 세 자리 숫자

    return (right_nums * 10 + left_num); // 나머지 숫자에 10을 곱하고 천의 자리를 더함
}

// 숫자를 오른쪽으로 한 칸 쉬프트하는 함수 (예: 1234 -> 4123)
int shift_R(int num) {
    int right_num = num % 10;       // 일의 자리 숫자
    int left_nums = num / 10;       // 나머지 세 자리 숫자

    return right_num * 1000 + left_nums; // 일의 자리를 천의 자리로 옮기고 나머지를 뒤에 붙임
}

int main() {
    // C++ 표준 스트림과 C 표준 스트림의 동기화를 해제하여 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    // cin과 cout의 묶음을 해제하여 입력/출력 버퍼를 비동기화, 속도 향상
    cin.tie(NULL);
    cout.tie(NULL);

    int T; // 테스트 케이스의 수
    cin >> T;
    while(T--) {
        int start, end; // 시작 숫자와 목표 숫자
        cin >> start >> end;

        // log_num[i] = i에 도달하기 전의 숫자 (부모 노드)
        // -1: 아직 방문하지 않음
        // -2: 시작 노드 (경로 추적의 끝을 나타내기 위함)
        vector<int> log_num(10000, -1); // 0부터 9999까지 사용
        // log_char[i] = i에 도달하기 위해 사용한 연산 문자
        vector<char> log_char(10000);

        queue<int> q; // BFS를 위한 큐, 숫자만 저장

        // **중요:** 큐에 넣기 전에 방문 처리
        log_num[start] = -2; // 시작 노드의 부모를 -2로 설정하여 경로 추적의 끝을 표시
        q.push(start);

        // BFS 탐색
        while(!q.empty()) {
            int curr = q.front(); // 현재 탐색 중인 숫자
            q.pop();

            // 목표 숫자에 도달하면 경로 재구성 후 탐색 종료
            if (curr == end) {
                string answer_path = ""; // 최종 경로를 문자열로 저장
                int trace_num = end;

                // 시작 노드(-2)에 도달할 때까지 역추적
                while(log_num[trace_num] != -2) {
                    answer_path += log_char[trace_num]; // 사용된 연산 문자 추가
                    trace_num = log_num[trace_num];     // 부모 노드로 이동
                }
                
                // 역순으로 저장된 경로를 뒤집어서 출력
                reverse(answer_path.begin(), answer_path.end());
                cout << answer_path << '\n';
                break; // 목표에 도달했으므로 현재 테스트 케이스 탐색 종료
            }

            // D 연산 (2 * n)
            int next_num_D = (2 * curr) % 10000;
            // **중요:** 아직 방문하지 않았다면 (log_num이 -1이라면)
            if (log_num[next_num_D] == -1) {
                log_num[next_num_D] = curr;     // 현재 숫자를 부모로 저장
                log_char[next_num_D] = 'D';     // 사용된 연산 기록
                q.push(next_num_D);             // 큐에 추가
            }

            // S 연산 (n - 1)
            // 음수 방지를 위해 10000을 더하고 10000으로 나눈 나머지 계산
            int next_num_S = (curr - 1 + 10000) % 10000;
            if (log_num[next_num_S] == -1) {
                log_num[next_num_S] = curr;
                log_char[next_num_S] = 'S';
                q.push(next_num_S);
            }

            // L 연산 (shift_L)
            int next_num_L = shift_L(curr);
            if (log_num[next_num_L] == -1) {
                log_num[next_num_L] = curr;
                log_char[next_num_L] = 'L';
                q.push(next_num_L);
            }

            // R 연산 (shift_R)
            int next_num_R = shift_R(curr);
            if (log_num[next_num_R] == -1) {
                log_num[next_num_R] = curr;
                log_char[next_num_R] = 'R';
                q.push(next_num_R);
            }
        }
    }
    return 0;
}