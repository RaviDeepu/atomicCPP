#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size(), num = 0;
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    num++;
                    markIslands(grid, visited, i, j);
                }
            }
        }
        return num;
    }
private: 
    void markIslands(vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c) {
        visited[r][c] = true;
        int m = grid.size(), n = grid[0].size();
        if (r - 1 >= 0 && grid[r - 1][c] == '1' && !visited[r - 1][c])
            markIslands(grid, visited, r - 1, c);
        if (r + 1 < m && grid[r + 1][c] == '1' && !visited[r + 1][c])
            markIslands(grid, visited, r + 1, c);
        if (c - 1 >= 0 && grid[r][c - 1] == '1' && !visited[r][c - 1])
            markIslands(grid, visited, r, c - 1);
        if (c + 1 < n && grid[r][c + 1] == '1' && !visited[r][c + 1])
            markIslands(grid, visited, r, c + 1);
    }
};


int main()
{
    vector< vector<char> > gridVector;

    vector<char> row1={'1', '1', '0', '0', '0'};
    vector<char> row2={'0', '1', '0', '0', '1'};
    vector<char> row3={'1', '0', '0', '1', '1'};
    vector<char> row4={'0', '0', '0', '0', '0'};
    vector<char> row5={'1', '0', '1', '0', '1'};

    gridVector.push_back(row1);
    gridVector.push_back(row2);
    gridVector.push_back(row3);
    gridVector.push_back(row4);
    gridVector.push_back(row5);

    for(auto a:gridVector)
    {
        for(auto aa:a)
        {
            cout<<aa<<" ";
        }
        cout<<endl;
    }

    Solution s;
    cout<<s.numIslands(gridVector)<<endl;
}

