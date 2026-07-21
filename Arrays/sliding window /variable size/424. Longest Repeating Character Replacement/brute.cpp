class Solution {
public:
    int characterReplacement(string s, int k) {

       int n = s.length();
       //int i = 0; int j = 0;
      int maxl = 0;
     
     

      for(int i =0; i<n; i++)
      {
          vector<int>freq(26,0);

          int maxfreq =0;

        for(int j = i; j<n; j++)
        {
            freq[s[j] - 'A']++;
            maxfreq = max(maxfreq , freq[s[j] - 'A']);
            int windowlen = j-i+1;
            int replace = windowlen - maxfreq;

            if(replace<=k)
            {
                maxl = max(maxl , windowlen);
            }
        }
      }

       return maxl;


    }
};
