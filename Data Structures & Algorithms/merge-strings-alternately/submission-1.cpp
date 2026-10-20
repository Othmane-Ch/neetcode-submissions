class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        const int n = word1.size() + word2.size();
        string word = "";
        word.reserve(n);
        
        int i = 0;
        int j = 0;
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