/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void swap(int &a, int &b){
        int c = a;
        a = b;
        b = c;
    }
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size() < 2)
            return ;
        int l=0,r = matrix.size()-1; // 目前旋转的正方形区域左右(上下)下标
        while(r > l){
            for (int i = 0; i < r-l; i++)
            {
                int cur = matrix[l][l+i];
                swap(matrix[l+i][r],cur);
                // cout<<"cur:"<<cur<<" swap-> "<<matrix[r][r-i]<<"\n";
                swap(matrix[r][r-i],cur);
                // cout<<"cur:"<<cur<<" swap-> "<<matrix[r-i][l]<<'\n';
                swap(matrix[r-i][l],cur);
                // cout<<"cur:"<<cur<<" swap-> "<<matrix[l][l+i]<<'\n';
                swap(matrix[l][l+i],cur);
                
            }
            l++;
            r--;
        }
    }
};
// @lc code=end

