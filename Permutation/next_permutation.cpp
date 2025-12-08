#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void nextGreaterPermutation(vector<int> &A) {
    int n = A.size();
    int ind = -1;

    // Step 1: find the first index from the right where A[i] < A[i+1]
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            ind = i;
            break;
        }
    }

    // If no such index found, array is in descending order -> reverse it
    if (ind == -1) {
        reverse(A.begin(), A.end());
        return;
    }

    // Step 2: find the element just larger than A[ind] to the right
    for (int i = n - 1; i > ind; i--) {
        if (A[i] > A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }

    // Step 3: reverse the suffix
    reverse(A.begin() + ind + 1, A.end());
}

// Simple main to test the function
int main() {
    vector<int> a = {1, 2, 3};
    nextGreaterPermutation(a);      // modifies 'a' in-place
    for (int x : a) {
        cout << x << " ";
    }
    return 0;
}
