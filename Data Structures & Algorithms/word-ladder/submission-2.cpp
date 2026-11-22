class Solution {
public:
    // Time  : O(N × L² × 26)
    // Space : O(N × L)
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if(!words.contains(endWord)) return 0;
        const int sz = beginWord.size();
        queue<string> q {};
        q.push(beginWord);
        int min_num = 0;

        while(!q.empty())
        {
            int qsz = q.size();
            ++min_num;
            for(int k = 0; k < qsz; ++k)
            {
                auto s = q.front(); q.pop();
                if(s == endWord) return min_num;
                
                for(int i = 0; i < sz; ++i)
                {
                    char c = s[i];
                    for(int j = 0; j < 26; ++j)
                    {
                        s[i] = 'a' + j;
                        if(words.contains(s))
                        {
                            words.erase(s);
                            q.push(s);
                        } 
                    }
                    s[i] = c;
                }
            }
        }
        return 0;
    }
};
