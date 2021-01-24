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

    int getLength()
    {
        return length;
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

    void printList()
    {
        if(list==0)
        {
            printf("\n\tThe ListWithTail is empty!!!\n");
        }
        ListNode * temp;
        temp = list;
        printf("\n\tThe ListWithTail is : \n");
        printf( "----------------------------\n");
        while(temp!=0)
        {
            printf("%d->", temp->item);
            temp = temp->next;
        }
        printf("NULL\n");
        printf("\nLength: %d\n",length);
    }

    int insertLast(int item)
    {
        ListNode *newNode=new ListNode();
        if(list==0)
        {
            newNode->item=item;
            newNode->next=list;
            list=newNode;
            tail=newNode;
            length++;
            return SUCCESS_VALUE;
        }
        ListNode* temp=tail;
        newNode->item=item;
        newNode->next=temp->next;
        temp->next=newNode;
        tail=newNode;
        length++;
        return SUCCESS_VALUE;
    }


    ListNode * getItemAt(int pos)
    {
        if(pos>length)
        {
            printf("\n\tInvalid input\n");
        }
        else
        {
            ListNode *current = new ListNode();
            current=list;
            int counter=1;
            while(counter!=NULL_VALUE)
            {
                if(counter==pos)
                {
                    printf("The item is : %d\n",current->item);
                    return 0;
                }
                counter++;
                current=current->next;
            }
        }
    }

    int deleteLast()
    {
        int ditem;
        ListNode *temp1=tail;
        if(list==0)
        {
            printf("\n\tNothing Inserted in the ListWithTail,so can't delete!!!\n");
        }
        else
        {
                ditem=temp1->item;
                deleteItem(temp1->item);
                return ditem;
        }
    }
};

int main(void)
{
    LinkedListWithTail ll;

    while(1)
    {
        printf( "\t\tTHE LIST WITH TAIL\n");
        printf("\t-------------------------------------\n");
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("4.Get Item at index. 5. Insert item at Last 6. Delete Last item\n");
        printf("7.Print List. 8.Exit\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            ll.insertItem(item);
        }
        else if(ch==2)
        {
            int item;
            scanf("%d", &item);
            ll.deleteItem(item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            ListNode * res = ll.searchItem(item);
            if(res!=0)
                printf("Item Found!!!\n");
            else
                printf("Item Not found!!!\n");
        }
        else if(ch==4)
        {
            int index;
            scanf("%d",&index);
            ll.getItemAt(index);
        }
        else if(ch==5)
        {
            int item;
            scanf("%d", &item);
            ll.insertLast(item);
        }
        else if(ch==6)
        {
            int ditem = ll.deleteLast();
            if(ditem!=NULL_VALUE)
                printf("Deleted item: %d\n", ditem);
        }
        else if(ch==7)
        {
            ll.printList();
        }
        else if(ch==8)
        {
            break;
        }
    }

}
