/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution
{
public:
    char cres[10];
    string sres;
    vector<string> res;
    int cnt;
    string input;
    unordered_map<char, string> mat {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};

    void dfs(int index)
    {
        if (index == input.length())
        {
            sres = cres;
            res.push_back(sres);
            return;
        }

        for (int i = 0; i < mat[input.at(index)].length(); i++)
        {
            cres[index] = mat[input.at(index)].at(i);//根据映射生成字符
            dfs(index+1);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if(digits.length()==0)
            return res;
        input = digits;
        dfs(0);
        return res;
    }
};
// @lc code=end
