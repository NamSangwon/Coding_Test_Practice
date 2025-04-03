#include <bits/stdc++.h>

using namespace std;

enum COLOR { WHITE, BLACK };
char BOARD_COLOR[2] = { 'W', 'B' };

int main()
{
    int N, M;
    vector<string> board;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string line;
        cin >> line;
        board.push_back(line);
    }

    int result = INT_MAX;
    for(int row = 0; row <= N-8; row++)
    {
        for (int col = 0; col <= M-8; col++)
        {
            int main_white_result = 0;
            int main_black_result = 0;

            for(int i = row; i < row + 8; i++)
            {
                for (int j = col; j < col + 8; j++)
                {
                    if (i % 2 == 0 && ((j % 2 == 0 && board[i][j] != BOARD_COLOR[WHITE] || (j % 2 == 1 && board[i][j] == BOARD_COLOR[WHITE]))) 
                     || (i % 2 == 1 && ((j % 2 == 0 && board[i][j] == BOARD_COLOR[WHITE]) || (j % 2 == 1 && board[i][j] != BOARD_COLOR[WHITE]))))
                        main_white_result++;
        
                    else if (i % 2 == 0 && ((j % 2 == 0 && board[i][j] != BOARD_COLOR[BLACK] || (j % 2 == 1 && board[i][j] == BOARD_COLOR[BLACK]))) 
                    || (i % 2 == 1 && ((j % 2 == 0 && board[i][j] == BOARD_COLOR[BLACK]) || (j % 2 == 1 && board[i][j] != BOARD_COLOR[BLACK]))))
                        main_black_result++;
                }
            }
            
            int min = (main_white_result < main_black_result) ? (main_white_result) : (main_black_result);
            result = (result < min) ? (result) : (min);
        }
    }

    cout << result << '\n';
}