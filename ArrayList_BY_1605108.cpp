#include<stdio.h>
#include<stdlib.h>

#define LIST_INIT_SIZE 2
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

int listMaxSize;
int *list;
int length;

void initializeList()
{
    listMaxSize = LIST_INIT_SIZE;
    list = (int*)malloc(sizeof(int)*listMaxSize) ;
    length = 0 ;
}

int getlength()
{
    return length;
}

int searchItem(int item)
{
    int i = 0;
    for (i = 0; i < length; i++)
    {
        if( list[i] == item )
            return i;
    }
    return NULL_VALUE;
}

int insertItemAt(int pos,int item)
{
    if(listMaxSize==0)
        initializeList();
    if ( pos > length )
        return NULL_VALUE;
    int * tempList ;
    if (length == listMaxSize)
    {
        //allocate new memory space for tempList
        listMaxSize = 2 * listMaxSize ;
        tempList = (int*) malloc (listMaxSize*sizeof(int)) ;
        int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        free(list) ; //free the memory allocated before
        list = tempList ; //make list to point to new memory
    }
    length++;
    list[length-1] = list[pos] ;
    list[pos] = item;
    return SUCCESS_VALUE;
}

int insertItem(int newitem)
{
    if(listMaxSize==0)
        initializeList();
    int * tempList ;
    if (length == listMaxSize)
    {
        //allocate new memory space for tempList
        listMaxSize = 2 * listMaxSize ;
        tempList = (int*) malloc (listMaxSize*sizeof(int)) ;
        int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        free(list) ; //free the memory allocated before
        list = tempList ; //make list to point to new memory
    }
    list[length] = newitem ; //store new item
    length++ ;
    return SUCCESS_VALUE ;
}

void shrink()
{
    int * tmplist;
    listMaxSize=(listMaxSize/2);
    tmplist = (int*) malloc (listMaxSize*sizeof(int)) ;
    int i;
    for( i = 0; i < length ; i++ )
    {
        tmplist[i] = list[i] ;
    }
    free(list) ;
    list = tmplist ;
}

int deleteItemAt(int position) //version 2, do not preserve order of items
{
    if ( position >= length )
        return NULL_VALUE;
    if(length==(listMaxSize/2) && listMaxSize>LIST_INIT_SIZE)
        shrink();
    list[position] = list[length-1] ;
    length-- ;
    return list[position];
}

int deleteItem(int item)
{
    int position;
    position = searchItem(item) ;
    if ( position == NULL_VALUE )
        return NULL_VALUE;
    deleteItemAt(position) ;
    if(length==(listMaxSize/2) && listMaxSize>LIST_INIT_SIZE)
        shrink();
    return SUCCESS_VALUE ;
}

int deleteLast()
{
    list[length-1] = list[length-2] ;
    length--;
    if(length==(listMaxSize/2) && listMaxSize>LIST_INIT_SIZE)
        shrink();
    return SUCCESS_VALUE;
}

int deleteAll()
{
    while(length!=0)
        deleteLast();
}

void printList()
{
    int i;
    for(i=0; i<length; i++)
        printf("%d ", list[i]);
    printf("Current size: %d, current length: %d\n", listMaxSize, length);
}

void clear()
{
    deleteAll();
    free(list);
    listMaxSize=0;
}

/*int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. Delete item at. 3. Delete item.\n");
        printf("4. Insert new item at. 5. Print. 6. get length. 7.Delete last item.\n");
        printf("8.Delete All items. 9.clear list. 10.exit.\n");
        int ch;
        scanf("%d",&ch);
        if(ch == 1)
        {
            int item;
            scanf("%d", &item);
            insertItem(item);
        }
        else if(ch == 2)
        {
            int pos;
            scanf("%d", &pos);
            deleteItemAt(pos);
        }
        else if(ch == 3)
        {
            int item;
            scanf("%d", &item);
            deleteItem(item);
        }
        else if(ch == 4)
        {
            int position,item;
            scanf("%d %d",&position,&item);
            insertItemAt(position,item);
        }
        else if(ch == 5)
        {
            printList();
        }
        else if(ch == 6)
        {
            printf("the current length is %d\n",getlength());
        }
        else if(ch == 7)
        {
            deleteLast();
        }
        else if(ch == 8)
        {
            deleteAll();
        }
        else if(ch == 9)
        {
            clear();
        }
        else if(ch == 10)
        {
            break;
        }
    }

}*/
/*int main(void)
{
    initializeList();
    int i,temp;
    char str[100];
    gets(str);
    for(i=0; str[i]!='\0'; i++)
    {
        if(str[i]>='0'&&str[i]<='9')
        {
            insertItem(str[i]-48);
        }
        if(str[i]=='+')
        {
            temp=(list[length-2])+(list[length-1]);
            deleteLast();
            deleteLast();
            insertItem(temp);
        }
        if(str[i]=='-')
        {
            temp=(list[length-2])-(list[length-1]);
            deleteLast();
            deleteLast();
            insertItem(temp);
        }
        if(str[i]=='*')
        {
            temp=(list[length-2])*(list[length-1]);
            deleteLast();
            deleteLast();
            insertItem(temp);
        }
        if(str[i]=='/')
        {
            if(list[length-1]==0)
            {
                printf("error...:(");
                return 0;
            }
            else
            {
                temp=(list[length-2])/(list[length-1]);
            }
            deleteLast();
            deleteLast();
            insertItem(temp);
        }
    }
    printList();
    clear();
}*/
