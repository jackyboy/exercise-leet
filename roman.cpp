class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;
        int b = romanCharToInt(s[s.size()-1]);
        ret = b;
        int a = 0;
        for (int i = s.size()-2; i >= 0; i--) {
            a = romanCharToInt(s[i]);
            if (b > a) {
                ret = ret - a;
            } else {
                ret = ret + a;
            }
            b = a;
        }

        return ret;
    }

    int romanCharToInt(char c) {
        switch (c) {
        case 'I':
            return 1;
            break;
        case 'V':
            return 5;
            break;
        case 'X':
            return 10;
            break;
        case 'L':
            return 50;
            break;
        case 'C':
            return 100;
        case 'D':
            return 500;
            break;
        case 'M':
            return 1000;
            break;
        default:
            return 0;
        }
    }
};