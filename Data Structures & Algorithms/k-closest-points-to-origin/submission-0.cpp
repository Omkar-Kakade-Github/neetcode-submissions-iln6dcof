class Solution {
public:
    vector<int> quickSort(vector<float>& arr,vector<int>& arr2, int s, int e) {
        if (e - s + 1 <= 1) {
            return arr2;
        }

        float pivot = arr[e];
        int pivot2 = arr2[e];
        int left = s;

        for (int i = s; i < e; i++) {
            if (arr[i] < pivot) {
                float tmp = arr[left];
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
        
        quickSort(arr, arr2, s, left - 1);
        quickSort(arr, arr2, left + 1, e);

        return arr2;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<float> output;
        vector<int> pointer;
        float curr_dist = 0;

        for (int i = 0; i < points.size(); i++) {
            curr_dist = sqrt(pow((points[i][0] - 0), 2) + pow((points[i][1] - 0), 2));
            output.push_back(curr_dist);
            pointer.push_back(i);
        }
        
        quickSort(output, pointer, 0, output.size() - 1);

        vector<vector<int>> result;

        for (int i = 0; i < k; i++) {
            result.push_back(points[pointer[i]]);
        }

        return result;

    }
};
