class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int mov;
        int consec = 0;
        
        while(sandwiches.size() != 0){
            if (students.front() == sandwiches.front()){
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                consec = 0;
            }
            else if (students.front() != sandwiches.front()){
                mov = students.front();

                if (consec == students.size()){
                    return students.size();
                }
                students.erase(students.begin());
                students.push_back(mov);
                consec++;
            }
        }
        return students.size();
    }
};