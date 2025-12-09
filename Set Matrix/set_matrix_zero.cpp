#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    int col0 = 1;  // flag for first column

    // Step 1: Mark rows & columns
    for (int i = 0; i < n; i++) {
        if (matrix[i][0] == 0)
            col0 = 0;

        for (int j = 1; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;  // mark row
                matrix[0][j] = 0;  // mark column
            }
        }
    }

    // Step 2: Use marks to set cells to zero (except first row & first column)
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Step 3: If first row should be zero
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }

    // Step 4: If first column should be zero
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> result = zeroMatrix(matrix, n, m);

    for (const auto &row : result) {
        for (const auto &val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}