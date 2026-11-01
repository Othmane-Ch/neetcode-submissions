class Solution {
public:
    // Time  : O(log(n) + log(m)) = O(log(m*n))
    // Space : O(1) extra space  
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix[0][0] > target || matrix.back().back() < target)
        {
            return false;
        }

        int l = 0, r = matrix.size() - 1;
        int mid_row = 0;
        while(l <= r)
        {
            mid_row = l + (r-l)/2;
            if(matrix[mid_row][0] <= target && target <= matrix[mid_row].back())
            {
                break;
            } else if(matrix[mid_row][0] > target)
            {
                r = mid_row - 1;
            } else if(target > matrix[mid_row].back())
            {
                l = mid_row + 1;
            }
        }

        int i = 0, j = matrix[0].size() - 1;
        int mid_col = 0;
        while(i <= j)
        {
            mid_col = i + (j - i)/2;
            if(matrix[mid_row][mid_col] == target)
            {
                return true;
            } else if( matrix[mid_row][mid_col] < target)
            {
                i = mid_col + 1;
            } else if(target < matrix[mid_row][mid_col])
            {
                j = mid_col - 1;
            }
        }
        return false;
    }
};
