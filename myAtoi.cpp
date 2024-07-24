/*
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

    Whitespace: Ignore any leading whitespace (" ").
    Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity is neither present.
    Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
    Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.

Return the integer as the final result.
*/

class Solution {
public:
    int myAtoi(string s) {
        int maxL = pow(2, 31) - 1;
        int minL = -1 * pow(2, 31);
        int ret = 0;
        std::vector<int> a;
        bool isNegative = false;
        bool isPositive = false;
        bool findNum = false;
        bool findUs = false;
        bool fN = false;
        for (int i = 0; i < s.size(); i++) {
            int b = charToNum(s[i]);
            if (b != -1) {
                findNum = true;
                a.push_back(b);
            } else if (s[i] == '-' && !isNegative && !isPositive && !findNum) {
                isNegative = true;
            } else if (s[i] == '+' && !isNegative && !isPositive && !findNum) {
                isPositive = true;
            } else if (s[i] != ' ') {
                break;
            } else if (s[i] == ' ' && (findNum || isNegative || isPositive)) {
                break;
            }
        }
        if (findNum) {
            int p = a.size() - 1;
            if (pow(10, p) <= maxL && pow(10, p) >= minL) {
                for (int j = 0; j < a.size(); j++) {
                    if (a[j] == 0 && !fN) {
                        p = p - 1;
                        ret = ret + 0;
                    } else {
                        fN = true;
                        long tmp = ret + a[j] * pow(10, p);
                        if (tmp <= maxL && tmp >= minL) {
                            ret = tmp;
                            p = p - 1;
                        } else {
                            if (isNegative) {
                                ret = minL;
                            } else {
                                ret = maxL;
                            }
                            findUs = true;
                            break;
                        }
                    }
                }

                if (isNegative && !findUs) {
                    ret = -1 * ret;
                }
            } else {
                if (a[0] == 0) {
                    for (int j = 0; j < a.size(); j++) {
                        if (a[j] == 0 && !fN) {
                            p = p - 1;
                            ret = ret + 0;
                        } else {
                            fN = true;
                            long tmp = ret + a[j] * pow(10, p);
                            if (tmp <= maxL && tmp >= minL) {
                                ret = tmp;
                                p = p - 1;
                            } else {
                                if (isNegative) {
                                    ret = minL;
                                } else {
                                    ret = maxL;
                                }
                                findUs = true;
                                break;
                            }
                        }
                    }

                    if (isNegative && !findUs) {
                        ret = -1 * ret;
                    }
                } else {
                    if (isNegative) {
                        ret = minL;
                    } else {
                        ret = maxL;
                    }
                }
            }
        } else {
            ret = 0;
        }

        return ret;
    }

    int charToNum(char x) {
        switch (x) {
        case '0':
            return 0;
            break;
        case '1':
            return 1;
            break;
        case '2':
            return 2;
            break;
        case '3':
            return 3;
            break;
        case '4':
            return 4;
            break;
        case '5':
            return 5;
            break;
        case '6':
            return 6;
            break;
        case '7':
            return 7;
            break;
        case '8':
            return 8;
            break;
        case '9':
            return 9;
            break;
        default:
            return -1;
        }
    }
};