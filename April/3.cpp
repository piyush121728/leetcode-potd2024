#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> vis;
    int n, m, l;
    bool search(int i, int j, vector<vector<char>> &board, string word, int k)
    {
        vis[i][j] = 1;
        if (k == l - 1)
        {
            return true;
        }

        for (int d = 0; d < 4; d++)
        {
            int nr = i + dir[d].first, nc = j + dir[d].second;
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && board[nr][nc] == word[k + 1])
            {
                if (search(nr, nc, board, word, k + 1))
                {
                    return true;
                }
            }
        }
        vis[i][j] = 0;
        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        n = board.size(), m = board[0].size(), l = word.size();
        vis.clear();
        vis.resize(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0])
                {
                    cout << i << " " << j << endl;
                    if (search(i, j, board, word, 0))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};