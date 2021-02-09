/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    struct Node
    {
        int lSum, // 以l为开始的区间最大子序和
        rSum,     // 以r为开始的区间最大子序和
        mSum,     // l,r的区间最大子序和
        wSum; // 整段区间和
    };

    Node pushUp(Node a, Node b){
        Node t;
        t.wSum = a.wSum + b.wSum;
        t.lSum = max(a.lSum,a.wSum+b.lSum);
        t.rSum = max(b.rSum,b.wSum+a.rSum);
        t.mSum = max(max(a.mSum,b.mSum),a.rSum+b.lSum);
        return t;
    }
    
    Node get(vector<int > &a,int l,int r){
        if(l == r)
            return (Node){a[l],a[l],a[l],a[l]};
        int mid = (l+r)/2;
        Node left = get(a,l,mid);
        Node right = get(a,mid+1,r);
        return pushUp(left,right);
    }

    int maxSubArray(vector<int>& nums) {
        return get(nums,0,nums.size()-1).mSum;
    }
    int maxSubArray2(vector<int>& nums) {
        int max = nums[0];
        int pre=0;
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            pre = (pre + x) > x?(pre + x):x;
            max = max>pre?max:pre;
        }
        
        return max;
    }   
};
// @lc code=end

