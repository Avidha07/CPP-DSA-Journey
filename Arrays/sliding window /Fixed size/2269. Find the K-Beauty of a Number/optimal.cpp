class Solution {
public:
    int divisorSubstrings(int num, int k) {
        
        string str = to_string(num);
        int n = str.length();
        int cnt =0;
        int i =0; int j =0;
        string s = "";
        while(j<n)
        {
             s += str[j];
            if(j-i+1 == k)
            {   
                int digit = stoi(s);
                if( digit != 0 && num%digit == 0)
                {
                    cnt++;
                }
                s.erase(0,1);
                i++;
                
            }
            j++;
        }
        return cnt;
    }
};
