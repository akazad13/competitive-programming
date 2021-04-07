            /************************************************/
            /************************************************/
            /**                                            **/
            /**                 *           *    *         **/
            /**                * *          *   *          **/
            /**               *   *         *  *           **/
            /**              *     *        * *            **/
            /**             *********       * *            **/
            /**            *         *      *  *           **/
            /**           *           *     *   *          **/
            /**          *             *    *    *         **/
            /**                                            **/
            /**             Md. Abul Kalam Azad            **/
            /**           CSE - 13 series , RUET,BD        **/
            /**        Email : akazad.cse13@gmail.com      **/
            /**                cell-01686871012            **/
            /**           Cool Ur head & Think :-)         **/
            /**        codeforce & uva id: akazad133032    **/
            /**         fb id: facebook.com/akazad.cse13   **/
            /**                                            **/
            /**                                            **/
            /**                                            **/
            /************************************************/
            /************************************************/


#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Macros
#define read(a) scanf("%d",&a)
#define CLEAR(a,b) memset(a,b,sizeof(a))
#define VI(a) vector<a>

#define lld long long int
#define ulld unsigned long long int
#define PI acos(-1.0)
#define Gamma 0.5772156649015328606065120900824024310421

//End Macros

#define MAX 10000
bool prime[MAX+10];
vector<int>primeList; //for saving prime number in a vector
int Vsize;

void sieve()
{
  //generating prime table
    for(int i=4;i<=MAX;i+=2)
        prime[i]=1;
    int srt = sqrt(MAX);
    for(int i=3;i<=srt;i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<=MAX;j+=2*i)
            {
                prime[j]=1;
            }
        }
    }
    prime[0]=prime[1]=1;


  //for saving the prime in one place
    for(int i=2;i<=MAX;i++)
    {
        if(prime[i]==0)
        {
            primeList.push_back(i);
        }
    }

    Vsize = primeList.size();

   // cout<<"seive OK"<<endl;
}

int n,k;
lld dp[190][1122][15];

lld solve(int ind, int make, int take)
{
    if(ind>=190 || primeList[ind]>n)
    {
        if(make==n && take==k)
            return 1;
        else return 0;
    }

    if(dp[ind][make][take]!=-1) return dp[ind][make][take];

    lld ret=0;
    if(primeList[ind]+make<=n && take+1<=k)
    {
        ret = solve(ind+1, make+primeList[ind],take+1);
    }

    ret+= solve(ind+1, make,take);

    return dp[ind][make][take] = ret;
}



int main()
{
    //freopen("uvain.txt","r",stdin);

    sieve(); //calling sieve function

    //then you can write your code here

    while(scanf("%d %d",&n,&k)==2)
    {
        if(n==0 && k==0)
            break;
        CLEAR(dp,-1);
        lld ret = solve(0,0,0);

        printf("%lld\n",ret);
    }

    return 0;

}

