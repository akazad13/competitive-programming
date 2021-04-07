#include<iostream>

using namespace std;
long int temp;

long int BigMod(long int a,long int p,long int m)
{
    if(p==0)
        return 1;
    if(p%2==1)
        return ((a%m)*(BigMod(a,p-1,m))%m);
    else
         temp=BigMod(a,p/2,m)%m;
    return (temp*temp)%m;
}


int main()
{
    long int a,p,m;
    int test;
    while(cin>>test)
    {
        if(test==0)
            break;
         // cin>>test;
        while(test--)
        {

            cin>>a>>p>>m;
            {

                cout<<BigMod(a,p,m)<<endl;
            }
        //cin>>test;
        //cin>>test;
        //if(test==0)
          //  break;
        }
    }
    return 0;
}

