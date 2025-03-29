#include <bits/stdc++.h>

using namespace std;

int main()
{
    int result = 0;

    string str;
    getline(cin, str);

    // // {Separate String to Token}
    // // Using by [StringStream]
    // istringstream ss(str);
    // string token;
    // while(getline(ss, token, ' '))
    //     if (!token.empty()) ++result; 

    // {Count space character with condition}
    // Using by only [String]
    // First character is not ' '  =>  Count First Word
    if (str[0] != ' ') 
        ++result;

    // Count Space Character
    //  => Number of Space Character == Number of Word
    for (int i = 0; i < str.length(); i++)
        if (str[i] == ' ') 
            ++result;

    // Last Character is ' ' => Over Count.
	if (str[str.length() - 1] == ' ') --result;
 
    cout << result << '\n';
}