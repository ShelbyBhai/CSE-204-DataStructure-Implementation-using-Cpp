#include<bits/stdc++.h>

using namespace std;

void bucketSort(vector<double> &array, int num)
{
    if(array.size() == 0)
        return;
    vector<double> bucket[num];

    double maxItem=array[0];
    for(int i=0; i<array.size(); i++)
    {
        if(array[i]>maxItem)
            maxItem=array[i];
    }
    if(maxItem>=1)
    {
        for(int i=0; i<array.size(); i++)
        {
            array[i]=array[i]/(maxItem+0.5);
        }
    }
    for (int i=0; i<num; i++)
    {
        int bucket_i = num*array[i];
        bucket[bucket_i].push_back(array[i]);
    }

    for (int i=0; i<num; i++)
        sort(bucket[i].begin(), bucket[i].end());

    int idx = 0;
    for (int i = 0; i < num; i++)
        for (int j = 0; j < bucket[i].size(); j++)
            array[idx++] = bucket[i][j];

    if(maxItem>=1)

    {
        for(int j=0; j<array.size(); j++)
        {
            array[j]=array[j]*(maxItem+0.5);
        }
    }
}
void sortForAll(double arr[], int n)
{
    vector<double>Neg ;
    vector<double>Pos;
    for (int i=0; i<n; i++)
    {
        if (arr[i] < 0)
            Neg.push_back (-1 * arr[i]) ;
        else
            Pos.push_back (arr[i]) ;
    }
    bucketSort(Neg, (int)Neg.size());
    bucketSort(Pos, (int)Pos.size());
    for (int i=0; i < Neg.size(); i++)
        arr[i] = -1 * Neg[ Neg.size() -1 - i];
    for(int j=Neg.size(); j < n; j++)
        arr[j] = Pos[j - Neg.size()];
}
int main()
{
    int arrSize;
    cin>>arrSize;
    double array[arrSize];
    for(int i=0; i<arrSize; i++)
    {
        cin>>array[i];
    }
    sortForAll(array,arrSize);
    cout<<"The array is: "<<endl;
    for(int i=0; i<arrSize; i++)
    {
        cout<<array[i]<<endl;
    }
    return 0;
}
