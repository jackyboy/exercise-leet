/*Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

    Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
    Return k.
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 0;
        vector<int> v;
        while(i<nums.size()){
            if(j<nums.size()){
                if(nums[i]==nums[j]){
                    j++;
                }else{
                    v.push_back(nums[i]);
                    i=j;
                }
            }else{
                v.push_back(nums[i]);
                i=nums.size();
            }
        }
        nums = v;
        return v.size();
    }
};