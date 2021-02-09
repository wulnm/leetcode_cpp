/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<=1)
            return s;
    int max = -1, len = 0, pos = 0, type = 0; // type==0则为中心双数情况,type==1则为中心单数情况
    for (int i = 0; i < s.length(); i++) {
        len = 0;
        while (i - (len + 1) >= 0 && i + (len + 1) < s.length() && s.at(i - (len + 1)) == s.at(i + (len + 1))) {
            len++;
        }

        if (len > max) {
            max = len;
            pos = i;
            type = 1;
        }

        len = 0;
        int l = i - 1;
        // 中心为两个字符的情况
        // 左1个字符加入中心
        if (i > 0 && s.at(i - 1) == s.at(i)){
            while (l - (len + 1) >= 0 && i + (len + 1) < s.length() && s.at(l - (len + 1)) == s.at(i + (len + 1))) {
                len++;
            }

            if (len >= max) {
                max = len;
                pos = i;
                type = 0;
//                cout << "now is:" << s.at(pos) << endl;
            }
        }

    }
    if (type == 1)
        return s.substr(pos - max, 2 * max + 1);
    else
        return s.substr(pos - max - 1, 2 * max + 2);
    // return s.substr(pos,1);
}
};
// @lc code=end

