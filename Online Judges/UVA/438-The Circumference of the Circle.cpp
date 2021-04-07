#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;

int main()
{
    freopen("E:\\1.txt","r",stdin);
    freopen("E:\\2.txt","w",stdout);
    double a,b,c,d,e,f,x,y,radious,temp;
    while(cin>>a>>b>>c>>d>>e>>f)
    {
        temp=2*((a-c)*(b-f)-(b-d)*(a-e));

        x=(((b-d)*((e*e)+(f*f)))+((d-f)*((a*a)+(b*b)))-((b-f)*((c*c)+(d*d))))/temp;
        y=(((a-e)*((c*c)+(d*d)))+((e-c)*((a*a)+(b*b)))-((a-c)*((e*e)+(f*f))))/temp;

        radious= sqrt((pow((x-a),2)+pow((y-b),2)));

        printf("%.2f\n",2*acos(-1)*radious);
    }

    return 0;
}
