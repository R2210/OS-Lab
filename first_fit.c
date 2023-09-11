#include<stdio.h>
int main(){
	int n,k;
	printf("enter no of process:");
	scanf("%d",&n);
	int p[n],vis[n],i;
	printf("enter memory of processes respectively:\n");
	for(i=1;i<=n;i++){
		
		scanf("%d",&p[i]);
		vis[i]=0;
	}
	printf("enter no of blocks:");
	scanf("%d",&k);
	int b[k],visit[k],j;
	printf("enter memory of processes respectively:\n");
	for(j=1;j<=k;j++){
		scanf("%d",&b[j]);
		visit[j]=0;
	}
	int sum=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=k;j++){
			if(p[i]<=b[j]&&vis[i]==0&&visit[j]==0){
				printf("P[%d]--->B[%d]\n",i,j);
				sum+=(b[j]-p[i]);
				vis[i]=1;
				visit[j]=1;
			}
		}
	}
	printf("internal fragmentation:%d\n\n",sum);
	int f=0;
	for(i=1;i<=k;i++){
		if(visit[i]!=1){
			f+=b[i];
		}
	}
	int flag=0;
	for(i=1;i<=n;i++){
		if(vis[i]!=1 && f>=p[i]){
			printf("enternal fragmentation for p[%d] is present %d",i,f);
		     flag=1;
		}
	}
	if(flag==0){
		printf("no external fragmentation");
	}
	
}
