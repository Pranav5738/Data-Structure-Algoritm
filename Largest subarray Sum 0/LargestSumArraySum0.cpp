class Solution {
public:
    int maxLen(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sum = 0;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            // If sum becomes zero
            if (sum == 0) {
                maxLen = i + 1;
            }

            // If sum already exists
            if (mp.find(sum) != mp.end()) {
                maxLen = max(maxLen, i - mp[sum]);
            }
            // Store first occurrence
            else {
                mp[sum] = i;
            }
        }
        return maxLen;
    }
};
