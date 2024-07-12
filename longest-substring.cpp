/*
* Given a string s, find the length of the longest substring without repeating characters.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int newMax = 0;
        string a = "";
        for (int i = 0; i < s.size(); i++) {
            a = s[i];
            if (s.size() > 1) {
                max = 1;
                for (int j = i + 1; j < s.size(); j++) {
                    if (!findChar(a, s[j])) {
                        a = a + s[j];
                        max++;
                    } else {
                        if (max >= newMax) {
                            newMax = max;
                        }
                        break;
                    }
                    if (max >= newMax) {
                        newMax = max;
                    }
                }
            } else {
                if (s.size() == 1) {
                    newMax = 1;
                }
            }
        }
        return newMax;
    }

    bool findChar(string a, char b) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b) {
                return true;
            }
        }
        return false;
    }
};