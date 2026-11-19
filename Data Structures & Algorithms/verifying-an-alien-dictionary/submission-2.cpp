class Solution {
public:
    // Time  : O(m * n) m number of words and n
    // Space : O(26)
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> letters {};
        int i = 0;
        for(char c : order)
        {
            letters[c] = i;
            ++i;
        }
        for(int i = 0; i < words.size() - 1; ++i)
        {
            auto len = min(words[i].size(), words[i + 1].size()); 
            for(int j = 0; j < len; ++j)
            {
                if(words[i][j] == words[i + 1][j]) continue;
                if(letters[words[i][j]] > letters[words[i + 1][j]])
                {
                    return false;
                } else {
                    break;
                }
            }
            if(words[i].size() > words[i + 1].size() && words[i].compare(0, len, words[i + 1]) == 0) return false;
        }
        return true;
    }
};