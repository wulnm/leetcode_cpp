/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
    char cres[10005];
    cres[0] = '1';
    string res = "1";
    int pos=1;
    for (int i = 2; i <=n; i++)
    {
        pos=0;
        char last = res.at(0),c=last;
        int cnt=1;
        for (int j = 1; j < res.length(); j++)
        {
            c = res.at(j);
            if(c==last)
                cnt++;
            else{
                cres[pos++] = cnt + '0';
                cres[pos++] = last;
                cnt = 1;
                last = c;
            }

        }
        cres[pos++] = cnt + '0';
        cres[pos++] = c;
        cres[pos] = '\0';
        res = cres;
        // cout<<"n:"<<i<<"  ->  "<<res<<endl;
    }
    return res;
}
};
// @lc code=end

