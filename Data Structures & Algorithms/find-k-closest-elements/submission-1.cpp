class Solution {
public:
    bool isCloser(int a, int x, int b) {
        return abs(a - x) == abs(b - x) ? a < b : abs(a - x) < abs(b - x);
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        const int n = arr.size();
        int l = 0;
        int r = 1;
        while(l < r && r < n)
        {
            if(r - l >= k)
            {
                if(!isCloser(arr[r], x ,arr[l]) && arr[r] != arr[l]) {
                    break;
                }  else 
                {
                    ++r;
                    ++l;
                }
            } else {
                ++r;
            }

        }

        vector<int> result(k, 0);
        for(int i = 0; i < k; ++i)
        {
            result[i] = arr[i+l];
        }
        return result;
    }
};