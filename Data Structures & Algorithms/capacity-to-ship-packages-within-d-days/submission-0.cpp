class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l  = *std::max_element(weights.begin(), weights.end());
        int r  = 0;
        for(const auto& weight : weights)
        {
            r += weight;
        }
        int min_weight = r;
        
        while(l <= r)
        {
            int mid = l + (r - l)/2;
            int time = 0;
            int sum_weight = 0;
            for(int i = 0; i < weights.size(); ++i)
            {
                if(sum_weight + weights[i] > mid)
                {
                    sum_weight = weights[i];
                    ++time;
                } else {
                    sum_weight += weights[i];
                }
            }
            if( sum_weight <= mid)
            {
                ++time;
            }
            cout << "min current capacity = " << mid << endl;
            if(time <= days)
            {
                r = mid - 1;
                min_weight = mid;
            } else {
                l = mid + 1;
            }
        }
        return min_weight;
    }
};