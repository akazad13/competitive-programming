#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct data
{
    char c;
    int count;
};


int main()
{
    int n;

    while(cin>>n)
    {
        data res[27],temp;
        for(int i=0;i<26;i++)
        {
            res[i].c='A'+i;
            res[i].count=0;
        }
        char ch =getchar();
        while(n--)
        {
             while((ch=getchar())!='\n')
            {
                if(isalpha(ch))
                {
                    if(ch>='a'&&ch<='z')
                    {
                        ch-=32;
                    }

                    res[ch-'A'].count++;
                }
            }
        }

        for(int i=0;i<26;i++)
        {
            for(int j=0;j<25;j++)
            {
                if(res[j].count<res[j+1].count)
                {
                    temp=res[j];
                    res[j]=res[j+1];
                    res[j+1]=temp;
                }
            }
        }

        for(int i=0;i<26;i++)
        {
            if(res[i].count>0)
            printf("%c %d\n",res[i].c,res[i].count);
        }
    }
    return 0;

}
