#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int *a,int left,int right){
	int i=left,j=right+1,s=a[left],t;

	printf("called %d %d \n",left,right);

	if(right<left)return;

	while(1){
		while(a[++i]<s);
		while(a[--j]>s);
		if(i>=j)break;
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}

	a[left] = a[j];
	a[j] = s;

	quicksort(a,left,j-1);
	quicksort(a,j+1,right);
}



int main(int argc,char **argv){
	int i,n = atoi(argv[1]);
	srand(time(NULL));

	if(argc==2){
		int a[n];
		for(i=0;i<n;i++){
			a[i] = rand();
		}

		quicksort(a,0,n-1);

		for(i=0;i<10;i++){
			printf("%d\n",a[i]);
		}
	}

	return 0;
}