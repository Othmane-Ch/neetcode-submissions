class Solution {
public:
    const unordered_map<char, pair<char, char>> nextDigit = {
        {'0', {'9', '1'}}, {'1', {'0', '2'}}, {'2', {'1', '3'}},
        {'3', {'2', '4'}}, {'4', {'3', '5'}}, {'5', {'4', '6'}},
        {'6', {'5', '7'}}, {'7', {'6', '8'}}, {'8', {'7', '9'}},
        {'9', {'8', '0'}}
    };
    // Time  : O(d + 10^n) n size of target
    // Space : O(10^n)
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited {};
        for(const auto& s : deadends)
        {
            if(s == "0000") return -1;
            visited.insert(s);
        }
        queue<pair<int, string>> q {};
        q.push(make_pair(0, "0000"));
        while(!q.empty())
        {
            auto [spin, pin] = q.front();q.pop();
            if(pin == target)
            {
                return spin;
            }
            for(int i = 0; i < 4; ++i)
            {
                string forward_pin(pin), backward_pin(pin);
                backward_pin[i] = nextDigit.at(backward_pin[i]).first;
                forward_pin[i] = nextDigit.at(forward_pin[i]).second;

                if(!visited.contains(backward_pin))
                {
                    visited.insert(backward_pin);
                    q.push(make_pair(spin + 1, backward_pin));
                }
                if(!visited.contains(forward_pin))
                {
                    visited.insert(forward_pin);
                    q.push(make_pair(spin + 1, forward_pin));
                } 
            }
        }

        return -1;
    }
};