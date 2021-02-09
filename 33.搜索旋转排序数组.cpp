/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> input;
    int binFind(int l, int r, int v) {
        if (l > r)
            return -1;
        int mid = (l + r) / 2;
        // cout << "mid : "<<input[mid] << endl;
        if (input[mid] == v)
            return mid;
        // 找出有顺序的一边
        if (mid>0&&input[mid] > input[l]) {
            // 若左边有序且目标在其中
            if (input[l] <= v && v <= input[mid-1]) {
                // cout << "left" << endl;
                return binFind(l, mid - 1, v);
            } else if(mid<input.size()-1){
                // cout << "right" << endl;
                return binFind(mid + 1, r, v);
            }
        } else {
            // 右边有序且在目标在范围内
            if (mid<input.size()-1&&input[mid+1] <= v && v <= input[r]) {
                // cout << "right" << endl;
                return binFind(mid+1, r, v);
            } else if(mid>0){
                // cout << "left" << endl;
                return binFind(l, mid - 1, v);
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        input = nums;
        return binFind(0,nums.size()-1,target);
    }
};
// @lc code=end

