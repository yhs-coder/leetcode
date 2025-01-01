/*
leetcode[27] 移除元素
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        //方法一：暴力破解法
        // 时间复杂度：O(n^2)
        // 空间复杂度：O(1)
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) { //发现需要移除的元素，就将数组集体向前移动一位
                for(int j = i+1; j < size; j++) {
                    nums[j-1] = nums[j];
                }
                i--; // 因为下标i以后的数值都向前移动了一位，所以i也向前移动一位
                size--; // 此时数组的大小-1
            }
        }
        return size;


       // 时间复杂度：O(n)
       // 空间复杂度：O(1) 
       //方法二：快慢指针法（第一种写法）
        /*
        int fastIndex = 0;
        int slowIndex = 0;
        //注意边界条件，快指针不能越界
        while (fastIndex < nums.size()) {
            if (nums[fastIndex] != val) {
                nums[slowIndex] = nums[fastIndex];
                slowIndex++;
            }
            fastIndex++;
        }
        return slowIndex; 
    */

    //快慢指针法（第二种写法）
   
   /*
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size();fastIndex++) {
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    */


    //方法三：相向双指针方法
        int leftIndex = 0;
        int rightIndex = nums.size() - 1;
        while (leftIndex <= rightIndex) {
            //左指针一直向右移动，直到找到val的元素才停止
            // 找左边等于val的元素
            while (leftIndex <= rightIndex && nums[leftIndex] != val) {
                leftIndex++;
            }
            // 找右边不等于val的元素
            //当左指针停止后，右指针开始向左移动，直到找到非val的元素
            while (rightIndex >= leftIndex && nums[rightIndex] == val) {
                rightIndex--;
            }
             // 将右边不等于val的元素覆盖左边等于val的元素
            nums[leftIndex++] = nums[rightIndex--];
        }
        return leftIndex;



    }

};