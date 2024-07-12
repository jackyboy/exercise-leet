/*
* Given an integer x, return true if x is a palindrome, and false otherwise.
*/
class Solution {
public:
    bool isPalindrome(int x) {
        std::string a = std::to_string(x);
        int last = a.size()-1;
        for(int i=0; i<a.size(); i++){
            if(a[i]!=a[last]){
                return false;
            }
            last = last - 1;
            if(i>last){
                break;
            }
        } 
        return true;
    }
};