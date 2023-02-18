#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }

    int ans = 0;
    vector<int> main(k, -1);
    main[0]=0;
    for(int i=0;i<n;i++)
    {
        vector<vector<int>> nums(m+1, vector<int>(k, -1));
        nums[0][0]=0;
        for(int j=0;j<m;j++)
        {
            for(int cnt=m/2-1;cnt>=0;cnt--)
            {
                for(int i1=0;i1<k;i1++)
                {
                    if(nums[cnt][i1]==-1)continue;
                    nums[cnt+1][(i1+mat[i][j])%k]=max(nums[cnt+1][(i1+mat[i][j])%k], nums[cnt][i1]+mat[i][j]);
                }
            }
        }
        vector<int> tmp = main;
        for(int j=0;j<k;j++)
        {
            if(tmp[j]==-1)continue;
            for(int cnt=m/2;cnt>=0;cnt--)
            {
                for(int i1=0;i1<k;i1++)
                {
                    if(nums[cnt][i1]==-1)continue;
                    main[(i1+j)%k]=max(main[(i1+j)%k], tmp[j]+nums[cnt][i1]);
                }
            }
        }
    }

    cout << main[0] << '\n';


    return 0;
}