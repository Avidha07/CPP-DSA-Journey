class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0; int j =0;

        int maxi = 0;
        int len = 0;

        //unordered_map<char , int>mp;
        set<char>st;
        //string str  = "";

        while(j<n)
        {
            while(st.find(s[j]) != st.end())
            {
                 st.erase(s[i]);
                 i++;
            }
            st.insert(s[j]);
            len = j-i+1;
            maxi = max(maxi , len);
            j++;
     
        }
        return maxi;
    }
};
