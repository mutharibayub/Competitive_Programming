#include <iostream>
#include <vector>
#include <array>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> isPrime(10000,true);
    for(int i=2;i<10000;i++)
    {
        if(isPrime[i])
        {
            for(int j=2*i;j<10000;j+=i)
            {
                isPrime[j] = false;
            }
        }
    }

    int t;
    cin>>t;
    while(t--)
    {
        int s,e;
        bool found = false;
        cin>>s>>e;
        vector<bool> done(10000,false);
        queue<array<int,2>> q;
        q.push({s, 0});
        while(!q.empty())
        {
            array<int,2> tmp = q.front();
            q.pop();
            done[tmp[0]] = true;
            if(tmp[0]==e)
            {
                cout << tmp[1] <<'\n';
                found = true;
                break; 
            }
            for(int pow=10;pow<=10000;pow*=10)
            {
                for(int i=0;i<=9;i++)
                {
                    int nextNum = (tmp[0]/pow)*pow + i*(pow/10) + tmp[0]%(pow/10);
                    if(nextNum >= 1000 && nextNum <= 9999 && isPrime[nextNum] && !done[nextNum])
                    {
                        q.push({nextNum, tmp[1]+1});
                    }
                }
            }
        }
        if(!found)
        {
            cout << "Impossible\n";
        }
    }   

    return 0;
}