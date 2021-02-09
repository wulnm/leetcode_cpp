/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution
{
public:
    int reverse(int x) {
    int res = 0;
    int cnt = 0; //int32是10位数
    int int32 = 1000000000;
    int flag = 0;//flag为1则说明反转后不会越界,-1则为会发生越界.
    while (x != 0) {
        int num = x % 10;
        if (flag == 0) {
            int temp = 0;
            if (x > 0)
                temp = 2147483647;
            else
                temp = -2147483648;

            if (abs(num) > abs(temp / int32 % 10))
                flag = -1;
            else if (abs(num) < abs(temp / int32 % 10))
                flag = 1;
        }

        cnt++;
        // 判断是否大于int32
        if (cnt == 10 && flag==-1)
            return 0;

        res = res * 10 + num;
        x /= 10;
        int32 /= 10;
    }

    return res;
}
};
// @lc code=end
