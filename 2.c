#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int arr[],int l,int m,int r)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
    {
        L[i]=arr[i+l];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=arr[m+1+j];
    }
    i=0;j=0;k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {   
            arr[k++]=L[i++];
        }
        else
        {
            arr[k++]=R[j++];
        }
    }
    while(i<n1)
    {
        arr[k++]=L[i++];
    }
    while(j<n2)
    {
        arr[k++]=R[j++];
    }
}
void merge_sort(int arr[],int l,int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
int main()
{
    int i,n,arr[100];
    float start,end;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("\nArray before sorting: \n");
    for(i=0;i<n;i++)
    {
        arr[i]=rand();
        printf("%d  ",arr[i]);
    }
    start = clock();
    merge_sort(arr,0,n-1);
    end = clock();
    printf("\nSorted array: \n");
    for(i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\nTime taken in sorting is %f\n",(end-start)/CLOCKS_PER_SEC);

}
