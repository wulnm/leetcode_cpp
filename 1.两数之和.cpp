/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int ,int >  map;
        for(int i=0;i<nums.size();i++){
            // 返回值: (http://www.cplusplus.com/reference/unordered_map/unordered_map/find/)
            // An iterator to the element, if the specified key value is found, 
            // or unordered_map::end if the specified key is not found in the container.
            if(map.find(target - nums[i]) != map.end()){ // end不是任何一个被插入的元素
                return {i,map[target - nums[i]]};
            }
            map.insert({nums[i],i});
        }
        return {};
    }
};
// @lc code=end

