/*You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j) {
            int a = 0;
            if (height[i] > height[j]) {
                a = area(j - i, height[j]);
                j--;
            } else {
                a = area(j - i, height[i]);
                i++;
            }
            if (a > max) {
                max = a;
            }
        }
        return max;
    }

    int area(int b, int h) { return b * h; }
};