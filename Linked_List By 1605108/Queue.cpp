#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

class ListNode
{
public:
    int item;
    ListNode * next;
};

class LinkedListWithTail
{

    ListNode * list;
    ListNode * tail;
    int length;

public:
    LinkedListWithTail()
    {
        list = 0;
        tail = 0;
        length=0;
    }
    int insertItem(int item)
    {
        ListNode * newNode ;
        newNode = new ListNode() ;
        if(list==0)
        {
            newNode->item=item;
            newNode->next=list;
            list=newNode;
            tail=newNode;
            length++;
            return SUCCESS_VALUE;
        }
        newNode->item = item ;
        newNode->next = list ;
        list = newNode ;
        length++;
        return SUCCESS_VALUE ;
    }
    int deleteItem(int item)
    {
        ListNode *temp, *prev ;
        temp = list ;
        while (temp != 0)
        {
            if (temp->item == item)
                break ;

            prev = temp;
            temp = temp->next ;
        }
        if (temp == 0)
            return NULL_VALUE ;
        if (temp == list)
        {
            list = list->next ;
            delete temp ;
            if(list==0)
                tail=list;

            length--;
        }
        else
        {
            if(temp->next==0)
                tail=prev;

            prev->next = temp->next ;
            delete temp;
            length--;
        }
        return SUCCESS_VALUE ;
    }

    int deleteLast()
    {
        int ditem;
        ListNode *temp1=tail;
        if(list==0)
        {
            printf("\n\tNothing Inserted in the Queue,so can't delete!!!\n");
        }
        else
        {
            ditem=temp1->item;
            deleteItem(temp1->item);
            return ditem;
        }
        return SUCCESS_VALUE;
    }
    void printList()
    {
        if(list==0)
        {
            printf("\n\tThe Queue is empty!!!\n");
        }
        ListNode * temp;
        temp = list;
        printf("\n\tThe Queue is : \n");
        printf( "----------------------------\n");
        while(temp!=0)
        {
            printf("%d ", temp->item);
            temp = temp->next;
        }
        printf("\nLength: %d\n",length);
    }
};
class Queue
{
    LinkedListWithTail ll;
public:
    Queue()
    {

    }

    void enqueue(int item)
    {
        ll.insertItem(item);
    }

    int dequeue()
    {
        return ll.deleteLast();
    }
    void printQueue()
    {
        ll.printList();
    }
};

int main(void)
{
    Queue qu;

    while(1)
    {
        printf( "\t\tTHE QUEUE\n");
        printf("\t-------------------------------\n");
        printf("1. Enqueue. 2. Dequeue. 3. Print the Queue 4. Exit. \n");
        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            qu.enqueue(item);
        }
        else if(ch==2)
        {
            printf("%d\n",qu.dequeue());
        }
        else if(ch==3)
        {
            qu.printQueue();
        }
        else if(ch==4)
        {
            break;
        }
    }
}

