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
    ListNode * prev;
};


class LinkedListDoubly
{

    ListNode * list;
    ListNode * tail;
    int length;

public:
    LinkedListDoubly()
    {
        list = 0;
        tail = 0;
        length=0;
    }

    int getLength()
    {
        return length;
    }

    int insertFirst(int item)
    {
        ListNode * newNode ;
        newNode = new ListNode() ;
        newNode->item = item ;

        if(list==0)
        {
            newNode->next = 0;
            newNode->prev = 0;
            list = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = list;
            list->prev = newNode;
            newNode->prev = 0;
            list = newNode;
        }
        length++;
        return SUCCESS_VALUE ;
    }

    ListNode * searchItem(int item)
    {
        ListNode * temp ;
        temp = list ;
        while (temp != 0)
        {
            if (temp->item == item)
                return temp ;
            temp = temp->next ;
        }
        return 0 ;
    }

    void printListForward()
    {
        if(list==0)
        {
            printf("\n\tThe Doubly List is empty!!!\n");
        }
        ListNode * temp;
        temp = list;
        printf("\n\tThe Doubly List is : \n");
        printf( "----------------------------\n");
        while(temp!=0)
        {
            printf("%d->", temp->item);
            temp = temp->next;
        }
        printf("NULL");
        printf("\nLength: %d\n",length);
    }

    int insertLast(int item)
    {
        if(list==0)
        {
            printf("\n\tNothing Inserted yet!!!\n");
        }
        else
        {
            ListNode *tmp = new ListNode();
            tmp->item=item;
            tmp->prev = tail;
            tail->next = tmp ;
            tmp->next= NULL;
            tail=tmp;
            length++;
        }
        return SUCCESS_VALUE;
    }

    int deleteLast()
    {
        int ditem;
        if(list==0)
        {
            printf("\n\tNothing Inserted in Doubly List,so can't delete!!!\n");
            return 0;
        }
        else
        {
            ListNode *temp1 = new ListNode();
            ListNode *temp2 = new ListNode();
            temp1=tail;
            if(list->next==0)
            {
                ditem=temp1->item;
                list=0;
                tail=0;
                length--;
                return ditem;
            }
            ditem=temp1->item;
            temp2=temp1->prev;
            temp2->next=temp1->next;
            tail=temp2;
            length--;
            return ditem;
        }
        return SUCCESS_VALUE;
    }

    void printListBackward()
    {
        if(list==0)
        {
            printf("\n\tThe Doubly List is empty\n");
        }
        ListNode * temp;
        temp = tail;
        printf("\n\tThe Doubly List is(In Reverse) : \n");
        printf( "-----------------------------------\n");
        while(temp!=0)
        {
            printf("%d->", temp->item);
            temp = temp->prev;
        }
        printf("NULL");
        printf("\nLength: %d\n",length);
    }
};

int main(void)
{
    LinkedListDoubly ll;

    while(1)
    {
        printf( "\t\tTHE DOUBLY LINKED LIST\n");
        printf("\t-----------------------------------------------\n");
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("4.Insert at Last. 5. Print forward. 6. Print backward. 7. exit.\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            ll.insertFirst(item);
        }
        else if(ch==2)
        {
            int ditem = ll.deleteLast();
            if(ditem!=NULL_VALUE)
                printf("Deleted item: %d\n", ditem);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            ListNode * res = ll.searchItem(item);
            if(res!=0)
                printf("\tItem Found!!!\n");
            else
                printf("\tItem Not found!!!\n");
        }
        else if(ch==4)
        {
            int newItem;
            scanf("%d", &newItem);
            ll.insertLast(newItem);
        }
        else if(ch==5)
        {
            ll.printListForward();
        }
        else if(ch==6)
        {
            ll.printListBackward();
        }
        else if(ch==7)
        {
            break;
        }
    }
}




