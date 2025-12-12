class Solution {
public:
    vector<int> generateRow(int row) {
        long long val = 1;
        vector<int> r;
        r.push_back(1);  // Every row starts with 1

        for (int col = 1; col < row; col++) {
            val = val * (row - col) / col;  // C(n, k) = C(n, k-1) * (n-k) / k
            r.push_back(val);
        }
        return r;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++) {
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};
