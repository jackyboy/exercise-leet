/*
* Write a function to find the longest common prefix string amongst an array of strings.
*
* If there is no common prefix, return an empty string "".
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        bool find = true;
        string r = "";
        string ret = "";
        int max = 200;
        if (strs.size() > 0) {
            for (int j = 1; j <= max; j++) {
                string f = strs[0].substr(0, j);
                if (max > strs[0].size()) {
                    max = strs[0].size();
                }
                if (strs.size() > 1) {
                    for (int i = 0; i < strs.size(); i++) {
                        string s = strs[i].substr(0, j);
                        if (max > strs[i].size()) {
                            max = strs[i].size();
                        }
                        if (f.compare(s) != 0) {
                            find = false;
                        } else {
                            r = s;
                        }
                    }
                } else {
                    r = f;
                }
                if (find) {
                    ret = r;
                }
                r = "";
                find = true;
            }
        } else {
            ret = "";
        }
        return ret;
    }
};