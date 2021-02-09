/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution
{
public:
    vector<int> input;
    int binFind(int l, int r, int v)
    {
        if (l > r)
            return -1;
        int mid = (l + r) / 2;
        if (input[mid] == v)
        {
            return mid;
        }
        if (v < input[mid])
        {
            return binFind(l, mid - 1, v);
        }
        else
        {
            return binFind(mid + 1, r, v);
        }
        return -1;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        input = nums;
        int left = binFind(0, nums.size()-1, target);
        int right = left;
        // cout << "first find : " << left << endl;
        while (left > 0 && nums[left - 1] == target)
        {
            int tmp = binFind(0, left - 1, target);
            if (tmp != -1)
                left = tmp;
        }
        while (right<nums.size() - 1 && nums[right + 1] == target)
        {
            int tmp = binFind(right + 1, nums.size() - 1, target);
            if (tmp != -1)
                right = tmp;
        }

        return {left, right};
    }
};
// @lc code=end
