#include<iostream>
#include<cstdio>
#include <iomanip>
using namespace std;

int main()
{
    long long int num;

    while(cin>>num){

    long long int line;

    line = (num/2)+1;

   long long int last = 2*(line*line)-1;
    cout<<fixed;
   cout<<setprecision(0)<<last+last+last-6<<endl;
    }

    return 0;
}
