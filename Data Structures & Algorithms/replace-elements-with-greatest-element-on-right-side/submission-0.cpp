class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int current_max = -1;

        for (int i = arr.size() - 1; i >= 0; i--){
            int new_max = max(arr[i], current_max);
            arr[i] = current_max;
            current_max = new_max;
        }

        return arr;
    }
};