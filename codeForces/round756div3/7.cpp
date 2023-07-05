#include <iostream>
#include <vector>

using namespace std;

int count(vector<vector<int>> &block, int n, int m)
{
    int cnt=0;
    for(int i=0;i<block.size();i++)
    {
        if(block[i].size())
        {
            int c = i;
            int r = 0;
            while(r<n&&c<m)
            {
                if(block[c].size()==0||block[c].back()<r)
                {
                    c++,r++;
                }
                else
                {
                    int tr = block[c].back()+1;
                    while(block[c].size()&&block[c].back()>=r)block[c].pop_back();
                    r = tr;
                    c++;
                }
            }
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int m1=(n+m)/2,m2=(n+m)/2;
        vector<vector<int>> block1(m1), block2(m2);
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            for(int j=0;j<m;j++)
            {
                if(s[j]=='0')continue;
                auto &block = ((i%2)^(j%2))?block2:block1;
                int rowNum = i;
                int colNum = (j+i)/2;
                block[colNum].push_back(i);
            }
        }
        cout << count(block1,n,m1)+count(block2,n,m2) << '\n';
    }

    return 0;
}