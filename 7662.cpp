#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;

        int size = 0;
        map<int, int> m; // 삭제 여부를 판별하기 위한 맵
        priority_queue<int, vector<int>, less<int>> less_pq;
        priority_queue<int, vector<int>, greater<int>> greater_pq;
        for (int i = 0; i < N; i++) {
            char cmd;
            int num;
            cin >> cmd >> num;

            switch (cmd) {
                case 'I':
                    size++;
                    m[num]++;
                    less_pq.push(num);
                    greater_pq.push(num);
                    break;
                case 'D':
                    if (size <= 0) break;

                    // 동기화 작업은 삭제하고자 한 값이 이미 삭제된 경우, 삭제 반영
                    if (num > 0) { // 최대갓 삭제
                        size--;
                        while(m[less_pq.top()] < 1) less_pq.pop(); // 최솟값 삭제, 동기화
                        m[less_pq.top()]--; 
                        less_pq.pop();
                    }
                    else { // 최솟값 삭제
                        size--;
                        while(m[greater_pq.top()] < 1) greater_pq.pop(); // 최댓값 삭제, 동기화
                        m[greater_pq.top()]--; 
                        greater_pq.pop();
                    }
                    break;
            }
        }

        if (size <= 0) {
            cout << "EMPTY\n";
            continue;
        }
        else {
            // 두 pq의 동기화 작업
            while(m[less_pq.top()] < 1) less_pq.pop();
            while(m[greater_pq.top()] < 1) greater_pq.pop(); 
            cout << less_pq.top() << ' ' << greater_pq.top() << '\n';
        }
    }
}