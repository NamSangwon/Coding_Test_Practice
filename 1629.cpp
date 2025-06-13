#include <bits/stdc++.h>

using namespace std;

uint64_t A, B, C;

uint64_t solve(uint64_t b) {
    if (b == 0) return 1;
    if (b == 1) return A % C;

    // [중복 출력 제거]
    // 중복 호출을 한 번의 호출로 처리하고, 그 값을 기억
    uint64_t tmp = solve(b / 2);
    tmp = tmp * tmp % C;

    // 짝수 계산 시, 종료
    if (b % 2 == 0) {
        return tmp;
    }
    // 홀수 개 계산 시, 한 번 더 연산
    else {
        return tmp * A % C;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C;

    cout << solve(B) << '\n';
}