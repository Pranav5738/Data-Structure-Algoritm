class Solution {
public:
    int firstPos(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1, ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                ans = mid;
                high = mid - 1;   // go left
            }
            else if (arr[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return ans;
    }

    int lastPos(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1, ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                ans = mid;
                low = mid + 1;   // go right
            }
            else if (arr[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return ans;
    }

    int countOccurrences(vector<int>& arr, int target) {
        int first = firstPos(arr, target);
        if (first == -1) return 0;   // target not found

        int last = lastPos(arr, target);
        return last - first + 1;
    }
};
