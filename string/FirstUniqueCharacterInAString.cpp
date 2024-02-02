/*
leeetcode387. First Unique Character in a String
*/
class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = {0};
        // 哈希思想，字母与下标位置对应，a->0,b->1...并记录该位置次数
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
        }
        // 遍历字符串，查看该字符在数组对应位置的值是否为1
        for (int i = 0; i < s.size(); i++) {
            if (count[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};