/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        int mat[strs.size()][26];
        int cnt = 0;
        bool flag = false;
        vector<vector<string>> res;
        int tmat[26];
        for (int i = 0; i < strs.size(); i++)
        {
            // 初始化
            for (int k = 0; k < 26; k++)
            {
                tmat[k] = 0;
            }
            // 遍历所有字符
            for (int k = 0; k < strs[i].length(); k++)
            {
                
                tmat[strs[i].at(k) - 'a']++;
            }
            // 遍历已存在的集合
            for (int j = 0; j < cnt; j++)
            {
                flag = false;
                // cout<<"cur string : "<<strs[i]<<endl;
                for (int k = 0; k < 26; k++)
                {
                    if (tmat[k] != mat[j][k])
                    {
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    res[j].push_back(strs[i]);
                    break;
                }
                    
            }
            // 若不与存在集合同字母或者目前集合,
            // 则创建新集合
            if (flag == true || cnt == 0)
            {
                vector<string> tmp;
                tmp.push_back(strs[i]);
                for (int k = 0; k < 26; k++)
                {
                    mat[cnt][k] = tmat[k];
                }
                cnt++;
                res.push_back(tmp);
            }
        }

        return res;
    }
};
// @lc code=end
