#include <bits/stdc++.h>
using namespace std;

/*
================================================================================
PROBLEM STATEMENT:
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0.
You must do it in place.

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
================================================================================
*/

// HELPER FUNCTION FOR BRUTE FORCE
void markRow(vector<vector<int>> &matrix, int n, int m, int i)
{
    // set all non-0 elements to -1 (marker)
    for (int j = 0; j < m; j++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

void markCol(vector<vector<int>> &matrix, int n, int m, int j)
{
    // set all non-0 elements to -1 (marker)
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

// ==========================================
// BRUTE FORCE
// Logic: Iterate over matrix. If we find a 0, mark that entire row and col with -1.
// We use -1 so we don't confuse a "new" 0 with an "original" 0.
// Finally, change all -1s to 0s.
// Note: Only works if matrix contains only positive numbers (or if -1 is not a valid data input).
// TC: O((N*M) * (N+M)) -> Very slow because for every 0, we traverse row/col. ~O(n^3)
// SC: O(1)
// ==========================================
void setZeroesBrute(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

// ==========================================
// BETTER APPROACH
// Logic: Use two separate arrays (rowArray and colArray) to keep track of which
// rows and columns need to be zeroed.
// TC: O(2 * N*M) -> O(N*M)  ~O(n^2) whichb is the least we could do for a matrix so we tryna remove the extra space used
// SC: O(N) + O(M) -> Extra space used.
// ==========================================
void setZeroesBetter(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> rowArray(n, 0);
    vector<int> colArray(m, 0);

    // Step 1: Mark the arrays
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                rowArray[i] = 1;
                colArray[j] = 1;
            }
        }
    }

    // Step 2: Set matrix entries to 0 based on arrays
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (rowArray[i] == 1 || colArray[j] == 1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

// ==========================================
// OPTIMAL APPROACH
// Logic: Instead of external arrays, use the First Row and First Col OF THE MATRIX
// as the "checklists". Use a variable col0 for the 0th column conflict.
// TC: O(2 * N*M) -> O(N*M)
// SC: O(1) -> No extra space.
// ==========================================
void setZeroesOptimal(vector<vector<int>> &matrix)
{
    int n = matrix.size();    // rows
    int m = matrix[0].size(); // cols
    int col0 = 1;

    // Step 1: Traverse and Mark
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0; // Mark Row Header

                if (j != 0)
                    matrix[0][j] = 0; // Mark Col Header
                else
                    col0 = 0; // Mark special Col0 variable
            }
        }
    }

    // Step 2: Mark inner matrix (1 to n-1, 1 to m-1)
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // Step 3: Handle Row 0 (Limit: m/Width)
    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < m; j++)
            matrix[0][j] = 0;
    }

    // Step 4: Handle Col 0 (Limit: n/Height)
    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
            matrix[i][0] = 0;
    }
}

int main()
{
    // Example Input
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};

    cout << "Original Matrix: " << endl;
    for (auto row : matrix)
    {
        for (auto ele : row)
            cout << ele << " ";
        cout << endl;
    }

    // Call the function (Uncomment the one you want to test)
    // setZeroesBrute(matrix);
    // setZeroesBetter(matrix);
    setZeroesOptimal(matrix);

    cout << "\nResult Matrix: " << endl;
    for (auto row : matrix)
    {
        for (auto ele : row)
            cout << ele << " ";
        cout << endl;
    }

    return 0;
}