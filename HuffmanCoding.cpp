#include<cstdio>
#include<iostream>

#define MAX_HEAP_SIZE 100000

using namespace std;

class HeapItem
{
public:
    char data;
    int key;
    HeapItem *left,*right;
};


class MinHeap
{
public:

    HeapItem **A;
    int heapLength;

    MinHeap()
    {
        A = new HeapItem*[MAX_HEAP_SIZE];
        heapLength=0;
    }

    ~MinHeap()
    {
        if(A)
            delete [] A;
        A = 0;
    }

    void insertItem(HeapItem item)
    {
        heapLength++;
        A[heapLength]=new HeapItem;
        A[heapLength]->data=item.data;
        A[heapLength]->key=item.key;
        A[heapLength]->left=item.left;
        A[heapLength]->right=item.right;
        buHeapify(heapLength);
    }

    HeapItem* removeMin()
    {
        HeapItem* temp=A[1];
        swap(A[1],A[heapLength]);
        heapLength--;
        heapify(1);
        return temp;
    }
    void Huffman(HeapItem* root,int sign,string s)
    {
        string str=s;
        if(sign==0)
            str.push_back('0');
        else if(sign==1)
            str.push_back('1');
        if(root->left==0 && root->right==0)
        {
            cout<<root->data<<" "<<str<<endl;
        }
        else
        {
            Huffman(root->left,0,str);
            Huffman(root->right,1,str);
        }
    }

    void heapify(int i)
    {
        int left,right,smallest;
        while(1)
        {
            left=2*i;
            right=2*i+1;
            smallest=i;
            if(left>heapLength && right>heapLength)
                break;
            else if(right>heapLength)
                smallest = left;
            else if(left>heapLength)
                smallest = right;
            else if( A[left]->key < A[right]->key )
                smallest = left;
            else
                smallest = right;
            if(A[i]->key <=A[smallest]->key)
                break;
            else
            {
                swap(A[i],A[smallest]);
                i=smallest;
            }
        }
    }
    void buHeapify(int i)
    {
        HeapItem* temp;
        int parent,child;
        child=i;
        while(child>1)
        {
            if(child%2==0)
                parent=child/2;
            else
                parent=(child-1)/2;
            if(A[parent]->key>A[child]->key)
            {
                swap(A[parent],A[child]);
            }
            child=parent;
        }
    }
    void printHeap()
    {
        printf("Heap length is: %d\n", heapLength);
        for(int i=1; i<=heapLength; i++)
        {
            cout<<"("<<A[i]->data<<","<<A[i]->key<<") ";
        }
        printf("\n");
    }
    int Size()
    {
        return heapLength;
    }
};

int main()
{
    int i,j,k;
    int key,n;
    char data;
    MinHeap heap;
    cin>>n;
    HeapItem hp;
    for(i=0; i<n; i++)
    {
        cin>>data>>key;
        hp.data=data;
        hp.key=key;
        hp.left=0;
        hp.right=0;
        heap.insertItem(hp);
    }
    char ch='#';
    HeapItem *a,*b;
    while(heap.Size()>1)
    {
        a=heap.removeMin();
        b=heap.removeMin();
        hp.data=ch;
        hp.key=a->key+b->key;
        hp.left=a;
        hp.right=b;
        heap.insertItem(hp);
    }
    a=heap.removeMin();
    heap.Huffman(a,2,"");
}
