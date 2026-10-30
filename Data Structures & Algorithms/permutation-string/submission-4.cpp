class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        unordered_map<char, int> count1 {};
        for(const auto& c: s1)
        {
            ++count1[c];
        }
        unordered_map<char, int> count2 {};
        int l = 0;
        for(int r = 0; r < s2.size(); ++r)
        {
            ++count2[s2[r]];
            if(r - l + 1 == s1.size())
            {
                if(count1 == count2)
                {
                    return true;
                } else {
                    --count2[s2[l]];
                    if(count2[s2[l]] == 0)
                    {
                        count2.erase(s2[l]);
                    }
                    ++l;
                }
            } 
        }
        return false;
    }
};
