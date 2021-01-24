#include<bits/stdc++.h>

using namespace std;

void countingSort(int arr[],int n)
{
    int maxItem=arr[0];
    int minItem=arr[0];
    for(int i=0; i<n; i++)
    {
        if(arr[i]>maxItem)
            maxItem=arr[i];
        if(arr[i]<minItem)
            minItem=arr[i];
    }
    if(minItem<0)
    {
        for(int i=0; i<n; i++)
            arr[i]=arr[i]-minItem;
        maxItem -= minItem;
    }
    int count[maxItem+1] = {0};
    int output[n];
    for(int i=0; i<n; i++)
        count[arr[i]]++;
    for(int i=1; i<maxItem+1; i++)
    {
        count[i]+=count[i-1];
    }
    for(int i=n-1; i>=0; i--)
    {
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    if(minItem<0)
    {
        for(int i=0; i<n; i++)
            arr[i] = output[i]+minItem;
    }
    else
    {
        for(int i=0; i<n; i++)
            arr[i] = output[i];
    }
}
void print(int arr[],int n)
{
    cout<<"\n";
    cout<<"The Array is : ";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<' ';
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    countingSort(arr,n);
    print(arr,n);
    return 0;
}
