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

class LinkedList
{

    ListNode * list;
    int length;

public:
    LinkedList()
    {
        list=0;
        length=0;
    }

    int getLength()
    {
        return length;
    }

    int insertItem(int item)
    {
        ListNode * newNode = new ListNode() ;
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
            length--;
        }
        else
        {
            prev->next = temp->next ;
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
            printf("\n\tThe SinglyList is empty!!!\n");
        }
        ListNode * temp;
        temp = list;
        printf("\n\tThe SinglyList is : \n");
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
        if(list==0)
        {
            printf("\n\tNothing inserted in SinglyList!!!!\n");
        }
        else
        {
            ListNode * newNode = new ListNode() ;
            newNode->item=item;
            newNode->next=0;
            ListNode *prev = new ListNode();
            prev=list;
            while (prev->next != NULL)
                prev = prev->next;
            newNode->next=0;
            prev->next=newNode;
            length++;
        }
        return SUCCESS_VALUE;
    }

    int insertAfter(int oldItem, int newItem)
    {
        if(list==0)
        {
            printf("\n\tNothing inserted in SinglyList!!!\n");
        }
        else if (searchItem(oldItem)==0)
        {
            printf("\n\tThis item is not present in the SinglyList\n");
        }
        else
        {
            ListNode * newNode = new ListNode() ;
            newNode->item=newItem;
            newNode->next=0;
            ListNode *prev = new ListNode();
            prev=list;
            while (prev->item != oldItem)
                prev = prev->next;
            newNode->next = prev->next;
            prev->next = newNode;
            length++;
        }
        return SUCCESS_VALUE;
    }

    ListNode * getItemAt(int pos)
    {
        if(pos>length)
        {
            printf("\n\tInvalid input!!!\n");
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

    int deleteFirst()
    {
        if(list==0)
        {
            printf("\n\tNo item found in the SinglyList!!!\n");
        }
        else
        {
            ListNode *temp=new ListNode();
            temp=list;
            list = list->next ;
            delete temp;
            length--;
        }
        return SUCCESS_VALUE;
    }

    ~LinkedList()
    {
        ListNode * temp ;
        while (list != 0)
        {
            temp=list->next;
            delete list;
            list = temp;
        }
        length=0;
        list=0;
    }
};

int main(void)
{
    LinkedList ll;

    while(1)
    {
        printf( "\t\tTHE SINGLY LINKED LIST\n");
        printf("\t-------------------------------------\n");
        printf("\n1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("\n4. Insert at Last. 5. Insert After any Item 6. Get Item at index. \n");
        printf("\n7.Delete First Item. 8.Print The List. 9.Exit\n");
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
                printf("\nItem Found!!!\n");
            else
                printf("\nItem Not found!!!\n");
        }
        else if(ch==4)
        {
            int item;
            scanf("%d", &item);
            ll.insertLast(item);
        }
        else if(ch==5)
        {
            int newValue,oldValue;
            scanf("%d %d",&oldValue,&newValue);
            ll.insertAfter(oldValue,newValue);
        }
        else if(ch==6)
        {
            int index;
            scanf("%d",&index);
            ll.getItemAt(index);
        }
        else if(ch==7)
        {
            ll.deleteFirst();
        }
        else if(ch==8)
        {
            ll.printList();
        }
        else if(ch==9)
        {
            break;
        }
    }
}
