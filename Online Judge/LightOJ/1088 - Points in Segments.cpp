#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define read(n) scanf("%d",&n)

int main()
{
    int test,arr[100010],seg,n,p,q,element;
    read(test);

    for(int Case = 1 ; Case<=test ; Case++)
    {
        read(n);
        read(seg);
        for(int i=0;i<n;i++)
            read(arr[i]);
        printf("Case %d:\n",Case);
        for(int i=0;i<seg;i++)
        {
            read(p);read(q);

            element = upper_bound(arr,arr+n,q)-lower_bound(arr,arr+n,p);
            printf("%d\n",element);
        }
    }
    return 0;
}
