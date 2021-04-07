#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    //freopen("D:\\11777.txt","r",stdin);
    short int term1,term2,Final,attend,ct1,ct2,ct3,t,i;
    float avg_ct,total;
    while(cin>>t)
    {
        for(i=1;i<=t;i++)
        {
            cin>>term1>>term2>>Final>>attend>>ct1>>ct2>>ct3;
            if(ct1>ct2)
            {
                if(ct2>ct3)
                    avg_ct=(ct1+ct2)/2.0;
                else
                    avg_ct=(ct1+ct3)/2.0;
            }
            else
            {
                if(ct1>ct3)
                    avg_ct=(ct1+ct2)/2.0;
                else
                    avg_ct=(ct2+ct3)/2.0;
            }

            total= term1+term2+Final+attend+avg_ct;

            if(total>=90)
                cout<<"Case "<<i<<": A"<<endl;
            else if(total>=80 && total<90)
                cout<<"Case "<<i<<": B"<<endl;
            else if(total>=70 && total<80)
                cout<<"Case "<<i<<": C"<<endl;
            else if(total>=60 && total<70)
                cout<<"Case "<<i<<": D"<<endl;
            else
                cout<<"Case "<<i<<": F"<<endl;
        }
    }
    return 0;
}
