class Solution {
public:
    void sortColors(vector<int>& nums) {
        int color_count[] = {0, 0, 0};

        for (auto n: nums) {
            color_count[n]++;
        }

        int i = 0;

        for (int n = 0; n < 3; n++) {
            for (int j = 0; j < color_count[n]; j++) {
                nums[i] = n;
                i++;
            }
        }
    }
};