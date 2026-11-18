class Solution {
public:
    string reorganizeString(string s) {
        const int n = s.size();
        array<int, 26> count {};
        for(char c : s)
        {
            ++count[c - 'a'];
        }
        priority_queue<pair<int, char>> max_pq {};
        for(int i = 0; i < count.size(); ++i)
        {
            if(count[i] > 0)
            {
                max_pq.push(make_pair(count[i],  static_cast<char>(i + 'a')));
            }
        }

        if(max_pq.top().first > (n + 1)/2) return "";
        queue<pair<int, char>> q {};
        string r = "";
        
        while(!max_pq.empty() || !q.empty())
        {
            if(!q.empty() && q.front().second != r.back())
            {
                max_pq.push(q.front());
                q.pop();
            }
            if(!max_pq.empty())
            {
                auto p = max_pq.top(); max_pq.pop();
                r += p.second;
                --p.first;
                if(p.first) q.push(p);
            }
        }
        return r;
    }
};