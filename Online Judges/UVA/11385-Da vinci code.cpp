#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct vin
{
    char charac;
    int serial;
};

bool cmp(vin a,vin b)
{
    return a.serial<b.serial;
}

int main()
{
    map<int,int>myMap;

    long long int fib[100];

    fib[1]=1;
    fib[2]=2;

    for(int i=3;i<45;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
       // cout<<fib[i]<<endl;
    }

    for(int i=1;i<45;i++)
    {
        myMap[fib[i]]=i;
    }

    int test;

    long long int temp;



    cin>>test;
    while(test--)
   {
       vin data[105];

        int n;

        cin>>n;

        char str[200];

        for(int i=0;i<n;i++)
        {
            cin>>temp;
            data[i].serial=myMap[temp];
        }

        int i=0;
        char ch=getchar();

        gets(str);

        int len=strlen(str);

        for(int k=0;k<len;k++)
        {
            if(str[k]>='A'&&str[k]<='Z')
            {
                data[i++].charac=str[k];
            }
        }

        sort(data,data+n,cmp);

        for(int k=1;k<data[0].serial;k++)
            printf(" ");
        printf("%c",data[0].charac);

        for(i=1;i<n;i++)
        {
            if((data[i].serial)==(data[i-1].serial+1))
            {
                printf("%c",data[i].charac);
            }
            else
            {
                for(int k=data[i-1].serial+1;k<data[i].serial;k++)
                    printf(" ");
                printf("%c",data[i].charac);
            }
        }

        printf("\n");


   }

     myMap.clear();


    return 0;
}

