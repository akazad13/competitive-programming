#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
    int n,i=0;

    double Ha, Hb, Hc, p;
    cin>>n;
    while(cin>>Ha>>Hb>>Hc)
    {
        if(n==i)
            break;
        if(Ha==0||Hb==0||Hc==0)
        {
            i++;
            cout<<"These are invalid inputs!"<<endl;
        }
        else
        {
            p=((1/Ha)+(1/Hb)+(1/Hc))*((1/Hb)+(1/Hc)-(1/Ha))*((1/Hc)+(1/Ha)-(1/Hb))*((1/Ha)+(1/Hb)-(1/Hc));
            if(p>0)
            {
                p=1/p;
                printf("%.3lf\n",sqrt(p));
            }
            else
            {
                 i++;
                cout<<"These are invalid inputs!"<<endl;
            }
        }
    }
    return 0;
}
