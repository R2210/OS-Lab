#include<stdio.h>
int main(){
	int n,x;
	printf("enter no of processes:");
	scanf("%d",&n);
	int p[n],vis[n],i;
	printf("enter memory of processes:\n");
	for(i=1;i<=n;i++){
		scanf("%d",&p[i]);
		vis[i]=0;
	}
	printf("enter no of memory blocks:");
	scanf("%d",&x);
	int b[x],visit[x];
	printf("enter respective block sizes:\n");
	for(i=1;i<=x;i++){
		scanf("%d",&b[i]);
		visit[i]=0;
	}
	int j,k,max,sum=0;
	for(i=1;i<=n;i++){
		max=9999,k=-1;
		for(j=1;j<=x;j++){
			if(max>b[j]&&b[j]>=p[i]&&visit[j]!=1&&vis[i]!=1){
				k=j;
				max=b[j];
			}
		}
		if(k!=-1){
			printf("P[%d]---B[%d]\n",i,k);
			sum+=(b[k]-p[i]);
			vis[i]=1;
			visit[k]=1;
		}
	}
	printf("INTERNAL FRAGMENTATION IS:%d\n",sum);
	int f=0;
	for(i=1;i<=x;i++){
		if(visit[i]!=1){
			f+=b[i];
		}
	}
	for(j=1;j<=n;j++){
		if(vis[j]!=1&&f>=p[j]){
			printf("THERE IS EXTERNAL FRAGMENTATION ");
			break;
		}
	}
	if(j>n){
		printf("THERE IS NO EXTERNAL FRAGMENTATION");
	}
}
