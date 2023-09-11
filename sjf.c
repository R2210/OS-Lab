#include <stdio.h>
#define scan(a) scanf("%d",&a);
void swap(int *a,int i,int j){
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
/*
	6
	4 2 
	10 1
	15 2
	20 3
	28 8
	4 3
*/
void sort(int *ar,int *br,int *s,int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(ar[j]>ar[i]){
				swap(ar,i,j);
				swap(br,i,j);
				swap(s,i,j);
			}
		}
	}
}
int findUnArMinBrTime(int *ar,int *br,int *v,int n,int k){
	int index=-1,min=100000,i;
	for(i=0;i<n;i++){
		if(v[i]==0 && br[i]<min && ar[i]<=k){
			min=br[i];
			index=i;
		}
	}
	if(index==-1){
		return -1;
	}
	v[index]=1;	
	return index;
}
int main(){
	int n,i,j=0;
	printf("enter no of  inputs:");
	scanf("%d",&n);
	int serial[n];
	int arrival[n];
	int brust[n];
	int ct[n];
	int visited[n];
	printf("[Arrival] [burst]\n");
	for(i=0;i<n;i++){
		serial[i]=i+1;
		scan(arrival[i]);
		scan(brust[i]);
		visited[i]=0;
	}
	sort(arrival,brust,serial,n);
	int k=0,si=0;
	char str[100];
	int val[100],vi=1;
	val[0]=0;
	printf("--------\n");
	for(i=0;i<n;i++){
		printf("%d %d %d\n",serial[i],arrival[i],brust[i]);
	}
	printf("--------\n");
	if(arrival[0]>k){
		str[si++]='$';
		k=k+arrival[0];
		val[vi++]=k;
	}
	str[si++]='0'+serial[0];
	k=k+brust[0];
	val[vi++]=k;
	ct[0]=k;
	visited[0]=1;
	i=1;
	while(i<n){
		j=findUnArMinBrTime(arrival,brust,visited,n,k);
		if(j!=-1){
			str[si++]='0'+serial[j];
			k=k+brust[j];
			val[vi++]=k; 
			ct[j]=k;
			i++;
		}else{
			str[si++]='$';
			val[vi++]=arrival[i];
			k=arrival[i];
		}
	}
	for(i=0;i<si;i++){
		if(val[i]%10==val[i]){
			printf("  P%c",str[i]);
		}else{
			printf("   P%c",str[i]);
		}	
	}
	printf("\n");
	for(i=0;i<vi;i++){
		printf("%d   ",val[i]);
	}
	printf("\nPno\tA[i]\tB[i]\tCT[i]\tTT[i]\tWT[i]\n");
	for(i=0;i<n;i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\t\n",serial[i],arrival[i],brust[i],ct[i],ct[i]-arrival[i],ct[i]-arrival[i]-brust[i]);
	}
}
