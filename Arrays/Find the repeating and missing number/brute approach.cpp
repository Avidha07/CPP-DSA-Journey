Find the repeating and missing number

class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
  int reapting = -1 , missing =-1;

  for(int i = 1; i<=nums.size(); i++){

    int cnt =0;
    for(int j =0;j<nums.size(); j++){
        if(nums[j] == i)
        {
            cnt++;
        }

        
    }
    if(cnt == 2) reapting = i;
        else if(cnt == 0) missing  = i;
        if(reapting != -1 && missing != -1)
        {
            break;
        }
  }

  return {reapting , missing};
    }
};
