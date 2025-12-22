class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();
        vector<vector<int>> ans;

        // IMPORTANT: sort first
        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < n; i++) {

            // If ans is empty OR no overlap
            if (ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);
            }
            // Overlapping case
            else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
    }
};
