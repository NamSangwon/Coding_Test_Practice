#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int64_t A, B;
    cin >> A >> B;

    unordered_map<int64_t, bool> visited;

    queue<pair<int64_t, int>> q;
    q.push({A, 1});
    while(!q.empty()) {
        pair<int64_t, int> curr = q.front();
        q.pop();

        if (visited[curr.first]) continue;
        if (curr.first > B) continue;

        if (curr.first == B) {
            cout << curr.second << '\n';
            return 0;
        }

        visited[curr.first] = true;
        q.push({curr.first * 2, curr.second + 1});
        q.push({curr.first * 10 + 1, curr.second + 1});
    }

    cout << -1 << '\n';
}