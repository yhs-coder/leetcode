// leetcode260. 只出现一次的数字 III

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // 将数组所有元素进行异或
        // 异或后的结果就是只出现一次的两个元素
        int val = 0;
        for (auto e : nums) {
            val ^= e;
        }
        // 分离出只出现一次的两个元素
        // [1,2,1,3,2,5]
        //  0000 0011
        //  0000 0101
        //^=-------------
        //  0000 0110 
        //         ^这里！
        /* 思路: 两个元素不同的位异或为1，根据这个差异，从val的32位中，
                （从右到左）找到最先出现1的位置pos,然后根据元素中的二
                进制位的位置是否为1，分成两组：[1,2,1,3,2,5]
                    - 第一组保存nums中元素pos位为1的数 [2,2,3] 
                    - 第二组保存nums中元素pos位为0的数 [1,1,5]
                然后每次异或，最后就分离出只出现依次的元素
        */
        // 从异或的结果中，找到1的位置
        size_t i = 0;
        for (; i < 32; i++) {
            if (val & (1 << i)) 
                break;
        }
        int num1 = 0;
        int num2 = 0;
        for (auto e : nums) {
            if (e & (1 << i)) 
                num1 ^= e;
            else 
                num2 ^= e;
        }
        return vector<int>{num1, num2};
    }
};