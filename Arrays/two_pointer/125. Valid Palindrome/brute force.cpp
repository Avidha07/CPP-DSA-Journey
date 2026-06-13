class Solution {
public:
    bool isPalindrome(string s) {
        
        string str = "";
        int n = s.length();

        for(int i = 0; i<n; i++)
        {
            if((s[i]>='A' && s[i] <= 'Z') || (s[i] >='a' && s[i] <='z') || (s[i] >= '0' && s[i] <= '9'))
            {
                str += tolower(s[i]);
            }
        }

        string str1 = str;
             
             reverse(str1.begin() , str1.end());

             if(str == str1)
             {
                return true;
             }
             return false;
    }
};
