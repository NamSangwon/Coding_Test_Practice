#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;

    for (int num = 1; num < N; num++)
    {
        string str_num = to_string(num);

        int sum = num;
        for (int i = 0; i < str_num.size(); i++)
            sum += str_num[i] - '0';

        if (sum == N) 
        {
            cout << num;
            return 0;
        }
    }

    cout << 0;
}

// to_string() 대신 자릿수 계산하는 것이 시간이 더 짧음
// int main()
// {
// 	int N;
// 	cin >> N;
// 	int M = 1;
// 	while (1)
// 	{
// 		int sum = M;
// 		int num = M;
// 		while (num > 0)
// 		{
// 			sum += num % 10;
// 			num /= 10;
// 		}
// 		if (sum == N)
// 		{
// 			cout << M;
// 			break;
// 		}
// 		else if (M >= N)
// 		{
// 			cout << 0;
// 			break;
// 		}
// 		M++;
// 	}
// 	return 0;
// }