#include <iostream>

using namespace std;

#define ll long long

int main()
{
    int queryCount = 0;
    for(int i=2;i<27;i++)
    {
        ll a,b;
        cout << "? 1 " << i << endl;
        cin>>a;
        cout << "? " << i << " 1"<< endl;
        cin>>b;
        if(a==-1)
        {
            cout << "! " << i-1 << endl;
            return 0;
        }
        else if(a!=b)
        {
            cout << "! " << a+b << endl;
            return 0;
        }
    }
    cout << "! 1" << endl;
}