class Solution {
public:
    void sortColors(vector<int>& nums) {
        int nextZero = 0, nextOne = 0, nextTwo = nums.size() - 1;

        while (nextOne <= nextTwo) {
            if (nums[nextOne] == 0) {
                swap(nums[nextZero++], nums[nextOne++]);
            } else if (nums[nextOne] == 1) {
                nextOne++;
            } else {
                swap(nums[nextOne], nums[nextTwo--]);
            }
        }
    }
};