class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int mov;
        int num_sandwich = 0;
        
        while(sandwiches.size() != 0){
            if (students.front() == sandwiches.front()){
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                num_sandwich--;
            }
            else if (students.front() != sandwiches.front()){
                mov = students.front();
                if (num_sandwich == 150){
                    return students.size();
                }
                students.erase(students.begin());
                students.push_back(mov);
                num_sandwich++;
            }
        }
        return students.size();

        
    }
};