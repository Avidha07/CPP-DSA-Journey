class Solution {
public:
    int kDistinctChar(string& s, int k) {
        //your code goes here
        int n = s.length();
        int i =0; int j =0;
        int maxlen = INT_MIN;
        
        unordered_map<char , int>mp;

        while(j<n)
        {
            mp[s[j]]++;

            if(mp.size() > k)
            {
                 while(mp.size() > k)
                 {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0)
                    {
                        mp.erase(s[i]);
                    }
                    i++;
                 }
            }
            if(mp.size() <= k)
            {
                maxlen = max(maxlen , j-i+1);
            }
            j++;
        }
        return maxlen;
    }
};
