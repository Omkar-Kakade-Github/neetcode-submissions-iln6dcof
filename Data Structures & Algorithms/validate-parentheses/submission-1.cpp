class Solution {
public:
    bool isValid(string s) {
        vector<int> bracket_stack;
        int size = s.size();

        if (size%2 == 1){
            return false;
        }

        if (s[0] == ']' || s[0] == '}' || s[0] == ')'){
            return false;
        }
        
        for (int i = 0; i < size; i++){

            if (s[i] == ']' && bracket_stack.back() == '[') {
                bracket_stack.pop_back();
            }

            else if (s[i] == '}' && bracket_stack.back() == '{') {
                bracket_stack.pop_back();
            }

            else if (s[i] == ')' && bracket_stack.back() == '(') {
                bracket_stack.pop_back();
            }

            else {
                bracket_stack.push_back(s[i]);
            }
        }

        if (bracket_stack.empty()) {
            return true;
        }
        else {
            return false;
        } 
    }
};
