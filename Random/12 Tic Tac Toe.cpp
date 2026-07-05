// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/description/
// 0174 (Easy)- Tic Tac Toe

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool pending(vector<vector<char>> &moves)
    {
        for (auto move : moves)
        {
            for (auto ele : move)
            {
                if (ele == ' ')
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool xWinning(vector<vector<char>> &moves)
    {
        if (moves[0][0] == 'X' && moves[0][1] == 'X' && moves[0][2] == 'X')
        {
            return true;
        }
        else if (moves[1][0] == 'X' && moves[1][1] == 'X' && moves[1][2] == 'X')
        {
            return true;
        }
        else if (moves[2][0] == 'X' && moves[2][1] == 'X' && moves[2][2] == 'X')
        {
            return true;
        }
        else if (moves[0][0] == 'X' && moves[1][0] == 'X' && moves[2][0] == 'X')
        {
            return true;
        }
        else if (moves[0][1] == 'X' && moves[1][1] == 'X' && moves[2][1] == 'X')
        {
            return true;
        }
        else if (moves[0][2] == 'X' && moves[1][2] == 'X' && moves[2][2] == 'X')
        {
            return true;
        }
        else if (moves[0][0] == 'X' && moves[1][1] == 'X' && moves[2][2] == 'X')
        {
            return true;
        }
        else if (moves[0][2] == 'X' && moves[1][1] == 'X' && moves[2][0] == 'X')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool oWinning(vector<vector<char>> &moves)
    {
        if (moves[0][0] == 'O' && moves[0][1] == 'O' && moves[0][2] == 'O')
        {
            return true;
        }
        else if (moves[1][0] == 'O' && moves[1][1] == 'O' && moves[1][2] == 'O')
        {
            return true;
        }
        else if (moves[2][0] == 'O' && moves[2][1] == 'O' && moves[2][2] == 'O')
        {
            return true;
        }
        else if (moves[0][0] == 'O' && moves[1][0] == 'O' && moves[2][0] == 'O')
        {
            return true;
        }
        else if (moves[0][1] == 'O' && moves[1][1] == 'O' && moves[2][1] == 'O')
        {
            return true;
        }
        else if (moves[0][2] == 'O' && moves[1][2] == 'O' && moves[2][2] == 'O')
        {
            return true;
        }
        else if (moves[0][0] == 'O' && moves[1][1] == 'O' && moves[2][2] == 'O')
        {
            return true;
        }
        else if (moves[0][2] == 'O' && moves[1][1] == 'O' && moves[2][0] == 'O')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void fillMoves(vector<vector<int>> &movesInInt, vector<vector<char>> &moves)
    {
        for (int i = 0; i < 3; i++)
        {
            vector<char> temp(3);
            for (int j = 0; j < 3; j++)
            {
                temp[j] = ' ';
            }
            moves.push_back(temp);
        }
        int count = 0;
        for (auto move : movesInInt)
        {
            if (count % 2 == 0)
            {
                moves[move[0]][move[1]] = 'X';
            }
            else
            {
                moves[move[0]][move[1]] = 'O';
            }
            count++;
        }
    }
    string tictactoe(vector<vector<int>> &movesInInt)
    {
        // Winning
        // loosenig
        // draw
        vector<vector<char>> moves;
        fillMoves(movesInInt, moves);
        if (xWinning(moves))
        {
            return "A";
        }
        if (oWinning(moves))
        {
            return "B";
        }
        if (pending(moves))
        {
            return "Pending";
        }

        return "Draw";
    }
};

int main()
{
    vector<vector<int>> moves = {{'X', ' ', ' '}, {' ', 'X', ' '}, {'O', 'O', 'X'}};
    Solution s;
    cout << s.tictactoe(moves) << endl;

    return 0;
}
