#include<stdio.h>
int main(){
	int n,m;
	printf("ENTER NO OF PROCESSES:");
	scanf("%d",&n);
	int p[n],visit[n],i;
	printf("ENTER PROCESS SIZES:");
	for(i=1;i<=n;i++){
		scanf("%d",&p[i]);
		visit[i]=0;
	}
	printf("ENTER NO OF BLOCKS:");
	scanf("%d",&m);
	int b[m],vis[m],j;
	printf("ENTER BLOCK SIZES:");
	for(i=1;i<=m;i++){
		scanf("%d",&b[i]);
		vis[i]=0;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(b[j]>=p[i]){
				printf("P[%d]-->B[%d]\n",i,j);
				vis[j]=1;
				visit[i]=1;
				b[j]=b[j]-p[i];
				break;
			}
		}
	}
	int f=0,s=0,flag=0;
	for(i=1;i<=m;i++){
		if(vis[i]!=0){
			f+=b[i];
		}else{
			s+=b[i];
		}
	}
	printf("INETRNAL FRAGMENTATION IS:%d\n",f);
	for(i=1;i<=n;i++){
		if(visit[i]!=1 && s>=p[i]){
			flag=1;
			printf("EXTERNAL FRAGMENTATION IS THERE FOR P[%d] process\n",i);
		}
	}
	if(flag==0){
		printf("NO EXTERNAL FRAGMENTATION");
	}
}
