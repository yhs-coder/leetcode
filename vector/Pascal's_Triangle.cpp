// leetcode118. 杨辉三角

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // 杨辉三角特点
        // 行数和个数相同，第一行1个，第二行2个，逐渐递增
        // 每个元素都是 上行的元素与上行元素前一个的元素相加
        vector<vector<int>> vv;
        // 开辟空间并初始化
        vv.resize(numRows);
        for (size_t i = 0; i < numRows; i++) {
            vv[i].resize(i + 1);
            vv[i][0] = 1;
            vv[i][vv[i].size() - 1] = 1;
        }
        for (size_t i = 0; i < vv.size(); i++) {
            for (size_t j = 0; j < vv[i].size(); j++) {
                if (vv[i][j] != 1) {
                    vv[i][j] = vv[i-1][j] + vv[i-1][j-1];
                }
            }
        }
        return vv;
    }
};