#include <stdio.h>
#define scan(a) scanf("%d",&a);
void swap(int *a,int i,int j){
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
/*
4
0 8
1 4
2 9
3 5

6
0 8
1 6
2 5
3 2
4 4
5 1
*/
void sort(int *ar,int *br,int *tb,int *s,int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(ar[j]>ar[i]){
				swap(ar,i,j);
				swap(br,i,j);
				swap(s,i,j);
				swap(tb,i,j);
			}else if(ar[j]==ar[i]){
				if(i>j){
					swap(ar,i,j);
					swap(br,i,j);
					swap(s,i,j);
					swap(tb,i,j);
				}
			}
		}
	}
}
int findUnArMinBrTime(int *ar,int *br,int n,int k,int *pr){
	int index=-1,min=-100000,i;
	int bflag=0;
	for(i=0;i<n;i++){
		if(br[i]!=0){
			bflag=1;
		}
		if(br[i]!=0 && pr[i]>min && ar[i]<=k){
			min=pr[i];
			index=i;
		}
	}	
	if(bflag==0){
		return -2;
	}
	return index;
}
int main(){
	int n,i,j=0,k=0,si=0,val[100],vi=0,ci=0;
	char str[100];
	val[0]=0;
	printf("enter no of  inputs:");
	scanf("%d",&n);
	int serial[n];
	int arrival[n];
	int brust[n];
	int tbrust[n];
	int priority[n];
	int ct[n];
	printf("[Priority] [Arrival] [burst]\n");
	for(i=0;i<n;i++){
		serial[i]=i+1;
		scan(priority[i]);
		scan(arrival[i]);
		scan(brust[i]);
		tbrust[i]=brust[i];
	}
	sort(arrival,brust,tbrust,serial,n);
	printf("--------\n");
	for(i=0;i<n;i++){
		printf("%d %d %d %d\n",priority[i],serial[i],arrival[i],brust[i]);
	}
	printf("--------\n");
	
	//ideal condition
	if(arrival[0]>k){
		str[si++]='$';
		k=k+arrival[0];
		val[++vi]=k;
	}
	
	str[si++]='0'+serial[0];
	k++;
	val[++vi]=k;
	brust[0]--;
	if(brust[0]==0){
		ct[0]=1;
		ci=1;
	}
	i=1;
	
	//looping
	while(j!=-2){
		j=findUnArMinBrTime(arrival,brust,n,k,priority);
		if(j==-1){
			str[si++]='$';
			val[vi++]=arrival[j];
			k++;
			
		}else if(j!=-2){
			k++;
			if(str[si-1]!='0'+serial[j]){
				str[si++]='0'+serial[j];
				val[++vi]=k;
			}else{
				val[vi]=k;
			}
			brust[j]--;
			if(brust[j]==0){
				ct[j]=k;	
			}
		}
	}
	if(str[si-1]!='0'+serial[j]){
		val[++vi]=k;
	}else{
		val[vi]=k;
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
		printf("%d\t%d\t%d\t%d\t%d\t%d\t\n",serial[i],arrival[i],tbrust[i],ct[i],ct[i]-arrival[i],ct[i]-arrival[i]-tbrust[i]);
	}
}

