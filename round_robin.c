#include <stdio.h>
#define scan(a) scanf("%d",&a);
#define L 100
int array[L],front=0,rear=0;
/* 6 2
0 4
1 5
2 6
3 3
4 1
5 4
*/

int  enQueue(int data){
	if(rear==L){
		printf("queue is overflow\n");
		return 0;
	}
	array[rear]=data;
	rear++;
	return 1; 
}

int isQEmpty(){
	if(rear==L || front==rear){
		return 1;
	}
	return 0;
}
int deQueue(){
	if(front==rear){
		printf("queue is underflow\n");
		return -1;
	}
	int i;
	int temp=array[front];
	for(i=0;i<rear-1;i++){
		array[i]=array[i+1];		
	}
	rear--;
	return temp;
}
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
//					swap(ar,i,j);
//					swap(br,i,j);
//					swap(s,i,j);
//					swap(tb,i,j);
				}
			}
		}
	}
}

int main(){
	int n,i,j=0,k=0,si=0,val[100],vi=0,ci=0;
	char str[100];
	val[0]=0;
	printf("enter no of  inputs:");
	scanf("%d",&n);
	printf("enter time quantum:");
	int tq;
	scanf("%d",&tq);
	int serial[n];
	int arrival[n];
	int brust[n];
	int tbrust[n];
	int ct[n];
	int visit[n];
	printf("[Arrival] [burst]\n");
	for(i=0;i<n;i++){
		serial[i]=i+1;
		scan(arrival[i]);
		scan(brust[i]);
		tbrust[i]=brust[i];
		visit[i]=0;
	}
	sort(arrival,brust,tbrust,serial,n);
	printf("--------\n");
	for(i=0;i<n;i++){
		printf("%d %d %d\n",serial[i],arrival[i],brust[i]);
	}
	printf("--------\n");
	//ideal condition
	if(arrival[0]>k){
		str[si++]='$';
		val[vi++]=0;
		k=k+arrival[0];
	}
	enQueue(serial[0]-1);
	visit[serial[0]-1]=1;
	val[vi++]=k;
	i=1;

	//looping
	int process;
	int status=0;
	while(!isQEmpty()){
		process=deQueue();
		printf("process %d b=%d\n",process+1,brust[process]);
		if(brust[process]>=tq){	
			printf("p%d - brust %d\n",process,brust[process]);
			brust[process]-=tq;
			printf("p%d - brust %d\n",process,brust[process]);
			if(brust[process]==0){
				ct[process]=k;
				status++;
			}
			k=k+tq;
			str[si++]='0'+(process+1);
			str[si]='\0';
			printf("gantt chart %s\n",str);
			val[vi++]=k;
			ct[process]=k;
			int flag=0,nextProcess;
			for(i=0;arrival[i]<=k && i<n;i++){
				printf("process=%d i=%d k=%d serial-%d a[i]=%d\n",process,i,k,serial[i]-1,arrival[i]);
				if(brust[i]!=0 &&  arrival[i]<=k  && (serial[i]-1)!=process  && visit[serial[i]-1]==0){
					enQueue(serial[i]-1);
					visit[serial[i]-1]=1;
					printf("enQueued process--s %d\n",serial[i]);
				}
			}
			if(brust[process]!=0){
				enQueue(process);
				printf("enQueued process %d\n",process+1);
			}	
		}else{
			printf("brust[%d]<tq\n",process);
			k+=brust[process];
			brust[process]=0;
			visit[process]=1;
			val[vi++]=k;
			str[si++]='0'+(process+1);
			str[si]='\0';
			printf("gantt chart %s\n",str);
			ct[process]=k;
			status++;
		}
		if(isQEmpty() && status<n){
			for(i=0;i<n;i++){
				if(brust[i]!=0 && visit[i]==0){
					enQueue(i);
					k=arrival[i];
					visit[i]=1;
					val[vi++]=k;
					break;
				}
			}
			str[si++]='$';
			str[si]='\0';
			
		}
	}
	printf("\n\nGantt Chart\n\n");
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
		printf("%d\t%d\t%d\t%d\t%d\t%d\t\n",serial[i],arrival[i],tbrust[i],ct[i],ct[i]-arrival[i],ct[i]-arrival[i]-brust[i]);
	}
}

