class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nextGreater;
        stack<int> st;

        for(int num : nums2){
            while(!st.empty()&& num> st.top()){
                nextGreater[st.top()]=num;
                st.pop();
            }
            st.push(num);
        }
        while (!st.empty()){
            nextGreater[st.top()] = -1;
            st.pop();
        }
        vector<int> result;
        for(int num : nums1){
            result.push_back(nextGreater[num]);
        }
        return result;
    }
};


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater; // value -> next greater
        stack<int> st;                       // monotonic decreasing stack
        
        for (int num : nums2) {
            // While current num is greater than stack top,
            // it is the "next greater" for that element.
            while (!st.empty() && num > st.top()) {
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        // Remaining elements in stack have no greater element
        while (!st.empty()) {
            nextGreater[st.top()] = -1;
            st.pop();
        }

        // Build result for nums1 using the map
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreater[num]);
        }
        return result;
    }
};
