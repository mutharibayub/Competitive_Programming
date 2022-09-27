#include <iostream>
#include <vector>
#include <string>
using namespace std;

void testCase(const int& tCount)
{
    int ec,wc;
    cin>>ec>>wc;
    int sum=0;
    vector<vector<int>> raw(ec,vector<int>(wc,0));    
    vector<vector<int>> push(ec,vector<int>(wc,0));
    vector<vector<int>> pop(ec,vector<int>(wc,0));
    for(int i=0;i<ec;i++)
    {
        for(int j=0;j<wc;j++)
        {
            cin>>raw[i][j];
            if(i==0)
            {
                push[i][j]=raw[i][j];
            }
            else
            {
                if(raw[i][j]-raw[i-1][j]>0)
                {
                    push[i][j]=raw[i][j]-raw[i-1][j];
                }
                else
                {
                    pop[i][j]=raw[i-1][j]-raw[i][j];
                }
            }
        }
    }
    // cout<<"__\n";
    // for(int i=0;i<ec;i++)
    // {
    //     for(int j=0;j<wc;j++)
    //     {
    //         cout<<push[i][j]<<" ";
    //     }cout<<endl;
    // }
    // cout<<"__\n";
    int popc=0;
    for(int i=1;i<ec;i++)
    {
        for(int j=0;j<wc;j++)
        {
            if(pop[i][j]!=0)
            {
                int req=pop[i][j];
                for(int k=0;k<i;k++)
                {
                    int subt = min(req,push[i-k-1][j]); 
                    req-=subt;
                    sum+=2*k*subt;
                    cout<<(2*k*subt)<<" added to sum for subt'ing: i="<<i<<",j="<<j<<",k="<<k<<endl;
                    popc+=2*k*subt;
                    if(k!=0)
                    {
                        push[i-k-1][j]-=subt;
                    }
                    if(req==0)
                    {break;}
                }
                push[i-1][j]=max(0,push[i-1][j]-pop[i][j]);
            }
            // cout<<i<<" "<<j<<": "<<sum<<endl;
            sum+=pop[i][j];
                    cout<<(pop[i][j])<<" added to sum for pop: i="<<i<<",j="<<j<<endl;
            sum+=push[i][j];
                    cout<<(push[i][j])<<" added to sum for push: i="<<i<<",j="<<j<<endl;

        }
    }
    // cout<<"PUSH MAT__\n";
    // for(int i=0;i<ec;i++)
    // {
    //     for(int j=0;j<wc;j++)
    //     {
    //         cout<<push[i][j]<<" ";
    //     }cout<<endl;
    // }cout<<"__\n";
    // cout<<"POP MAT__\n";
    // for(int i=0;i<ec;i++)
    // {
    //     for(int j=0;j<wc;j++)
    //     {
    //         cout<<pop[i][j]<<" ";
    //     }cout<<endl;
    // }cout<<"__\n";
    // }
    // cout<<popc<<endl;
    for(int i=0;i<wc;i++)
    {
        sum+=raw[0][i];
                    // cout<<(raw[0][i])<<" added to sum for firstLine"<<endl;
        sum+=raw[ec-1][i];
                    // cout<<raw[ec-1][i]<<" added to sum for lastLine"<<endl;

    }
    cout<<"Case #"+to_string(tCount)+": "<<sum<<endl;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        testCase(i+1);
    }
    return 0;
}