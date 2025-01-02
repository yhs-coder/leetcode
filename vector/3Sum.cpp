/*
leetcode15. 三数之和
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        //对数组进行排序
        sort(nums.begin(),nums.end());
        /*
            使用双指针法， a = nums[i],b = nums[left], c = nums[right];
        */
        for (int i = 0; i < nums.size(); i++) {
            //如果当前的元素大于0，那后面left和right的元素怎么相加都不为0，因为已经从小到大排好序了
            if (nums[i] > 0) {
                return res;
            }
            int left = i + 1;
            int right = nums.size()-1;
            //对a去重
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            //开始遍历，查找另外两数与nums[i]的和为0的情况
            while (right > left) { //不能right >= left，不然特殊情况 0，0，0没法包含
                if (nums[i] + nums[left] + nums[right] > 0 ) {
                    right--;  //right左移
                }
                else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++; //left右移
                }
                else {
                    res.push_back({nums[i],nums[left],nums[right]});

                    //对接下来的b,c去重 因为可能有这种情况 -1 -1 -1 -1 0 1 1 2 2 2 2 2
                    while(right > left && nums[left] == nums[left + 1]) left++;
                    while(right > left && nums[right] == nums[right - 1]) right--;

                    //对b,c去重后，left、right对应的元素是最后重复的元素，要双指针同时收缩，指向下一个不重复的元素
                    right--;
                    left++;
                }
            } 
        }
        return res;
    }
};