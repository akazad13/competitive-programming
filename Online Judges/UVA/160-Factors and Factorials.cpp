#include<bits/stdc++.h>

using namespace std;

int get_pow(int num, int p)
{
    int res=0;
    for(int power=p;power<=num;power=power*p)
        res+=(num/power);
    return res;
}

int main()
{
    int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int List[26]={0};
    int num;
    while(cin>>num,num)
    {
        printf("%3d! =",num);
        for(int i=0;i<25;i++)
        {
            List[i]=get_pow(num,prime[i]);
        }
        int k=0;
        for(int i=0;List[i]!=0;i++)
        {
            if(k>14)
                {
                    cout<<"\n      ";
                    k=0;
                }
            printf("%3d",List[i]);
            k++;
        }
        cout<<"\n";
    }

    return 0;
}
