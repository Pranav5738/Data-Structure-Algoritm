class Solution {
public:
    int findFirst(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) /2;

            if (nums[mid] == target) {
                ans = mid;
                high = mid - 1;   // move left
            }
            else if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return ans;
    }

    int findLast(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                ans = mid;
                low = mid + 1;   // move right
            }
            else if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        if (first == -1) return {-1, -1};

        int last = findLast(nums, target);
        return {first, last};
    }
};



//upper and lower bound approach

#include <bits/stdc++.h>
using namespace std;

int lowerBound(const vector<int> &arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int upperBound(const vector<int> &arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

pair<int,int> firstAndLastPosition(const vector<int> &arr, int k) {
    int lb = lowerBound(arr, k);

    if (lb == arr.size() || arr[lb] != k)
        return {-1, -1};

    int ub = upperBound(arr, k);

    return {lb, ub - 1};
}
