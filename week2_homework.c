#include<stdio.h>
#define maxn  10
int a[100],x[maxn],f[maxn];
int n,u;
void luukq()
{
    for(int i=1;i<=n;i++)
        a[i+u*n]=x[i];
        u++;
}
void hoanvi(int k)
{
    if(k==n+1)
    {
        if(u<=n) luukq();
    }
    else
    {
        for(int i=1;i<=n;i++)
            if(f[i]==0)
        {
            x[k]=i;
            f[i]=1;
            hoanvi(k+1);
            f[i]=0;
        }
    }
}
int main()
{
    scanf("%d",&n);
    hoanvi(1);
    printf("Mang X la: \n");
    for(int i=1;i<=n*n;i++)
        printf("%d ",a[i]);
    printf("\n");
    for(int i=1;i<=n*n;i++)
        a[i]--;
    int dem=0;
    for(int i=2;i<=n*n;i++)
        if(a[i]<a[i-1]) dem++;
        printf("%d",dem);
}
