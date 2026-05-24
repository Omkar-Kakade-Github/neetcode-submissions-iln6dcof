class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int opt_rate = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long rate = 0;

            for (int i: piles) {
                rate += ceil(static_cast<double>(i) / mid);
            }

            if (rate > h) {
                low = mid + 1;
            }

            else if (rate <= h) {
                opt_rate = mid;
                high = mid - 1;
            }
        }
        return opt_rate;
    }
};
