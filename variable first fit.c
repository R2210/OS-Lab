#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,m,i,j;
	printf("enter processes");
	scanf("%d",&n);
	int p[n],visit[n];
	printf("enter blocks");
	scanf("%d",&m);
	int b[m],vis[m];
	printf("enter processes seq");
	for(i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	printf("enter block seq");
	for(i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	for(i=1;i<=n;i++){
		visit[i]=0;
	}
	for(i=1;i<=m;i++){
		vis[i]=0;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(b[j]>=p[i]){
				printf("p[%d]--->b[%d]",i,j);
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
			f=f+b[i];
		}
		else{
			s=s+b[i];
		}
	}
	printf("\n\internal fragmentation",f);
	for(i=1;i<=n;i++){
		if(visit[i]!=1 && s>=p[i]){
			flag=1;
			printf("external frag for p[%d] process",i);
		}
		
	}
	if(flag==0){
		printf("no");
	}
	
}
