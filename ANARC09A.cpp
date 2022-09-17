#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int t=1;;t++)
    {
        string s;
        cin>>s;
        if(s[0]=='-')break;
        int counter = 0;
        int changes = 0;
        for(int i=0;s[i];i++)
        {
            if(s[i]=='{')
            {
                counter++;
            }
            else
            {
                if(counter == 0)
                {
                    counter++;
                    changes++;
                }
                else
                {
                    counter--;
                }
            }
        }
        changes += counter/2;
        cout << t << ". " << changes <<'\n';
    }
    return 0;
}