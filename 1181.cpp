#include <bits/stdc++.h>

using namespace std;

bool compare(const string &a, const string &b)
{
    // compare alphabet (such as dictionary)
    if (a.length() == b.length())
        return a < b;
        
    // compare length
    return a.length() < b.length();
}

int main()
{
    // 1. 메모리 공간이 충분하기 떄문에 map을 통해 중복 체크
    unordered_map<string, bool> word_exist;
    vector<string> words;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        if (word_exist[str] == false)
        {
            words.push_back(str);
            word_exist[str] = true;
        }
    }

    sort(words.begin(), words.end(), compare);

    // 2. 출력 시에 map 대신
    // 중복 출력 여부를 확인하도록 함
    string prev = "";
    for (auto word : words)
    {
        if (prev == word)
            continue;
        cout << word << '\n';
        prev = word;
    }
}
