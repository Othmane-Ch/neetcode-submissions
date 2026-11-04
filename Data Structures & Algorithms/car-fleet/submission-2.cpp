class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars(position.size());
        for(int i = 0; i < position.size(); ++i)
        {
            cars[i] = make_pair(position[i], speed[i]);
        }
        stack<double> st;
        sort(cars.begin(), cars.end(), std::greater<>());
        for(const auto& car : cars)
        {
            double time = static_cast<double>(target - car.first) / car.second;
            if(st.empty() ||  time > st.top() )
            {
                st.push(time);
            } 
        }
        return st.size();
    }
};
