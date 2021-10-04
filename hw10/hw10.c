#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort1(int data[], int left, int right, int re){
	int pivot, i, j;
	int temp;
	if(left < right)
	{
		i=left;	j=right+1;
		pivot = data[left];
		do{
			do i++;	while(data[i] < pivot);
			do j--;	while(data[j] > pivot);
			if(i < j){
				temp=data[i];
				data[i]=data[j];
				data[j]=temp;
			}
		}while(i < j);
		temp=data[left];
		data[left]=data[j];
		data[j]=temp;
		if(re==1){
			if(j-1-left > right-j-1){
				quickSort1(data, left, j-1, 1);
				quickSort1(data, j+1, right, 1);
			}
			else{
				quickSort1(data, j+1, right, 1);
				quickSort1(data, left, j-1, 1);
			}
		}
		if(re==2){
			if(j-1-left > right-j-1){
				quickSort1(data, j+1, right, 1);
				quickSort1(data, left, j-1, 1);
			}
			else{
				quickSort1(data, left, j-1, 1);
				quickSort1(data, j+1, right, 1);
			}
		}
		if(re==3){
			quickSort1(data, j+1, right, 1);
			quickSort1(data, left, j-1, 1);
		}
	}
}

void quickSort2(int data[], int left, int right, int re){
	int pivot, i, j;
	int temp;
	int median;
	if(data[left] > data[right] && data[right] > data[(left+right)/2])
		median = data[right];
	else if(data[right] > data[left] && data[left] > data[(left+right)/2])
		median = data[left];
	else
		median = data[(left+right)/2];
	if(left < right)
	{
		i=left;	j=right+1;
		pivot = median;
		do{
			do i++;	while(data[i] < pivot);
			do j--;	while(data[j] > pivot);
			if(i < j){
				temp=data[i];
				data[i]=data[j];
				data[j]=temp;
			}
		}while(i < j);
		temp=data[left];
		data[left]=data[j];
		data[j]=temp;	
		if(re==1){
			if(j-1-left > right-j-1){
				quickSort1(data, left, j-1, 1);
				quickSort1(data, j+1, right, 1);
			}
			else{
				quickSort1(data, j+1, right, 1);
				quickSort1(data, left, j-1, 1);
			}
		}
		if(re==2){
			if(j-1-left > right-j-1){
				quickSort1(data, j+1, right, 1);
				quickSort1(data, left, j-1, 1);
			}
			else{
				quickSort1(data, left, j-1, 1);
				quickSort1(data, j+1, right, 1);
			}
		}
		if(re==3){
			quickSort1(data, j+1, right, 1);
			quickSort1(data, left, j-1, 1);
		}
	}
}

int main()
{
	FILE *fpt;
	fpt=fopen("hw10.txt","r");
	
	int data[200000], index=0;
	char ch;

	clock_t start, end;
	double cpu_time_used;

	while(fscanf(fpt, "%d%c", &data[index++], &ch) != EOF)
		;
	start = clock();
	quickSort1(data, 0, 149999, 1);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("use leftmost and longer fist execution time = %f\n", cpu_time_used);
	for(int i=0; i<200000; i++)
		data[i]=0;
	index=0;

	while(fscanf(fpt, "%d%c", &data[index++], &ch) != EOF)
		;
	start = clock();
	quickSort1(data, 0, 149999, 2);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("use leftmost and shorter fist execution time = %f\n", cpu_time_used);
	for(int i=0; i<200000; i++)
		data[i]=0;
	index=0;

	while(fscanf(fpt, "%d%c", &data[index++], &ch) != EOF)
		;
	start = clock();
	quickSort1(data, 0, 149999, 3);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("use leftmost and left fist execution time = %f\n", cpu_time_used);
	for(int i=0; i<200000; i++)
		data[i]=0;
	index=0;

	while(fscanf(fpt, "%d%c", &data[index++], &ch) != EOF)
		;
	start = clock();
	quickSort2(data, 0, 149999,1);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("use median of three and longer fist execution time = %f\n", cpu_time_used);
	for(int i=0; i<200000; i++)
		data[i]=0;
	index=0;

	while(fscanf(fpt, "%d%c", &data[index++], &ch) != EOF)
		;
	start = clock();
	quickSort2(data, 0, 149999,2);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("use median of three and shorter fist execution time = %f\n", cpu_time_used);
	for(int i=0; i<200000; i++)
		data[i]=0;
	index=0;

	while(fscanf(fpt, "%d%c", &data[index++], &ch) != EOF)
		;
	start = clock();
	quickSort2(data, 0, 149999,3);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("use median of three and left fist execution time = %f\n", cpu_time_used);
	
	fclose(fpt);
	return 0;
}

