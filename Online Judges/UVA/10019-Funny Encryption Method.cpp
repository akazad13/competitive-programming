#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int Bin_1(int num)
{
    int sum=0;
    while(num!=0)
    {
        sum += num%2;
        num/=2;
    }
    return sum;
}

int HEX(int num)
{
    int hex;
    int sum=0;
    while(num!=0)
    {
        hex = num%10;

        sum+=Bin_1(hex);
       // cout<<sum<<endl;

        num/=10;
    }

    return sum;

}

int main()
{
    int test,num;
    cin>>test;
    while(test--)
    {
        cin>>num;
        int bin1 = Bin_1(num);
        int bin2 = HEX(num);
        printf("%d %d\n",bin1,bin2);
    }
}
