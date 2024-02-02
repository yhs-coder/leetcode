/*
leetcode917. Reverse Only Letters

*/


class Solution {
public:
    bool IsLetter(char ch) {
        if ((ch >= 'a' && ch <= 'z' ) || (ch >= 'A' && ch <= 'Z')) {
            return true;
        } else {
            return false;
        }
    }

    string reverseOnlyLetters(string s) {
        int begin = 0;
        int end = s.size() - 1;
        while (begin < end) {
            while (begin < end && IsLetter(s[begin]) == false) {
                begin++;
            }
            while (begin < end && IsLetter(s[end]) == false) {
                end--;
            }
            swap(s[begin++],s[end--]);
        }
        return s;

    }
};