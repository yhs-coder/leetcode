// leetcode137. Single Number II

class Solution {
public:
    // 思路：统计32个位，每个位合计起来1出现的位数
    int singleNumber(vector<int>& nums) {
        int bitArray[32] = {0};
        int ans = 0;
        // 统计所有数32位中1出现的次数
        for (auto e : nums) {
            for (size_t i = 0; i < 32; i++) {
                // 使用与运算和位运算，来获得元素上的二进制数
                if (e & (1 << i)) { // 当前位为1
                    bitArray[i]++;  
                }
            }
        }

        for (size_t i = 0; i < 32; i++) {
            // 次数为3n+1的位数，就是只出现一次的数里面为1的位
            if (bitArray[i] % 3 == 1) {
                // 使用或运算保存结果
                ans |= (1 << i);
            }
        }
        return ans;

    }

};