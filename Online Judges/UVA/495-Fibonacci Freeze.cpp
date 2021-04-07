#include<iostream>
#include<bits/stdc++.h>

using namespace std;

char sum[5010][50000];


void Fib()
{
    sum[0][0]='0';
    sum[1][0]='1';
    for(int num=2;num<=5001;num++)
    {
        int len1=strlen(sum[num-1]);
        int len2=strlen(sum[num-2]);

      //  cout<<"length: "<<len1<<" "<<len2<<endl;
        int l_low,l_high;

        if(len1<=len2)
        {
            l_low=len1;
            l_high=len2;
        }
        else
        {
            l_low=len2;
            l_high=len1;
        }

        int temp=0;

        for(int i=1;i<=l_low;i++)
        {
            temp=((sum[num-1][len1-i]-'0')+(sum[num-2][len2-i])-'0')+temp;
      //  cout<<temp<<endl;
            sum[num][(l_high+1)-i]=(temp%10)+'0';
       // cout<<sum[i]<<endl;
            temp=temp/10;

        }

   // cout<<sum[num]<<endl;

        if(l_low==len1)
        {
        //cout<<"in if: "<<sum<<endl;
            int k;
            for(k=len2-len1-1;k>=0;k--)
            {
                temp=sum[num-2][k]-'0'+temp;
                sum[num][k+1]=(temp%10)+'0';
                temp=temp/10;
            }

            if(temp>0)
            {
                sum[num][k+1]=temp+'0';
            }
            else
                sum[num][k+1]='0';

            sum[num][len2+1]='\0';
        }



        else if(l_low==len2)
        {
       // cout<<"in else: "<<sum<<endl;
            int k;
            for(k=len1-len2-1;k>=0;k--)
            {
                temp=sum[num-1][k]-'0'+temp;
                sum[num][k+1]=(temp%10)+'0';
                temp=temp/10;
            }

            if(temp>0)
            {
                sum[num][k+1]=temp+'0';
            }
            else
                sum[num][k+1]='0';
            sum[num][len1+1]='\0';
        }
    //cout<<sum<<endl;
    }
    return ;
}

int main()
{
   // freopen("Fib.txt","w",stdout);


    //cout<<sum[0]<<" "<<sum[1]<<endl;
    Fib();
    int n;

    while(cin>>n)
    {
        printf("The Fibonacci number for %d is ",n);
        if(n==0)
        {
            cout<<0<<"\n";
            continue;
        }
        int len=strlen(sum[n]);

        int flag=0;

        for(int i=0;i<len;i++)
        {
            if(flag==0&&sum[n][i]=='0')
                continue;
            else
            {
                flag=1;
                printf("%c",sum[n][i]);
            }
        }
        cout<<"\n";
    }

    return 0;
}

