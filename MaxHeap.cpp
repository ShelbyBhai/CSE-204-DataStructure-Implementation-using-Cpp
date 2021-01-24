#include<bits/stdc++.h>
#define NULL_Value -9999
using namespace std;

class MaxHeap
{
public:
    int heapsize;
    int *heap;
    int capacity;

    MaxHeap(int capacity);

    MaxHeap();

    ~MaxHeap();

    int findMax();

    int insert(int value);

    int extractMax();

    int deleteMax();

    int replace(int key);

    void createHeap();

    void heapify(int *arr,int n);

    static MaxHeap merge(MaxHeap h1,MaxHeap h2);

    static MaxHeap meld(MaxHeap *h1,MaxHeap *h2);

    int size();

    bool isEmpty();

    void increaseKey(int index,int key);

    void decreaseKey(int index,int key);

    int deleteNode(int index);

    void sift_up(int position);

    void sift_down(int position);

    void PrintHeap();

    int getParent(int i)
    {
        return (i-1)/2;
    }
    int getLeftChild(int i)
    {
        return 2*i+1;
    }
    int getRightChild(int i)
    {
        return 2*i+2;
    }
};

int MaxHeap::findMax()
{
      if(heapsize == 0)
    {
        cout<<"The Heap is Empty!!!"<<endl;
        return NULL_Value;
    }
    else
        return heap[0];
}

int MaxHeap::insert(int value)
{
    heap[heapsize]=value;
    heapsize++;
    sift_up(heapsize-1);
}

int MaxHeap::extractMax()
{
    if(heapsize == 0)
    {
        cout<<"The Heap is Empty!!!"<<endl;
        return NULL_Value;
    }
    else
    {
        int tempmax=heap[0];
        deleteMax();
        return tempmax;
    }
}

int MaxHeap::deleteMax()
{
    if(heapsize == 0)
    {
        cout<<"The Heap is Empty!!!"<<endl;
        return NULL_Value;
    }
    else
    {
        heap[0]=heap[heapsize-1];
        heapsize--;
        sift_down(0);
        return 0;
    }
}

int MaxHeap::replace(int key)
{
    heap[0]=key;
    sift_down(0);
}

void MaxHeap::createHeap()
{
    capacity = 20;
    heapsize = 0;
    heap = new int[capacity];
}

MaxHeap::MaxHeap(int capacity) : capacity(capacity)
{
    heapsize = 0;
    heap = new int[capacity];
}

MaxHeap::MaxHeap()
{
    capacity=20;
    heapsize = 0;
    heap = new int[capacity];
}

MaxHeap::~MaxHeap()
{
    delete heap;
    heapsize == 0;
}

void MaxHeap::heapify(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
    {
        insert(arr[i]);
    }
}

MaxHeap MaxHeap::merge(MaxHeap h1, MaxHeap h2)
{
    int size1=h1.heapsize;
    int size2=h2.heapsize;
    MaxHeap h3(size1+size2);
    for (int i = 0; i <size1 ; ++i)
    {
        h3.insert(h1.heap[i]);
    }
    for (int j = 0; j <size2 ; ++j)
    {
        h3.insert(h2.heap[j]);
    }
    return h3;
}

MaxHeap MaxHeap::meld(MaxHeap *h1, MaxHeap *h2)
{
    int size1=h1->heapsize;
    int size2=h2->heapsize;
    MaxHeap h3(size1+size2);
    for (int i = 0; i <size1 ; ++i)
    {
        h3.insert(h1->heap[i]);
    }
    for (int j = 0; j <size2 ; ++j)
    {
        h3.insert(h2->heap[j]);
    }
    delete h1;
    delete h2;
    return h3;
}

int MaxHeap::size()
{
    return heapsize;
}

bool MaxHeap::isEmpty()
{
    return (heapsize == 0);
}

void MaxHeap::increaseKey(int index, int key)
{
    if(heap[index]<key)
    {
        heap[index] = key;
        sift_up(index);
    }
    else
        cout<<"the value passed is smaller than existing value"<<endl;
}

void MaxHeap::decreaseKey(int index, int key)
{
    if(heap[index]>key)
    {
        heap[index] = key;
        sift_down(index);
    }
    else
        cout<<"the value passed is bigger than existing value"<<endl;
}

int MaxHeap::deleteNode(int index)
{
    if(index<heapsize)
    {
        heap[index]=heap[heapsize-1];
        sift_down(index);
        heapsize--;
        return 0;
    }
    else
        return NULL_Value;
}

void MaxHeap::sift_up(int position)
{
    if(heap[getParent(position)]<heap[position])
    {
        int temp = heap[getParent(position)];
        heap[getParent(position)] = heap[position];
        heap[position] = temp;
        sift_up(getParent(position));
    }
}

void MaxHeap::sift_down(int position)
{
    int greatest = position;
    if(getLeftChild(position)<heapsize && heap[getLeftChild(position)]>heap[greatest])
    {
        greatest = getLeftChild(position);
    }
    if(getRightChild(position)<heapsize && heap[getRightChild(position)]>heap[greatest])
    {
        greatest = getRightChild(position);
    }
    if(greatest != position)
    {
        int temp = heap[greatest];
        heap[greatest] = heap[position];
        heap[position] = temp;
        sift_down(greatest);
    }

}
void MaxHeap::PrintHeap()
{
    for(int i=0; i<heapsize; i++)
    {
        cout<<heap[i]<<"  ";
    }
}

