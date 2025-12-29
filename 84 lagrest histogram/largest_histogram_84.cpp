class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(); // Fixed typo: 'hight' -> 'heights'
        stack<int> st;
        int maxArea = 0;
        
        // Loop up to n to handle the remaining elements in the stack at the end
        for (int i = 0; i <= n; i++) {
            
            // If i == n, we treat the height as 0 to force popping the remaining stack
            int currHeight = (i == n ? 0 : heights[i]);
            
            // While the current bar is shorter than the bar at stack top,
            // we calculate the area for the bar at stack top.
            while (!st.empty() && currHeight < heights[st.top()]) { // Fixed typo: 'Heights' -> 'heights'
                
                // 1. Get the height of the rectangle we are processing
                int h = heights[st.top()]; 
                
                // 2. Remove that index
                st.pop(); 
                
                // 3. Calculate width
                int width;
                if (st.empty()) {
                    width = i; // If stack is empty, it extends to the very left (index 0)
                } else {
                    width = i - st.top() - 1; // Width is between current index i and the new top of stack
                }
                
                // 4. Update maxArea using the 'h' variable we created earlier
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        
        return maxArea;
    }
};