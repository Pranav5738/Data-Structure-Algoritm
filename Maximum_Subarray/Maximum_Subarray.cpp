class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxSoFar = nums[0];
        int minSoFar = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i];

            // If current number is negative, swap max and min
            if (x < 0) {
                swap(maxSoFar, minSoFar);
            }

            maxSoFar = max(x, maxSoFar * x);
            minSoFar = min(x, minSoFar * x);

            result = max(result, maxSoFar);
        }

        return result;
    }
};
