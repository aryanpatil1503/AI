

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;

void display()
{
    int n = grid.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j])
                cout << "Q ";
            else
                cout << "_ ";
        }
        cout << endl;
    }
}

bool is_safe(int r, int c)
{
    int n = grid.size();
    // queen in same row
    for (int i = 0; i < c; i++)
    {
        if (grid[r][i])
            return false;
    }
    // queen in same column
    for (int i = 0; i < r; i++)
    {
        if (grid[i][c])
            return false;
    }
    // left-right diagonal
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
    {
        if (grid[i][j])
            return false;
    }
    // rigth-left diagonal
    for (int i = r, j = c; i >= 0 && j < n; i--, j++)
    {
        if (grid[i][j])
            return false;
    }
    return true;
}

bool n_queen(vector<vector<int>> &grid, int row, int n)
{
    if (row >= n)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if (is_safe(row, i))
        {
            grid[row][i] = 1;
            if (n_queen(grid, row + 1, n))
                return true;
            grid[row][i] = 0;
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "\n\t Enter number of rows/columns in grid : ";
    cin >> n;

    grid.resize(n, vector<int>(n, 0));

    if (n_queen(grid, 0, n))
    {
        display();
    }
    else
    {
        cout << "\n\t No Solution Exists" << endl;
    }
}