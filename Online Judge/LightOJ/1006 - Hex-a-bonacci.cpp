#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
    long long int a, b, c, d, e, f,n;
    int test;
    cin>>test;
    for(int k=1;k<=test;k++) {
        cin>>a>>b>>c>>d>>e>>f>>n;
        int i;

        long long int arr[10010];

        arr[0]=a;
        arr[1]=b;
        arr[2]=c;
        arr[3]=d;
        arr[4]=e;
        arr[5]=f;

        for(i=6;i<=n;i++)
        {
            arr[i]=(arr[i-1]+arr[i-2]+arr[i-3]+arr[i-4]+arr[i-5]+arr[i-6])%10000007;
        }
        printf("Case %d: %lld\n",k, arr[n]%10000007);
    }
    return 0;
}
