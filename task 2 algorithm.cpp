#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void sortInsert(int arr[],int size);
int partition(int arr[],int str,int end);
void quicksort(int arr[],int start,int end);
int main()
{
	int arr[100001];
	int size=100000;
	for (int i =0 ;i<size;i++)
	{
		arr[i]=rand();//take the random numbers
	}
	clock_t t;
    t = clock();//begin time
    sortInsert(arr,size);
    t = clock() - t;//end time
    double time_taken = ((double)t)/CLOCKS_PER_SEC;//calc time
    printf("function Insertion Sort took %f seconds to execute \n", time_taken);
    clock_t beg=clock();
    
    quicksort(arr,arr[0],arr[100000]);
    clock_t end=clock();
    double time_taken2 = ((double)(end-beg))/CLOCKS_PER_SEC;
    printf("function Quick Sort took %f seconds to execute \n", time_taken2);
}
void sortInsert(int arr[],int size)
{int key , j;
for (int i =1;i<size;i++)
{key=arr[i];
j=i-1;
while(j>=0&&arr[j]>key)
{
	arr[j+1]=arr[j];
	j=j-1;
}
arr[j+1]=key;
}
}
void quicksort(int number[25],int first,int last){//quick sort
int i, j, pivot, temp;
if(first<last){
pivot=first;
i=first;
j=last;
while(i<j){
while(number[i]<=number[pivot]&&i<last)
i++;
while(number[j]>number[pivot])
j--;
if(i<j){
temp=number[i];
number[i]=number[j];
number[j]=temp;
}
}
temp=number[pivot];
number[pivot]=number[j];
number[j]=temp;
quicksort(number,first,j-1);
quicksort(number,j+1,last);
}
}

