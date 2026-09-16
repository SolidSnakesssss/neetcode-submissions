class Solution {
public:

    string encode(vector<string>& strs) {
        std::string encoded_string;
        for (const string& str : strs) {
            encoded_string += to_string(str.size()) + "#" + str;
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        std::vector<std::string> decoded_strings;
        size_t i = 0;
        while (i < s.size()) {
            size_t delim_pos = s.find('#', i);
            int len = stoi(s.substr(i, delim_pos - i));
            decoded_strings.push_back(s.substr(delim_pos + 1, len));
            i = delim_pos + 1 + len;
        }
        return decoded_strings;
    }
};