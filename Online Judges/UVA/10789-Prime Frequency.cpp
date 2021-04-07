#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool prime[2020];

void sieve()
{
    int i,j;
    for(i=4;i<=2015;i+=2)
        prime[i]=1;
    for(i=3;i<=sqrt(2015);i+=2)
    {
        if(prime[i]==0)
        {
            for(j=i*i;j<=2015;j=j+2*i)
                prime[j]=1;
        }
    }
    prime[1]=1;
    prime[0]=1;
}

int main()
{
    sieve();

    int test;
    char str[2010];

    cin>>test;
    char c=getchar();

    for(int i=1;i<=test;i++)
    {
        int flag=0;
        int Capital[28]={0};
        int Small[28]={0};
        int Digit[10]={0};

        gets(str);
        int length= strlen(str);

        for(int j=0;j<length;j++)
        {
            if(str[j]>='A'&&str[j]<='Z')
                Capital[str[j]-'A']++;

            else if(str[j]>='a'&&str[j]<='z')
                Small[str[j]-'a']++;

            else if(str[j]>='0'&&str[j]<='9')
                Digit[str[j]-'0']++;
        }
        cout<<"Case "<<i<<": ";
        for(int j=0;j<10;j++)
        {
            if(prime[Digit[j]]==0)
            {
                printf("%c",j+'0');
                flag=1;
            }
        }
        for(int j=0;j<26;j++)
        {
            if(prime[Capital[j]]==0)
            {
                printf("%c",j+'A');
                flag=1;
            }
        }
        for(int j=0;j<26;j++)
        {
            if(prime[Small[j]]==0)
            {
                printf("%c",j+'a');
                flag=1;
            }
        }

        if(flag==0)
            cout<<"empty";
        cout<<"\n";
    }

    return 0;

}
