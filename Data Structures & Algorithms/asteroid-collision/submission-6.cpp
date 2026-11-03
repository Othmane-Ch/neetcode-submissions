class Solution {
public:
    // Time  :  O(n) -- amortized
    // Space :  O(n)
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st {};
        for(const auto& a : asteroids)
        {
            if(st.empty())
            {
                st.push(a);
            } else {
                
                if(a >= 0)
                {
                    st.push(a);
                    continue;
                } else 
                {
                    // a going to left
                    int b = st.top();
                    if(b < 0)
                    {
                        st.push(a);
                        continue;
                    } else {
                        // check a and b colliding
                        bool alive = true;
                        while(!st.empty() && st.top() > 0)
                        {
                            if(abs(a) == st.top())
                            {
                                st.pop();
                                alive = false;
                                break;
                            } else if(abs(a) > st.top())
                            {
                                st.pop();
                            } else {
                                alive = false;
                                break;
                            }
                        }
                        if(alive) {
                            st.push(a);
                        }
                    }
                }
            }
        }
        
        vector<int> result(st.size(), 0);
        int i =(int) st.size() - 1;
        while(!st.empty())
        {
            result[i] = st.top();
            st.pop();
            --i;
        }

        return result;
    }
};