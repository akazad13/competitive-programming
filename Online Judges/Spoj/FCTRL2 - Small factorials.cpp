#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> fact[1002];

void factorial(int n)
{
    int ind=n-1;
    int temp=0;

    int Size = fact[ind].size();

    for(int i=0;i<Size;i++)
    {
        temp = temp+(fact[ind][i]*n);//cout<<temp<<endl;
        fact[n].push_back(temp%10);
       // cout<<temp%10<<endl;
        temp/=10;
    }

    while(temp)
    {
        fact[n].push_back(temp%10);
        temp/=10;
    }
    return ;
}

void print(int ind)
{
    //reverse(fact[ind].begin(),fact[ind].end());
    for(int i=fact[ind].size()-1;i>=0;i--)
    {
        printf("%d",fact[ind][i]);
    }
    printf("\n");
}

int main()
{
    int test,n;
    scanf("%d",&test);

    fact[1].push_back(1);

    for(int i=2;i<=100;i++)
    {
        factorial(i);
       // print(i);
        //cout<<"________________"<<endl;
    }

    while(test--)
    {
        scanf("%d",&n);
        print(n);
    }


}
