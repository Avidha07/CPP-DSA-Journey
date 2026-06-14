class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();

        int maxArea = 0;

        for(int i =0; i<n-1; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                int minHeight = min(height[i] , height[j]);
                int dist = j-i;
                int area = minHeight*dist;
                maxArea = max(area ,  maxArea);
            }
        }
        return maxArea;
    }
};
