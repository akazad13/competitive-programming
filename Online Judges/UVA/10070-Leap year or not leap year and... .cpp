#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    char input[1000000];
    long long int length,value1,value2,sum,sum1,sum2,i,j=0;
    int p,q;

    while(gets(input))
    {
        if(j)
            cout<<"\n";
        p=1;
        q=1;
        sum=0;
        sum1=0;
        sum2=0;
        length=strlen(input);
        value1=((input[length-2]-'0')*10)+(input[length-1]-'0');
        value2=((input[length-4]-'0')*1000)+((input[length-3]-'0')*100)+((input[length-2]-'0')*10)+(input[length-1]-'0');
        if((((value1%4)==0)&&(value1!=0))||((value2%400)==0))
           {
               cout<<"This is leap year."<<endl;
               p=0;
               q=0;
           }

        if((input[length-1]-'0')%5==0)
        {
            for(i=0;i<length;i++)
            {
                sum+=(input[i]-'0');
                if(i%2==0)
                {
                    sum1+=(input[i]-'0');
                }
                else if(i%2==1)
                {
                    sum2+=(input[i]-'0');
                }
            }
            if(sum%3==0)
                {
                    cout<<"This is huluculu festival year."<<endl;
                    q=0;
                }

            if(((sum1-sum2)%11==0)&&(p==0))
                {
                    cout<<"This is bulukulu festival year."<<endl;
                }
        }

        if(q==1)
            cout<<"This is an ordinary year."<<endl;
        j++;
    }
    return 0;
}
