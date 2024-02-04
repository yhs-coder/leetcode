//leetcode415. 字符串相加

class Solution {
public:
    string addStrings(string num1, string num2) {
        // 字符串从后往前相加，将结果尾插，最后再倒序
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        int next = 0;   // 用于保存进位
        string retstr;  // 返回的字符串
        int value1 = 0;
        int value2 = 0;
        while (end1 >= 0 || end2 >= 0) {
            if (end1 >= 0) {
                value1 = num1[end1] - '0';
            } else {
                value1 = 0;
            }

            if (end2 >= 0) {
                value2 = num2[end2] - '0';
            } else {
                value2 = 0;
            }
            int ret = value1 + value2 + next;
            if (ret > 9) {  
                next = 1;   // 相加大于9进位
                ret -= 10;
            } else {
                next = 0;
            }
            retstr += (ret + '0');  // 记得加'0',转为字符
            end1--;
            end2--;
        }
        // 检查最后的进位
        if (next == 1) {
            retstr += '1';
        }
        reverse(retstr.begin(), retstr.end());
        return retstr;
    }
};