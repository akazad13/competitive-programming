#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
    //freopen("D:\\12342.txt","r",stdin);
    long long int income;
    unsigned int i,t;
    double tax,pay;

    while(cin>>t)
    {
        for(i=1;i<=t;i++)
        {
            cin>>tax;
            if(tax>1180000)
            {
                pay=(tax-1180000)*0.25+150000;
            }
            else if(tax>880000&&tax<=1180000)
            {
                pay=(tax-880000)*0.2+90000;
            }
            else if(tax>480000&&tax<=880000)
            {
                pay=(tax-480000)*0.15+30000;
            }
            else if(tax>180000&&tax<=480000)
            {
                pay=(tax-180000)*0.1;
            }
            else
                pay=0.0;
            if(pay==0.0)
                cout<<"Case "<<i<<": 0"<<endl;
            else if(pay>0&&pay<2000)
                cout<<"Case "<<i<<": 2000"<<endl;
            else
            {
                pay=ceil(pay);
                //cout<<"Case "<<i<<": "<<pay<<endl;
               printf("Case %u: %.0lf\n",i,pay);
            }
        }
    }
    return 0;
}
