class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int k = 0;
        double median = 0;
        vector<int> v;

        while(j<nums1.size() || i<nums2.size()){
            if(j==nums1.size()){
                v.push_back(nums2[i]);
                i++;
            }else if(i==nums2.size()){
                v.push_back(nums1[j]);
                j++;
            }else if(nums1[j]<=nums2[i]){
                v.push_back(nums1[j]);
                j++;
            }else{
                v.push_back(nums2[i]);
                i++;
            }
        }

        if((v.size()%2)==0){
            int m1 = v.size()/2;
            int m2 = m1 - 1;
            median = (v[m1]+v[m2])/2.0; 
        }else{
            int m = v.size()/2;
            median = v[m];
        }
        return median;
    }
};