#include<stdio.h>
int a,b,u,v,n,i,j,ne=1,vis[10],min,mincost=0,cost[10][10];
main()
{
 printf("enter the no of nodes\n");
scanf("%d",&n);
printf("\n enter the cost of adjacency matrix\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d",&cost[i][j]);
for(i=2;i<=n;i++)
vis[i]=0;
printf("\n the edges of the network are \n");
vis[1]=1;
while(ne<n)
 {
for(i=1,min=999;i<=n;i++)
for(j=1;j<=n;j++)
if(cost[i][j]<min)
 if(vis[i]==0)
 continue;
 else
 {
 min=cost[i][j];
 a=i;
 b=j;
 }
 if(vis[a]==0||vis[b]==0)
 {
printf("%d edge (%d%d)=%d\n",ne++,a,b,min);
mincost+=min;
vis[b]=1;
 }
 cost[a][b]=cost[b][a]=999;
 }
printf("mincost=%d\n",mincost);
return 0;
}