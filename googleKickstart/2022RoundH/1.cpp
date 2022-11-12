#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        ll L,N,pos=0,ans=0;
        char dir = 'C';
        cin>>L>>N;
        for(int i=0;i<N;i++)
        {
            ll Di, newPos, add=0;
            char Ci, newDir;
            cin>>Di>>Ci;
            if(pos==0)dir = Ci;
            if(Ci=='C')
            {
                newPos = pos+Di;
                if(newPos>=L)
                {
                    add+=newPos/L;
                    if(Ci!=dir)add=max(0ll, add-1);
                    newPos%=L;
                    dir = Ci;
                }
            }
            else
            {
                newPos = pos-Di;
                if(newPos<=0)
                {
                    add+=(-1*newPos/L)+(pos!=0);
                    if(Ci!=dir)add=max(0ll, add-1);
                    newPos=(newPos%L+L)%L;
                    dir = Ci;
                }
            }
            pos = newPos;
            ans += add;
        }
        cout << "Case #" << t << ": " << ans << '\n';
    }   


    return 0;
}