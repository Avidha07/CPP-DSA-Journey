class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();

        vector<int>res;
        vector<int>windowFreq(26);
        vector<int>patternFreq(26);

        for(int i =0; i<m; i++)
        {
            patternFreq[p[i]-'a']++;
        }

        int i =0; int j =0;
        
        while( j < n)
        {
            windowFreq[s[j]-'a']++;

            if(j-i+1 == m)
            {
                 if(windowFreq==patternFreq)
                 {
                    res.push_back(i);
                 }

                windowFreq[s[i] - 'a']--;
                i++;
               
            }
            j++;
        }
        return res;
    }
};
