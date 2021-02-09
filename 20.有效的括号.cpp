/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char > mstack;
        char cur = s.at(0);
        if(cur==']' ||cur=='}'||cur==')'){
            return false;
        }
        for (int i = 0; i < s.length(); i++)
        {
            cur = s.at(i);
            switch (cur)
            {
            case '{':
                mstack.push('}');
                break;
            case '(':
                mstack.push(')');
                break;
            case '[':
                mstack.push(']');
                break;
            default:
                if(mstack.empty() || cur != mstack.top()){
                    return false;
                }
                mstack.pop();
                break;
            }
        }
        if(mstack.empty())
            return true;
        return false;
    }
};
// @lc code=end

