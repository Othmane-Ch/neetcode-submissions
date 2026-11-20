class Solution {
public:
    // Time  : O(D + 10^4 * 8)   D = number of deadends
    // Space : O(10^4)
    int openLock(vector<string>& deadends, string target) {
        array<bool, 10000> visited {};
        for(const auto& s : deadends) visited[stoi(s)] = true;

        const int start = 0, goal = stoi(target);
        if(visited[start]) return -1;
        if(goal == start) return 0;

        static constexpr array<int, 4> pow10 = {1, 10, 100, 1000};
        queue<int> q {};
        q.push(start);
        visited[start] = true;

        for(int spin = 1; !q.empty(); ++spin)
        {
            for(int k = q.size(); k > 0; --k)          // one BFS level
            {
                int pin = q.front(); q.pop();
                for(int i = 0; i < 4; ++i)
                {
                    int d = (pin / pow10[i]) % 10;
                    for(int nd : {(d + 1) % 10, (d + 9) % 10})   // forward, backward
                    {
                        int next = pin + (nd - d) * pow10[i];
                        if(visited[next]) continue;
                        if(next == goal) return spin;
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
        }
        return -1;
    }
};