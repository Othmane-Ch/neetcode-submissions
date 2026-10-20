class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int j = 0;
        string word = "";
        const int n = word1.size() + word2.size();
        while( i+j < n)
        {
            if(i < word1.size())
            {
                word += word1[i];
                ++i;
            }
            if(j < word2.size())
            {
                word += word2[j];
                ++j;
            }
        }
        return word;
    }
};