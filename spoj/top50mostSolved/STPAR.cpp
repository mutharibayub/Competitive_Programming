#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    while(n!=0)
    {
        vector<int> trucks(n);
        for(int i=0;i<n;i++)
        {
            cin>>trucks[i];
        }
        stack<int> sideStreet;
        int trucksOrdered = 0;
        for(int i=0;i<n;i++)
        {
            while(sideStreet.size()>0 && sideStreet.top()==trucksOrdered+1)
            {
                sideStreet.pop();
                trucksOrdered++;                
            }
            if(trucks[i]==trucksOrdered+1)
            {
                trucksOrdered++;
            }
            else
            {
                sideStreet.push(trucks[i]);
            }
        }
        while(sideStreet.size()>0 && sideStreet.top()==trucksOrdered+1)
        {
            sideStreet.pop();
            trucksOrdered++;                
        }
        if(trucksOrdered==n)
        {
            cout<<"yes\n";
        }
        else
        {
            cout<<"no\n";
        }

        cin>>n;
    }
}