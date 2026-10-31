class Solution {
public:
    bool isCloser(int a, int x, int b) {
        return abs(a - x) == abs(b - x) ? a < b : abs(a - x) < abs(b - x);
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        const int n = arr.size();
        int l = 0;
        int r = 0;
        while(l <= r && r < n)
        {
            if(r - l + 1 >= k)
            {
                if(!isCloser(arr[r+1], x ,arr[l]) && arr[r+1] != arr[l]) {
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