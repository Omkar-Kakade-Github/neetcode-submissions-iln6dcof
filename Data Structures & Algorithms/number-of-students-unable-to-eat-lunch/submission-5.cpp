
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int num_zero = 0;
        int num_one = 0;
        int res = students.size();
        for (int i = 0; i < students.size(); i++) {
            if (students[i] == 0) {
                num_zero++;
            }
            else {
                num_one++;
            }
        }

        for (int i = 0; i < sandwiches.size(); i++){
            if (sandwiches[i] == 0 && num_zero > 0){
                num_zero--;
                res--;
            }
            else if (sandwiches[i] == 1 && num_one > 0){
                num_one--;
                res--;
            }
            else {
                break;
            }
        }

        return res;
    }
};