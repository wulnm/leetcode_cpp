class Solution
{
public:
    int father[1005];

    int find(int x)
    {
        if (father[x] < 0 || father[x] == x)
            return x;
        int t = find(father[x]);
        father[x] = t;
        return t;
    }

    void merge(int a, int b)
    {
        // 以小为father
        if(a<=b)
            father[find(b)] = find(a);
        else
            father[find(a)] = find(b);
    }

    bool inTheSame(int a, int b)
    {
        int ta = find(a);
        int tb = find(b);
        return find(a) == find(b);
    }

    int makeConnected(int n, vector<vector<int> > &connections)
    {
        int conCnt = 0, dsuCnt = n;
        for (int i = 0; i < n; i++)
        {
            father[i] = i;
        }
        // 遍历线进行并查集操作
        for (int i = 0; i < connections.size(); i++)
        {
            int a = connections.at(i).at(0);
            int b = connections.at(i).at(1);
            if (inTheSame(a, b))
            {
                conCnt++;// 空闲线数 + 1
            }
            else
            {
                merge(a, b);
                dsuCnt--; // 更新并查集数量
            }
        }

        //return (conCnt >= dsuCnt - 1)?dsuCnt - 1:-1;
        return dsuCnt - 1;
    }
};