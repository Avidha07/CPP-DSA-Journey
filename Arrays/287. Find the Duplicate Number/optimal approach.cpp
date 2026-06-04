class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow = nums[0];
        int fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while(slow != fast);

        fast = nums[0];  //again we have to intialize with fist element of array to the fast

        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
