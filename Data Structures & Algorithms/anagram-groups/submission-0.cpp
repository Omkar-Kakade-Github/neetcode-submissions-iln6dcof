class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map to store sorted string as key and list of anagrams as value
        unordered_map<string, vector<string>> anagramMap;
    
        // Iterate through each string in the input array
        for (const auto& str : strs) {
            string key = str;       // Copy the original string
            sort(key.begin(), key.end());  // Sort the string to form the key
            anagramMap[key].push_back(str);  // Append original string to the corresponding key
        }
    
        // Prepare the result vector from the hash map values
        vector<vector<string>> result;
        for (auto& entry : anagramMap) {
            result.push_back(entry.second);
        }
    
        return result;
    }
};    
        
