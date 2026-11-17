class Solution {
public:
    // Time  : O(n*log(26)) worst case if all elements in tasks are unique
    // Space : O(n)
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> count {};
        int max = 0;
        char max_task {};
        for(char c : tasks)
        {
            ++count[c];
        }

        priority_queue<int> max_heap {};
        for(const auto& [_, v] : count)
        {
            max_heap.push(v);
        }
        
        queue<pair<int, int>> q {};
        int t = 0;
        while(!max_heap.empty() || !q.empty())
        {
            ++t;
            if(!max_heap.empty())
            {
                auto count_task = max_heap.top(); max_heap.pop();
                --count_task;
                if(count_task) q.push(make_pair(count_task, t + n));
            }
            if(!q.empty() && q.front().second == t)
            {
                max_heap.push(q.front().first);
                q.pop();
            }
        }
            
        return t;
    }
};
