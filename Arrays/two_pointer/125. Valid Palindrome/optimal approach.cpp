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
        //cout<<str<<endl;

        int m = str.length();

        int i =0; int j = m-1;

        while(i<=j)
        {
            if(str[i] == str[j] )
            {
                i++;
                j--;
            }
            else {
                return false;
                
            }
        }
        return true;
    }
};
