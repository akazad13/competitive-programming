#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

char line[1000006];

int main()
{
    int p=1;
    long int k,l,test,i=1;;

    while(scanf("%s",line)==1)
    {
        if(strlen(line)==0)
            break;
        cin>>test;

        cout<<"Case "<<i<<":"<<endl;

        while(test--)
        {
            scanf("%ld%ld",&k,&l);
            p=1;
            if(k==l)
            {
                cout<<"Yes"<<endl;
                continue;
            }

            if(k>l)
                swap(k,l);

            for(long int m=k;m<l;m++)
            {
                if(line[m]!=line[m+1])
                {
                    p=0;
                    break;
                }
            }

            if(p)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;

        }
        i++;
    }
    return 0;
}
