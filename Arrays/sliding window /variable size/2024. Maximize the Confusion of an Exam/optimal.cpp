class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int i = 0; int j = 0;
        int maxLen = 0;
        int maxfreq = 0;

        unordered_map<char,int>mp;

        while(j<n)
        {
            mp[answerKey[j]]++;

            maxfreq = max(maxfreq , mp[answerKey[j]]);

            while((j-i+1) - maxfreq  > k)
            {
                mp[answerKey[i]]--;
                i++;
            }
            maxLen = max(maxLen , j-i+1);
            j++;
        }

        return maxLen;

    }
};
