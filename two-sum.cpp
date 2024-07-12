/*
* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
*
* You may assume that each input would have exactly one solution, and you may not use the same element twice.
*
* You can return the answer in any order.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        int h = 0;
        int k = 0;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums.size(); j++){
                if(nums[i]+nums[j]==target && i!=j){
                    h = i;
                    k = j;
                    break;
                }
            }
        }
        ret.push_back(h);
        ret.push_back(k);
        return ret;
    }
};