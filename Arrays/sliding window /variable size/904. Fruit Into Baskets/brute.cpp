class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int maxlen = 0;
        int n = fruits.size();

        for(int i =0; i<n; i++)
        {
            set<int>st;

            for(int j = i; j<n; j++)
            {
                st.insert(fruits[j]);

                if(st.size() <= 2)
                {
                    maxlen = max(maxlen , j-i+1);
                }
                else{
                    break;
                }
            }
        }
        return maxlen;
    }
};
