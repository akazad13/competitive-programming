#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node
{
    int ind,val;
};
node arr[500010];
int sqArr[500010];
int n;

#define lld long long int

//segmented tree

struct ak
{
    lld val,prop;
};

ak tree[1500010];

void build(int Node, int start, int eend)
{
    if(start==eend)
    {
        tree[Node].val = 0;
        tree[Node].prop = 0;

        return ;
    }

    int mid  = (start+eend)>>1;

    build(Node<<1, start, mid);
    build((Node<<1)+1 , mid+1, eend);

    tree[Node].val = tree[Node<<1].val + tree[(Node<<1)+1].val;

    return ;
}

void update(int Node, int start, int eend, int left, int Right, lld x)
{
    if(start>Right || eend<left)
    {
        return ;
    }

    if(start>=left && eend<=Right)
    {
        tree[Node].prop+=x;
        tree[Node].val += (eend-start+1)*x;

        return ;
    }

    int mid  = (start+eend)>>1;

    update(Node<<1, start, mid,left,Right,x);
    update((Node<<1)+1 , mid+1, eend, left, Right,x);

    tree[Node].val = tree[Node<<1].val + tree[(Node<<1)+1].val + (eend-Right+1)*tree[Node].prop;

    return ;
}

lld query(int Node, int start, int eend, int ind, lld car)
{
    if(eend<ind || ind<start)
        return 0;
    if(start==ind && eend==ind)
    {
        return tree[Node].val+(eend-start+1)*car;
       // return ;

    }

    int mid = (start+eend)>>1;

    lld t1 = query(Node<<1,start,mid,ind,car+tree[Node].prop);
    lld t2 = query((Node<<1)+1,mid+1,eend,ind,car+tree[Node].prop);

   // ans+=tree[node<<1].sum+tree[(node<<1)+1].sum;

    return t1+t2;


}

//segmented tree



bool cmp(node a, node b)
{
    return a.val<b.val;
}

int main()
{

    while(scanf("%d",&n)==1)
    {
        if(n==0) break;

        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i].val);
            arr[i].ind = i;
        }

        sort(arr,arr+n,cmp);

        for(int i=0;i<=3*n;i++)
        {
            tree[i].val=0;
            tree[i].prop=0;
        }

        for(int i=0;i<n;i++)
        {
            //cout<<arr[i].ind<<" "<<i<<" "<<arr[i].val<<endl;
            sqArr[arr[i].ind]=i+1;
        }

        //for(int i=0;i<n;i++)
         //   cout<<sqArr[i]<<endl;

        build(1,1,n);

     //   cout<<"Ok"<<endl;

        lld ans=0;

        for(int i=n-1;i>=0;i--)
        {
            ans+=query(1,1,n,sqArr[i],0);
           // cout<<ans<<endl;
            update(1,1,n,sqArr[i]+1,n,1);
        }

        printf("%lld\n",ans);


    }

    return 0;
}

