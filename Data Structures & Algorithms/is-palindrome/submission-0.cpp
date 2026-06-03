class Solution {
public:
    string converter(string s, int len) {
        string conv_string;
        for (int i = 0; i < len; i++) {
            if (isalnum(s.at(i))) {
                conv_string.push_back(tolower(s.at(i)));
            }
        }

        return conv_string;
    }

    bool isPalindrome(string s) {
        int len_string = s.size();

        if (s.empty()) return true;

        string conv = converter(s, len_string);

        int conv_len = conv.size();
        int half = conv_len/2;

        for (int i = 0; i < half; i++) {
            char ptr = conv.at(0 + i);
            char ptr_back = conv.at(conv_len - 1 - i);

            if (ptr == ptr_back) {
                continue;
            }
            else {
                return false;
            }
        }

        return true;
    }
};
