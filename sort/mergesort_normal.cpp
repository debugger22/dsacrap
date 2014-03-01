#include <iostream>
#include <time.h>
using namespace std;

void merge(int *,int, int , int );
void mergesort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    return;
}
void merge(int *a, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }
}
int main()
{    
    clock_t tStart = clock();
    int a[20], i, b[20];
   int x;
   cin>>x;
    for (i = 0; i < x; i++)
    {
        cin>>a[i];
    }
    mergesort(a, 0, x-1);
    cout<<"sorted array\n";
    for (i = 0; i < x; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"Time taken"<< (double)(clock() - tStart)/CLOCKS_PER_SEC;
    return 0;
}