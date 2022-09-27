#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,d12,d23,d31,nextNode=4;
        cin>>n>>d12>>d23>>d31;
        if(d12+d23==d31 || d23+d31==d12 || d31+d12==d23)
        {
            vector<int> mainChain;
            int maxVal = max(d12,max(d23,d31));
            int first,second,third,len1,len2;
            if(maxVal==d12)
            {
                first = 1, second = 3, third = 2, len1 = d31, len2 = d23;
            }
            else if(maxVal==d23)
            {
                first = 2, second = 1, third = 3, len1 = d12, len2 = d31;
            }
            else
            {
                first = 3, second = 2, third = 1, len1 = d23, len2 = d12;
            }
            mainChain.push_back(first);
            for(int i=0;i<len1-1;i++)
            {
                mainChain.push_back(nextNode++);
            }
            mainChain.push_back(second);
            for(int i=0;i<len2-1;i++)
            {
                mainChain.push_back(nextNode++);
            }
            mainChain.push_back(third);
            while(nextNode<n+1)
            {
                mainChain.push_back(nextNode++);
            }
            cout << "YES\n";
            for(int i=0;i<mainChain.size()-1;i++)
            {
                cout << mainChain[i] << ' ' << mainChain[i+1] << '\n';
            }
        }
        else if((d12+d23-d31)%2==0 && d12+d23-d31>0 && d23+d31-d12>0 && d31+d12-d23>0 && (d12+d23+d31)/2<n)
        {
            int len1 = (d12+d31-d23)/2, len2 = (d12+d23-d31)/2, chain2Len = (d23+d31-d12)/2;
            vector<int> mainChain = {1}, secondChain;
            for(int i=0;i<len1+len2-1;i++)
            {
                mainChain.push_back(nextNode++);
                if(i==len1-1)
                {
                    secondChain.push_back(nextNode-1);
                    for(int j=0;j<chain2Len-1;j++)
                    {
                        secondChain.push_back(nextNode++);
                    }
                    secondChain.push_back(3);
                }
            }
            mainChain.push_back(2);
            while(nextNode<n+1)
            {
                mainChain.push_back(nextNode++);
            }
            cout << "YES\n";
            for(int i=0;i<mainChain.size()-1;i++)
            {
                cout << mainChain[i] << ' ' << mainChain[i+1] << '\n';
            }
            for(int i=0;i<secondChain.size()-1;i++)
            {
                cout << secondChain[i] << ' ' << secondChain[i+1] << '\n';
            }
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}