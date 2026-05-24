class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1;
        int m = 0;

        while (l <= r) {
            m = l + (r - l) / 2;
            int ptr = 0;

            for (auto f: matrix[m]) {

                if (f == target) {
                    return true;    
                }

                else if (f > target) {
                    r = m - 1;
                    break;
                }

                else if (f < target) {
                    ptr++;
                    continue;
                }
            }
            if (ptr > 0) {
                l = m + 1;
            }
        }
        return false;
    }
};
