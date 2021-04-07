#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    vector<string> res[5];

    string s1(2,' ');

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if((i+j)*(i+j)==10*i+j)
            {
               // res[0].push_back(10*i+j);
               s1[0] = '0'+i;
               s1[1] = '0'+j;
                //cout<<s1<<endl;
               res[0].push_back(s1);
            }
        }
    }

    string s2(4,' ');

    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            if((i+j)*(i+j)==100*i+j)
            {
                s2[0] = '0'+i/10;
                s2[1] = '0'+i%10;
                s2[2] = '0'+j/10;
                s2[3] = '0'+j%10;
                res[1].push_back(s2);
            }
        }
    }

    string s3(6,' ');

    for(int i=0;i<1000;i++)
    {
        for(int j=0;j<1000;j++)
        {
            if((i+j)*(i+j)==1000*i+j)
            {
                s3[0] = '0'+i/100;
                s3[1] = '0'+(i%100)/10;
                s3[2] = '0'+i%10;

                s3[3] = '0'+j/100;
                s3[4] = '0'+(j%100)/10;
                s3[5] = '0'+j%10;
                res[2].push_back(s3);
            }
        }
    }

    string s4(8,' ');

    for(int i=0;i<10000;i++)
    {
        for(int j=0;j<10000;j++)
        {
            if((i+j)*(i+j)==10000*i+j)
            {
                s4[0] = '0'+i/1000;
                s4[1] = '0'+(i/100)%10;
                s4[2] = '0'+(i/10)%10;
                s4[3] = '0'+i%10;

                s4[4] = '0'+j/1000;
                s4[5] = '0'+(j/100)%10;
                s4[6] = '0'+(j/10)%10;
                s4[7] = '0'+j%10;

                res[3].push_back(s4);
            }
        }
    }

    while(scanf("%d",&n)==1)
    {
        if(n==2)
        {
            //cout<<n<<endl;
            for(int i=0;i<res[0].size();i++)
                cout<<res[0][i]<<"\n";
           // cout<<"ok"<<endl;
        }
        else if(n==4)
        {
            //cout<<n<<endl;
            for(int i=0;i<res[1].size();i++)
                cout<<res[1][i]<<"\n";
        }
        else if(n==6)
        {
            for(int i=0;i<res[2].size();i++)
                cout<<res[2][i]<<"\n";
        }
        else
        {
          //  cout<<n<<endl;
            for(int i=0;i<res[3].size();i++)
                cout<<res[3][i]<<"\n";
        }

    }

    return 0;
}
