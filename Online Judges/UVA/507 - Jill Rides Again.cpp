                        /* Md. Abul Kalam Azad */
                         /* CSE-13  , @RUET */
                         /* cell-01686871012*/
                       /* Cool Ur head & Think */


#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Macros
#define llread(a) scanf("%lld",&a)
#define read(a) scanf("%d",&a)
#define write(a) printf("%d\n",a)
#define CLEAR(a,b) memset(a,b,sizeof(a))
#define VI(a) vector<a>
#define MA(a,b) map<a,b>

#define lld long long int
#define ulld unsigned long long int
#define dd double
#define ud unsigned long long int
#define PI acos(-1.0)
#define Gamma 0.5772156649015328606065120900824024310421

//End Macros



/* My note:-
    1. Can i solve the sub-problem of that problem
    2. Can i solve the whole problem
    3. Do i check the parameter
    4. Did i clear all the memory
    5. check whether DP is cleared
    6. Understand the prob?! check again!!!

End of my note */

typedef struct res{
    int i;
    int j;
    int sum;
}res;

struct res Kadane(int arr[],int n)
{
    struct res maax, max_cur;
    struct res *max_sub;

    max_sub = (struct res* ) calloc(n,sizeof(res));
    maax.sum = -1*INT_MAX;
    max_cur = maax;

    for(int i=0;i<n;i++)
    {
        if(max_cur.sum<0)
        {
            max_cur.sum = arr[i];
            max_cur.i = i;
            max_cur.j = i;
        }
        else
        {
            max_cur.sum += arr[i];
            max_cur.j = i;
        }

        if(maax.sum==max_cur.sum)
        {
            if(maax.j-maax.i<max_cur.j-max_cur.i)
                maax = max_cur;

        }

        else if(maax.sum<max_cur.sum)
        {
            maax = max_cur;
        }

        max_sub[i] = maax;
    }

    return max_sub[n-1];
}

int main()
{
  //  freopen("input.txt","r",stdin);
    int n,arr[200010];
    int test;
    scanf("%d",&test);
    int cnt=1;
    while(test--)
    {
        scanf("%d",&n);
        for(int i=0;i<n-1;i++)
        {
            cin>>arr[i];
        }

        struct res calResult = Kadane(arr,n-1);

        //cout<<calResult.i<<" "<<calResult.j<<" "<<calResult.sum<<endl;
        if(calResult.sum<0)
        {
            printf("Route %d has no nice parts\n",cnt++);
        }
        else
        {
            printf("The nicest part of route %d is between stops %d and %d\n",cnt++,(calResult.i)+1,(calResult.j)+2);
        }

    }

    return 0;
}


