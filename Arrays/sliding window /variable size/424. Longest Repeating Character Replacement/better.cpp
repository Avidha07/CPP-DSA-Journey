class Solution {
public:
    int characterReplacement(string s, int k) {

       int n = s.length();
       int i = 0; int j = 0;
      int maxl = 0;
      int maxf = 0;
      unordered_map<char,int>freq;

       while(j<n)
       {
           freq[s[j]]++;
           maxf = max(maxf, freq[s[j]]);

           while((j-i+1) - maxf > k)
           {
            freq[s[i]]--;
            i++;
           }
           maxl = max(maxl , j-i+1);
           j++;
             
       }

       return maxl;


    }
};
