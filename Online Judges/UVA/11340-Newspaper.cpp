#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;

    cin>>test;

    while(test--)
    {
        int char_no;
        char temp;
        cin>>char_no;

        char ch=getchar();

        //map<char, int> value;

        int value[261]={0};

       // int lValue[110]={0};

        map<char, int> track;

        for(int i=0;i<char_no;i++)
        {
            cin>>temp;
            cin>>value[temp];

            //cout<<temp<<endl;

            //cout<<value[temp]<<endl;
        }

        int line;

        cin>>line;

        ch= getchar();

        char str[1000000];

        while(line--)
        {
            gets(str);
            int l=strlen(str);
            for(int i=0;i<l;i++)
            {
                track[str[i]]++;
            }
        }

        double sum=0.0;

        for(int i=0;i<260;i++)
        {
            //cout<<track[i]<<endl;
            //cout<<value[i]<<endl;
            sum+=track[i]*value[i];
        }

        sum=sum/100;

        printf("%.2f$\n",sum);
    }

    return 0;
}
