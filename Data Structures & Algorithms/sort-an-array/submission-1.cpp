class Solution {
public:

    void merge(vector<int>& nums, int left, int mid, int right)
    {
        int n_left = mid - left + 1;
        int n_right = right - mid;

        vector<int> L(n_left), R(n_right);

        for(int i = 0; i < n_left; ++i)
        {
            L[i] = nums[left + i];
        }
        for(int i = 0; i < n_right; ++i)
        {
            R[i] = nums[mid + i + 1];
        }
        int i = left;
        int j = 0;
        int k = 0;

        while(j < L.size() && k < R.size())
        {
            if(L[j] <= R[k])
            {
                nums[i] = L[j];
                ++j;
            }
            else
            {
                nums[i] = R[k];
                ++k;
            }
            ++i;
        }

        while(j < L.size())
        {
            nums[i] = L[j];
            ++j;
            ++i;
        }

        while(k < R.size())
        {
            nums[i] = R[k];
            ++k; 
            ++i;
        }
    }

    void mergeSort(vector<int>& nums, int left, int right)
    {
        if(left >= right)
        {
            return;
        }

        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};