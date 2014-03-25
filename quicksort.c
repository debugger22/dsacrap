#include <stdio.h>
void quicksort(int arr[], int low, int high);
int main() 
{
	int n;
	scanf("%d",&n);
	int arr[1000] = {0};
	int i = 0;
	for(i = 0; i < n; i++)
		 scanf("%d",&arr[i]);
 	quicksort(arr, 0, (n - 1));
	for(i = 0; i < n; i++)
	 	 printf(" %d\n ", arr[i]); 
 	return 0;
}
void quicksort(int arr[], int low, int high)
{
	int i,j,temp=0,mid;
	i = low; j = high;
	mid = (low + high)/2;	
	while(i<j) 
 	{
		  while(arr[i] < arr[mid]) 
			  i++;
		  while(arr[j] > arr[mid]) 
			  j--;
  		if(i <= j)
  		{
		   temp = arr[i];
		   arr[i] = arr[j]; 
		   arr[j] = temp;
		   i++; 
		   j--;
  		}
	} 
 	if(low < j) 
  		quicksort(arr, low, j);
 	if(i < high) 
	       quicksort(arr, i, high); 
}