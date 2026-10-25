class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        vector<vector<int>> result {};
        int i = 0;
        
        while(i < n) {
            if (i > 0 && nums[i] == nums[i-1]) { ++i; continue; }
            int j = n-1;
            while (i < j)
            {
                if ( j < n-1 && nums[j] == nums[j+1]) { --j; continue; }
            
                int l = i+1;
                int r = j-1;

                while(l < r)
                {
                    auto sum = (long long) nums[i] + nums[l] + nums[r] + nums[j];
                    if( sum > target)
                    {
                        --r;
                    } 
                    else if(sum < target)
                    {
                        ++l;
                    }   
                    else
                    {
                        cout << sum << endl;
                        cout << i << endl;
                        cout << l << endl;
                        cout << r << endl;
                        cout << j << endl;
                        result.push_back({nums[i], nums[l], nums[r], nums[j]});
                        ++l; --r;
                        while (l < r && nums[l] == nums[l-1]) ++l;   // skip duplicate l
                        while (l < r && nums[r] == nums[r+1]) --r;   // skip duplicate r
                    }
                }
                --j;
            }
            
            ++i;
        }
        return result;
        
    }
    
};