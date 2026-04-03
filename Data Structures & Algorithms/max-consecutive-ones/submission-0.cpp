class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int length = nums.size();
        int list_consec[50000] = {0};
        int lc = 0;

        for (int i = 0; i < length; i++){
            if (nums[i] == 1) {
                count += 1;

                if (i == length - 1){
                    list_consec[lc] = count;
                    break;
                }
            }
            else if (nums[i] == 0){
                list_consec[lc] = count;
                lc += 1;
                count = 0;
            }
            
        };

        return *max_element(std::begin(list_consec), std::end(list_consec));
    };   
};