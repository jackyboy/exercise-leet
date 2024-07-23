/*
*Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
*
*Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
*/
class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        std::vector<int> r;
        int n = x;
        long qw = pow(2,31)-1;
        long qw2 = (pow(2, 31)*-1);

        while ((n / 10) != 0) {
            int i = n % 10;
            r.push_back(i);
            n = n / 10;
        }

        r.push_back(n % 10);
        int p = r.size() - 1;
        for (int j = 0; j < r.size(); j++) {
            long  a = r[j] * pow(10, p);
            if ((a + ret) <= qw && (a + ret) >= qw2) {
                ret = ret + a;
                p = p - 1;
            } else {
                ret = 0;
                break;
            }
        }

        return ret;
    }
};