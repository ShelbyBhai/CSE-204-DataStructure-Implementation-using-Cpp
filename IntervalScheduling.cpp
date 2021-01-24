#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

void  MergeSort(pair<int,int> arr[], int left, int right);
void Merge(pair<int,int> arr[], int left, int mid, int right);

void MergeSort(pair<int,int> arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (right + left)/2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);
        Merge(arr, left, mid, right);
    }
}
void Merge(pair<int,int> arr[], int left, int mid, int right)
{
    int i,j,k;
    int n1,n2;
    n1=mid-left+1;
    n2=right-mid;
    pair<int,int> tmp1[n1],tmp2[n2];
    k=left;
    for(i=0; i<n1; i++)
    {
        tmp1[i]=arr[k];
        k++;
    }
    k=mid+1;
    for(i=0; i<n2; i++)
    {
        tmp2[i]=arr[k];
        k++;
    }
    i=0;
    j=0;
    k=left;
    while(i<n1 && j<n2)
    {
        if(tmp1[i].second<tmp2[j].second)
        {
            arr[k]=tmp1[i];
            i++;
        }
        else
        {
            arr[k]=tmp2[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=tmp1[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=tmp2[j];
        j++;
        k++;
    }
}
int main()
{
    int i,j,k;
    int n,start,finish;
    int count=0;
    cin>>n;
    pair<int,int> array[n];
    for(i=0; i<n; i++)
    {
        cin>>start>>finish;
        array[i]= {start,finish};
    }
    MergeSort(array,0,n-1);
    pair<int,int> v[n];
    v[0]=array[0];
    count++;
    j=0;
    for(i=1; i<n; i++)
    {
        if(array[i].first>=v[j].second)
        {
            j++;
            v[j]=array[i];
            count++;
        }
    }
    cout<<"\n"<<endl;
    cout<<count<<endl;
    for(i=0; i<count; i++)
    {
        cout<<v[i].first<<" , "<<v[i].second<<endl;
    }
}

