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
    int insertItem(int item)
    {
        ListNode * newNode = new ListNode() ;
        newNode->item = item ;
        newNode->next = list ;
        list = newNode ;
        length++;
        return SUCCESS_VALUE ;
    }
    int deleteFirst()
    {

        if(list==0)
        {
            printf("\n\tNo item found in the Stack!!!\n");
        }
        else
        {
            ListNode *temp=new ListNode();
            temp=list;
            list = list->next ;
            length--;
            return temp->item;
        }
    }
     void printList()
    {
        if(list==0)
        {
            printf("\n\tThe Stack is empty!!!\n");
        }
        ListNode * temp;
        temp = list;
        printf("\n\tThe Stack is : \n");
        printf( "----------------------------\n");
        while(temp!=0)
        {
            printf("%d ", temp->item);
            temp = temp->next;
        }
        printf("\nLength: %d\n",length);
    }
};
class Stack
{
    LinkedList ll;
public:
    Stack()
    {

    }
    void push(int item)
    {
        ll.insertItem(item);
    }
    int pop()
    {
        return ll.deleteFirst();
    }
    void printStack()
    {
        ll.printList();
    }
};

int main(void)
{
    Stack st;

    while(1)
    {
        printf( "\t\tTHE STACK\n");
        printf("\t-------------------------------\n");
        printf("1. Push. 2. Pop. 3.Print the Stack 4. Exit. \n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            st.push(item);
        }
        else if(ch==2)
        {
            printf("%d\n",st.pop());
        }
        else if(ch==3)
        {
            st.printStack();
        }
        else if(ch==4)
        {
            break;
        }
    }

}
