#include <iostream>
#include <string>
using namespace std;

void testCase()
{
    int r,c;
    cin>>r>>c;
    r=r*2+1;
    c=c*2+1;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(i<2 && j<2)cout<<'.';
            else if(!(i%2))
            {
                if(!(j%2))
                {
                    cout<<'+';
                }
                else
                {
                    cout<<'-';
                }
            }
            else
            {
                if(!(j%2))
                {
                    cout<<'|';
                }
                else
                {
                    cout<<'.';
                }
            }
        }
        cout<<endl;
    }
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cout<<"Case #"<<to_string(i+1)<<":\n";
        testCase();
    }
    return 0;
}