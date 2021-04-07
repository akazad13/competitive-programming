#include<iostream>

using namespace std;

int main()
{
    int Player, K, Pass,temp,t,R,i;

    while(cin>>t)
    {
        for(i=1;i<=t;i++)
        {
            cin>>Player>>K>>Pass;

            R=Pass%Player+K;
            if(R>Player)
              R=R-Player;

            cout<<"Case "<<i<<": "<<R<<endl;
        }
    }
    return 0;
}
