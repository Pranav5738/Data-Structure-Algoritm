#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int longestConsequtive(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;

    unordered_set<int> s(arr.begin(), arr.end());
    int longest = 1;

    for (auto it : s) {

        // check if it's the start of a sequence
        if (s.find(it - 1) == s.end()) {
            int x = it;
            int cnt = 1;

            // count forward
            while (s.find(x + 1) != s.end()) {
                x++;
                cnt++;
            }

            longest = max(longest, cnt);
        }
    }

    return longest;
}

int main() {
    vector<int> arr = {100, 4, 200, 1, 3, 2};
    cout << "Length of longest consecutive elements sequence: "
         << longestConsequtive(arr) << endl;
    return 0;
}
