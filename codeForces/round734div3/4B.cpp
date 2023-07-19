#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> left(m, n);
        vector<string> grid(n, string(m, 0));
        bool check=true;
        int chr = 0;
        
        if(n%2)
        for(int i=0;i<m;i+=2)
        {
            if(!k)
            {
                check=false;
                break;
            }
            else
            {
                k--;
                grid[n-1][i]=grid[n-1][i+1]=chr+'a';
                chr=(chr+1)%26;
                left[i]=left[i+1]=n-1;
            }
        }
        
        if(k%2)check=false;
        
        if(check)
        for(int col=0;col+1<m&&k;col+=2)
        {
            int toAdd=min(k, left[col]);
            for(int j=0;j<toAdd;j++)
            {
                int row=left[col]-1-j;
                bool out=false;
                while(!out)
                {
                    out=true;
                    if(row+1<n&&(chr+'a'==grid[row+1][col]||chr+'a'==grid[row+1][col-1]))out=false;
                    if(col-1>=0 && chr+'a'==grid[row][col-1])out=false;
                    if(!out)chr=(chr+1)%26;
                }
                grid[row][col]=grid[row][col+1]=chr+'a';
                chr=(chr+1)%26;
            }
            left[col]=left[col+1]=left[col]-toAdd;
            k-=toAdd;
        }
        if(!k&&check)
        {
            for(int col=0;col<m;col++)
            {
                for(int row=left[col]-1;row>=0;row-=2)
                {
                    bool out=false;
                    while(!out)
                    {
                        out=true;
                        if(row+1<n && chr+'a'==grid[row+1][col])out=false;
                        if(col-1>=0 && (chr+'a'==grid[row][col-1]||chr+'a'==grid[row-1][col-1]))out=false;
                        if(!out)chr=(chr+1)%26;
                    }
                    grid[row][col]=grid[row-1][col]=chr+'a';
                    chr=(chr+1)%26;
                }
            }
            cout << "YES" << '\n';
            for(int i=0;i<n;i++)
            {
                cout << grid[i] << '\n';
            }
        }
        else
        {
            cout << "NO" << '\n';
        }
    }

    return 0;
}