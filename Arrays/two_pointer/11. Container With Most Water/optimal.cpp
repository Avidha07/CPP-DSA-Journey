11. Container With Most Water

class Solution {
public:
    int maxArea(vector<int>& height) {

       int n = height.size();
       int i = 0;
       int j =n-1;

       int area = 0;
       int maxArea = 0;

       while(i<j)
       {
         area = min(height[i] , height[j]) * (j-i);
         maxArea = max(maxArea , area);

         if(height[i] < height[j])
         {
            i++;
         }
         else{
            j--;
         }

       }
       return maxArea;

    }
};
