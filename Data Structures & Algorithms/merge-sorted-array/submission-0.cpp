class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int k = 0; k < nums2.size(); k++) {
            nums1[k + m] = nums2[k];
        }

        for (int i = 1; i < nums1.size(); i++) {
            int j = i - 1;
            while (j >= 0 && nums1[j + 1] < nums1[j]) {
                int tmp = nums1[j + 1];
                nums1[j + 1] = nums1[j];
                nums1[j] = tmp;
                j--;
            }
        }
    }
};