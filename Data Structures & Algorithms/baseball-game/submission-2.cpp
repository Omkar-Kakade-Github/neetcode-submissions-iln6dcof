class Solution {
public:
    int calPoints(vector<string>& operations) {
        int size = operations.size();
        vector<int> record;

        for (int i = 0; i < size; i++){

            if (operations[i] == "+"){
                int prev_add = record[record.size() - 1] + record[record.size() - 2];
                record.push_back(prev_add);
            }
            else if (operations[i] == "C"){
                record.pop_back();
            }
            else if (operations[i] == "D"){
                record.push_back(2 * record[record.size() - 1]);
            }
            else {
                record.push_back(stoi(operations[i]));
            }   
        }

        return accumulate(record.begin(), record.end(), 0);
    }
};