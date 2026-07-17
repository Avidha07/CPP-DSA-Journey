class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int i =0; int j =0;
        int cnt = 0;
        string str = "";
        int mini = INT_MAX;


        while(j<n)
        {
            str+=blocks[j];
            if(j-i+1 == k)
            {
                for(int p =0; p<k; p++)
                {
                    if(str[p] == 'W'){
                        cnt++;
                    }
                }
                mini = min(mini , cnt);
                str.erase(0,1);
                i++;
            }
            cnt = 0;
            j++;
            
        }
        return mini;
    }
};
