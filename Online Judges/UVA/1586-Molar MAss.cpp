#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    int val[102];
    char Mol[100];

    char c;
    cin>>test;
    c=getchar();
    while(test--)
    {

        int l;
        double total_weight;
        for(int i=0;i<=100;i++)
            val[i]=0;
        gets(Mol);
        l=strlen(Mol);
       
        for(int i=0;i<l;i++)
        {
          
            if(isalpha(Mol[i]))
            {
                if(isdigit(Mol[i+1])&&isdigit(Mol[i+2]))
                   {
                       val[Mol[i]]+=((Mol[i+1]-'0')*10)+(Mol[i+2]-'0');
                       i=i+2;
                   }
                else if(isdigit(Mol[i+1]))
                    {
                        //cout<<val[Mol[i]]<<endl;
                        val[Mol[i]]+=(Mol[i+1]-'0');
                        //cout<<val[Mol[i]]<<endl;
                        i++;
                    }
                else
                {
                    val[Mol[i]]+=1;
                }
            }
        }

        total_weight=val['C']*12.01+val['H']*1.008+val['O']*16.00+val['N']*14.01;

        printf("%.3f\n",total_weight);
        //c=getchar();

    }
}
