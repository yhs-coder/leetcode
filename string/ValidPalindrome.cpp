// leetcode125. 验证回文串

class Solution {
public:
    bool isCharOrNumber(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
            return true;
        } else {
            return false;
        }
    }
    bool isPalindrome(string s) {
        // 将所有的大写字母转为小写字母
        for (auto& ch : s) {
            if (ch >= 'A' && ch <= 'Z') {
                ch += ('a' - 'A');
            }
        }
        // 使用双指针，前后进行比较
        int begin = 0;
        int end = s.size() - 1;
        while (begin < end) {
            // 如果不是字母或者数字，就往前/往后移动
            while (begin < end && !isCharOrNumber(s[begin])) {
                begin++;
            }
            while (begin < end && !isCharOrNumber(s[end])) {
                end--;
            }
            if (s[begin] != s[end]) {
                return false;
            } else {
                begin++;
                end--;
            }
        }
        return true;
    }
};