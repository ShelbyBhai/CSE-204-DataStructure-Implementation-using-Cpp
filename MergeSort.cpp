#include<stdio.h>

int  MergeSort(int arr[], int left, int right);
int Merge(int arr[], int left, int mid, int right);

int MergeSort(int arr[], int left, int right)
{
    int inversion_Count = 0;
    if (left < right)
    {
        int mid = (right + left)/2;
        inversion_Count  = MergeSort(arr, left, mid);
        inversion_Count = inversion_Count + MergeSort(arr, mid+1, right);
        inversion_Count = inversion_Count + Merge(arr, left, mid+1, right);
    }
    return inversion_Count;
}
int Merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int count_Local = 0;
    int tmp[right-1];
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            tmp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            tmp[k] = arr[j];
            k++;
            j++;
            count_Local = count_Local + (mid - i);
        }
    }
    while (i <= mid - 1)
    {
        tmp[k] = arr[i];
        k++;
        i++;
    }
    while (j <= right)
    {
        tmp[k] = arr[j];
        k++;
        j++;
    }
    for (i=left; i <= right; i++)
    {
        arr[i] = tmp[i];
    }
    return count_Local;
}
int main()
{
    printf("\tWelcome to Counting Inversion!!!!\n");
    printf("\t---------------------------------\n");
    while(1)
    {
        printf("1.Count Inversion Of An Array. 2.Exit.\n");
        int ch;
        scanf("%d",&ch);
        if(ch == 1)
        {
            int i,n;
            printf("\nEnter The Size Of Array : ");
            scanf("%d",&n);
            int a[n];
            printf("\nEnter The Array : ");
            for(i=0; i<n; i++)
            {
                scanf("%d",&a[i]);
            }
            int inv_count=MergeSort(a,0,n-1);
            printf("\nTotal Number of Inversion : %d\n\n",inv_count);
        }
        else if(ch == 2)
        {
            printf("Exiting From Here\n");
            break;
        }
        else
        {
            printf("Please Give a Valid Input According to The Menu!!!!\n");
            break;
        }
    }
}
