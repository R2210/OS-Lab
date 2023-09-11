#include<stdio.h>
int main(){
	int n,m;
	printf("ENTER NO OF PROCESSES:");
	scanf("%d",&n);
	int p[n],pvis[n],i;
	printf("ENTER PROCESS SIZES:");
	for(i=1;i<=n;i++){
		scanf("%d",&p[i]);
		pvis[i]=0;
	}
	printf("ENTER NO OF BLOCKS:");
	scanf("%d",&m);
	int b[m],j,bvis[n];
	printf("ENTER BLOCK SIZES:");
	for(i=1;i<=m;i++){
		scanf("%d",&b[i]);
		bvis[i]=0;
	}
	for(i=1;i<=n;i++){
		int max=9999,k=0;
		for(j=1;j<=m;j++){
			if(b[j]>=p[i]&&max>b[j]){
				max=b[j];
				k=j;
			}
		}
		if(k!=0){
			printf("P[%d]-->B[%d]\n",i,k);
			b[k]=b[k]-p[i];
			pvis[i]=1;
			bvis[k]=1;
		}
	}
	int f=0,s=0,flag=0;
	for(i=1;i<=m;i++){
		if(bvis[i]!=0){
			f+=b[i];
		}else{
			s+=b[i];
		}
	}
	printf("INTERNAL FRAGMENTATION:%d\n",f);
	for(i=1;i<=n;i++){
		if(s>=p[i]&&pvis[i]==0){
		     printf("EXTERNAL FRAGMENTATIOM FOR P[%d]\n",i);
			 flag=1;	
		}
	}
	if(flag==0){
		printf("NO EXTERNAL FRAGMENTATION");
	}
}
