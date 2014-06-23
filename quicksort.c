#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int *a,int left,int right){
	int s,t,i,j;

	if(left<right){
		s = a[(right+left)/2];
		i = left-1;
		j = right+1;

		while(1){
			while(a[++i]<s);
			while(a[--j]>s);
			if(i>=j)break;

			t = a[i]; a[i] = a[j]; a[j] = t;
		}

		quicksort(a,left,i-1);
		quicksort(a,j+1,right);
	}
}

int main(int argc,char **argv){

	if(argc!=2){
		puts("syntax error!");
		exit(1);
	}

	int n = atoi(argv[1]);
	int a[n],i;
	time_t start,end;
	
	srand(time(NULL));

	printf("makeing random %d data...",n);
	for(i=0;i<n;i++){
		a[i] = rand();
	}
	puts("done");

	//watch time here
	puts("start quicksort");
	quicksort(a,0,n-1);
	puts("end quicksort");

	for(i=0;i<10;i++){
		printf("%d\n",a[i]);
	}
	printf("sorting time:");

	return 0;
}