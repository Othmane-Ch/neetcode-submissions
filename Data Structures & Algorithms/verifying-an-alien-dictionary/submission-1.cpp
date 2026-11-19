class Solution {
public:
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
            for(int j = 0; j < words[i].size(); ++j)
            {
                if(words[i][j] == words[i + 1][j]) continue;
                if(letters[words[i][j]] > letters[words[i + 1][j]])
                {
                    return false;
                } else {
                    break;
                }
            }
        }
        return true;
    }
};