class Solution {
public:
void quickSelect(vector<int>& arr, vector<int>& arr2, int s, int e, int k) {
    if (e - s + 1 <= 1) return;

    int pivot = arr[e];
    int pivot2 = arr2[e];
    int left = s;

    for (int i = s; i < e; i++) {
        if (arr[i] < pivot) {
            int tmp = arr[left];
            int tmp2 = arr2[left];
            arr[left] = arr[i];
            arr2[left] = arr2[i];
            arr[i] = tmp;
            arr2[i] = tmp2;
            left++;
        }
    }
    arr[e] = arr[left];
    arr2[e] = arr2[left];
    arr[left] = pivot;
    arr2[left] = pivot2;

    if (left == k)      return;                          
    else if (left > k)  quickSelect(arr, arr2, s, left - 1, k);  
    else if (left < k)  quickSelect(arr, arr2, left + 1, e, k);  
}

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<int> output;
        vector<int> pointer;
        int curr_dist = 0;

        for (int i = 0; i < points.size(); i++) {
            curr_dist = (points[i][0])*(points[i][0]) + (points[i][1])*(points[i][1]);
            output.push_back(curr_dist);
            pointer.push_back(i);
        }
        
        quickSelect(output, pointer, 0, output.size() - 1, k);

        vector<vector<int>> result;

        for (int i = 0; i < k; i++) {
            result.push_back(points[pointer[i]]);
        }

        return result;

    }
};
