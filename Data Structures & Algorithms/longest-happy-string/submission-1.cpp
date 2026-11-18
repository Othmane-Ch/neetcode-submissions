class Solution {
public:
    // Time  : O(a + b + c)
    // Space : O(a + b + c) for the output
    string longestDiverseString(int a, int b, int c) {
        const int sz = a + b + c;
        priority_queue<pair<int, char>> max_heap {};
        if(a > 0) max_heap.push(make_pair(a, 'a'));
        if(b > 0) max_heap.push(make_pair(b, 'b'));
        if(c > 0) max_heap.push(make_pair(c, 'c'));

        string s {};
        while(!max_heap.empty())
        {
            auto p = max_heap.top(); max_heap.pop();
            int n = s.size();
            if(n >= 2 && p.second == s[n - 1] && p.second == s[n - 2]) {
                if(max_heap.empty()) break;
                auto p2 = max_heap.top(); max_heap.pop();
                s += p2.second;
                --p2.first;
                if(p2.first) max_heap.push(p2);
            }
            s += p.second;
            --p.first;
            if(p.first) max_heap.push(p);
        }
        return s;
    }
};