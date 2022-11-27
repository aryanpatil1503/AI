

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;
vector<bool> col;
vector<bool> lrdiag;
vector<bool> rldiag;

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

bool is_safe(int r, int c, int n)
{
    if (lrdiag[r - c + n - 1] || rldiag[r + c] || col[c])
        return false;
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
        if (is_safe(row, i, n))
        {
            lrdiag[row - i + n - 1] = true;
            rldiag[row + i] = true;
            col[i] = true;
            grid[row][i] = 1;

            if (n_queen(grid, row + 1, n))
                return true;

            lrdiag[row - i + n - 1] = false;
            rldiag[row + i] = false;
            col[i] = false;
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
    col.resize(n, false);
    lrdiag.resize(2 * n - 1, false);
    rldiag.resize(2 * n - 1, false);

    if (n_queen(grid, 0, n))
    {
        display();
    }
    else
    {
        cout << "\n\t No Solution Exists" << endl;
    }
}