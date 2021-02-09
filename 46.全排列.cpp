/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    bool tag[10005];
    vector<int > input;
    int n;
    void dfs(vector<int > item){
        if(item.size() == n){
            res.push_back(item);
            return;
        }
            
        for (int i = 0; i < n; i++)
        {
            if(!tag[i]){
                tag[i] = true;
                item.push_back(input[i]);
                dfs(item);
                item.pop_back();
                tag[i]=false;
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        int mul=1;
        for (int i = 1; i <= n; i++)
        {
            mul*=i;
        }
        res.reserve(mul);
        input = nums;
        dfs({});
        return res;
    }
};
// @lc code=end

