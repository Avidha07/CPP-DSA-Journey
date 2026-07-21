class Solution {
public:
    int characterReplacement(string s, int k) {

       int n = s.length();
       int i = 0; int j = 0;
      int maxl = 0;
      int maxf = 0;
     vector<int>freq(26,0);

       while(j<n)
       {
           freq[s[j]-'A']++;
           maxf = max(maxf, freq[s[j] - 'A']);

           if((j-i+1) - maxf > k)
           {
            freq[s[i]-'A']--;
            i++;
           }
           maxl = max(maxl , j-i+1);
           j++;
             
       }

       return maxl;


    }
};