int main()
{
    MaxHeap hp;
    while(1)
    {
        cout<<"\n"<<endl;
        cout<<"------WELCOME TO MAXHEAP IMPLEMENTATION-----"<<endl;
        cout<<"\n"<<endl;
        cout<<"1.Find Maximum of Heap "<<"2.Insert Item into The Heap "<<"3.Extract Maximum from the Heap "<<endl;
        cout<<"4.Delete Maximum from the Heap "<<"5.Replace root with new value "<<"6.Create Heap "<<endl;
        cout<<"7.Heapify the given Array "<<"8.Merge two Heaps "<<"9.Meld two Heaps "<<"10.Current Size of Heap "<<endl;
        cout<<"11.Is the Heap Empty? "<<"12.Increase Key "<<"13.Decrease Key "<<"14.Delete Node "<<endl;
        cout<<"15.Sift Up "<<"16.Sift Down "<<"17.Print The Heap "<<"18.Exit "<<endl;
        int ch;
        cout<<"Enter Your Choice : "<<endl;
        cin>>ch;
        if(ch == 1)
        {
            cout<<"The Maximum : "<<hp.findMax()<<endl;
        }
        else if(ch == 2)
        {
            int item;
            cout<<"Enter the value you want to Insert: "<<endl;
            cin>>item;
            hp.insert(item);
        }
        else if(ch == 3)
        {
            cout<<"The Maximum Value extracted : "<<hp.extractMax()<<endl;
        }
        else if(ch == 4)
        {
            hp.deleteMax();
        }
        else if(ch == 5)
        {
            int newValue;
            cout<<"Enter value you want to replace with the Root: "<<endl;
            cin>>newValue;
            hp.replace(newValue);
        }
        else if(ch == 6)
        {
            hp.createHeap();
            cout<<"New Heap Created!!!"<<endl;
        }
        else if(ch == 7)
        {
            int arraySize;
            cout<<"Enter the Size of your Array: "<<endl;
            cin>>arraySize;
            int*arr = new int[arraySize];
            cout<<"Enter the Array : "<<endl;
            for(int j=0; j<arraySize; j++)
            {
                cin>>arr[j];
            }
            hp.heapify(arr,arraySize);
        }
        else if(ch == 8)
        {
            int arraySize1,arraySize2;
            cout<<"Enter the Size of your Array1: "<<endl;
            cin>>arraySize1;
            int *arr1=new int[arraySize1];
            cout<<"Enter the Array 1 : "<<endl;
            for(int j=0; j<arraySize1; j++)
            {
                cin>>arr1[j];
            }
            MaxHeap hp1;
            hp1.heapify(arr1,arraySize1);
            cout<<"Enter the Size of your Array2: "<<endl;
            cin>>arraySize2;
            int *arr2=new int[arraySize2];
            cout<<"Enter the Array 2 : "<<endl;
            for(int j=0; j<arraySize2; j++)
            {
                cin>>arr2[j];
            }
            MaxHeap hp2;
            hp2.heapify(arr2,arraySize2);
            MaxHeap hp3;
            hp3.merge(hp1,hp2);
        }
        else if(ch == 9)
        {
            int arraySize1,arraySize2;
            cout<<"Enter the Size of your Array1: "<<endl;
            cin>>arraySize1;
            int *arr1=new int[arraySize1];
            cout<<"Enter the Array 1 : "<<endl;
            for(int j=0; j<arraySize1; j++)
            {
                cin>>arr1[j];
            }
            MaxHeap hp1;
            hp1.heapify(arr1,arraySize1);
            cout<<"Enter the Size of your Array2: "<<endl;
            cin>>arraySize2;
            int *arr2=new int[arraySize2];
            cout<<"Enter the Array 2 : "<<endl;
            for(int j=0; j<arraySize2; j++)
            {
                cin>>arr2[j];
            }
            MaxHeap hp2;
            hp2.heapify(arr2,arraySize2);
            MaxHeap hp3;
            hp3.meld(&hp1,&hp2);
        }
        else if(ch ==10)
        {
            cout<<"The size of Heap : "<<hp.size()<<endl;
        }
        else if(ch == 11)
        {
            hp.isEmpty();
        }
        else if(ch == 12)
        {
            int idx,item;
            cout<<"Enter the Index position: "<<endl;
            cin>>idx;
            cout<<"Enter the Value : "<<endl;
            cin>>item;
            hp.increaseKey(idx,item);
        }
        else if(ch == 13)
        {
            int idx,item;
            cout<<"Enter the Index position: "<<endl;
            cin>>idx;
            cout<<"Enter the Value : "<<endl;
            cin>>item;
            hp.decreaseKey(idx,item);
        }
        else if(ch == 14)
        {
            int pos;
            cout<<"Enter the index to delete: "<<endl;
            cin>>pos;
            hp.deleteNode(pos);
        }
        else if(ch == 15)
        {
            int idx;
            cout<<"Enter the position to sift up: "<<endl;
            cin>>idx;
            hp.sift_up(idx);
        }
        else if(ch == 16)
        {
            int idx;
            cout<<"Enter the position to sift down: "<<endl;
            cin>>idx;
            hp.sift_down(idx);
        }
        else if(ch == 17)
        {
            hp.PrintHeap();
        }
        else if(ch == 18)
        {
            cout<<"Exiting from here!!!"<<endl;
            break;
        }
    }
}
/*void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
})*/
