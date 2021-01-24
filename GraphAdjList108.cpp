#include<stdio.h>
#include<stdlib.h>
#define NULL_VALUE -999999
#define INFINITY 999999
#define WHITE 1
#define GREY 2
#define BLACK 3

class Queue
{
    int queueInitSize ;
    int queueMaxSize;
    int * data;
    int length;
    int front;
    int rear;
public:
    Queue();
    ~Queue();
    void enqueue(int item); //insert item in the queue
    int dequeue(); //returns the item according to FIFO
    bool empty(); //return true if Queue is empty
};
Queue::Queue()
{
    queueInitSize = 2 ;
    queueMaxSize = queueInitSize;
    data = new int[queueMaxSize] ; //allocate initial memory
    length = 0 ;
    front = 0;
    rear = 0;
}
void Queue::enqueue(int item)
{
    if (length == queueMaxSize)
    {
        int * tempData ;
        //allocate new memory space for tempList
        queueMaxSize = 2 * queueMaxSize ;
        tempData = new int[queueMaxSize] ;
        int i, j;
        j = 0;
        for( i = rear; i < length ; i++ )
        {
            tempData[j++] = data[i] ; //copy items from rear
        }
        for( i = 0; i < rear ; i++ )
        {
            tempData[j++] = data[i] ; //copy items before rear
        }
        rear = 0 ;
        front = length ;
        delete[] data ; //free the memory allocated before
        data = tempData ; //make list to point to new memory
    }
    data[front] = item ; //store new item
    front = (front + 1) % queueMaxSize ;
    length++ ;
}
bool Queue::empty()
{
    if(length == 0)
        return true ;
    else
        return false ;
}
int Queue::dequeue()
{
    if(length == 0)
        return NULL_VALUE ;
    int item = data[rear] ;
    rear = (rear + 1) % queueMaxSize ;
    length-- ;
    return item ;
}
Queue::~Queue()
{
    if(data)
        delete[] data; //deallocate memory
    data = 0; //set to NULL
}

//****************Queue class ends here************************

//****************Dynamic ArrayList class based************************
class ArrayList
{
    int * list;
    int length ;
    int listMaxSize ;
    int listInitSize ;
public:
    ArrayList() ;
    ~ArrayList() ;
    int searchItem(int item) ;
    void insertItem(int item) ;
    void removeItem(int item) ;
    void removeItemAt(int item);
    int getItem(int position) ;
    int getLength();
    bool empty();
    void printList();
} ;
ArrayList::ArrayList()
{
    listInitSize = 2 ;
    listMaxSize = listInitSize ;
    list = new int[listMaxSize] ;
    length = 0 ;
}
void ArrayList::insertItem(int newitem)
{
    int * tempList ;
    if (length == listMaxSize)
    {
        //allocate new memory space for tempList
        listMaxSize = 2 * listMaxSize ;
        tempList = new int[listMaxSize] ;
        int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        delete[] list ; //free the memory allocated before
        list = tempList ; //make list to point to new memory
    }

    list[length] = newitem ; //store new item
    length++ ;
}
int ArrayList::searchItem(int item)
{
    int i = 0;
    for (i = 0; i < length; i++)
    {
        if( list[i] == item )
            return i;
    }
    return NULL_VALUE;
}
void ArrayList::removeItemAt(int position) //do not preserve order of items
{
    if ( position < 0 || position >= length )
        return ; //nothing to remove
    list[position] = list[length-1] ;
    length-- ;
}
void ArrayList::removeItem(int item)
{
    int position;
    position = searchItem(item) ;
    if ( position == NULL_VALUE )
        return ; //nothing to remove
    removeItemAt(position) ;
}
int ArrayList::getItem(int position)
{
    if(position < 0 || position >= length)
        return NULL_VALUE ;
    return list[position] ;
}
int ArrayList::getLength()
{
    return length ;
}
bool ArrayList::empty()
{
    if(length==0)
        return true;
    else
        return false;
}
void ArrayList::printList()
{
    int i;
    for(i=0; i<length; i++)
        printf("%d ", list[i]);
    printf("Current size: %d, current length: %d\n", listMaxSize, length);
}
ArrayList::~ArrayList()
{
    if(list)
        delete [] list;
    list = 0 ;
}
//******************ArrayList class ends here*************************

//******************Graph class starts here**************************
class Graph
{
    int nVertices, nEdges ;
    bool directed ;
    ArrayList  * adjList ;
    int *color,*parent,*dist;
    int *start,*finish;
    int time;
    //define other variables required for bfs such as color, parent, and dist
    //you must use pointers and dynamic allocation
public:
    Graph(bool dir = false);
    ~Graph();
    void setnVertices(int n);
    void addEdge(int u, int v);
    void removeEdge(int u, int v);
    bool isEdge(int u, int v);
    int getDegree(int u);
    bool hasCommonAdjacent(int u, int v);
    int getDist(int u, int v);
    void printGraph();
    void bfs(int source); //will run bfs in the graph
    void dfs(int source); //will run dfs in the graph
    void dfsVisit();
};
Graph::Graph(bool dir)
{
    nVertices = 0 ;
    nEdges = 0 ;
    adjList = 0 ;
    directed = dir ;
    color=0;
    parent=0;
    dist=0;
    start=0;
    finish=0;
    time=0;
    //set direction of the graph
    //define other variables to be initialized
}
void Graph::setnVertices(int n)
{
    this->nVertices = n ;

    if(adjList != NULL)
    {
        delete[] adjList ;   //delete previous list
    }
    if(color != NULL)
    {
        delete[] color;
    }
    if(parent != NULL)
    {
        delete[] parent;
    }
    if(dist != NULL)
    {
        delete[] dist;
    }
    if(start != NULL)
    {
        delete[] start;
    }
    if(finish != NULL)
    {
        delete[] finish;
    }
    color=new int[nVertices];
    dist=new int[nVertices];
    parent=new int[nVertices];
    start=new int[nVertices];
    finish=new int[nVertices];
    adjList = new ArrayList[nVertices] ;
}
void Graph::addEdge(int u, int v)
{
    if(u >= nVertices|| v >= nVertices)
    {
        printf("Vertex is out of Range!!!\n");
    }
    if(u < 0 || v < 0)
    {
        printf("Invalid Input!!!!\n");
    }
    //vertex out of range
    this->nEdges++ ;
    adjList[u].insertItem(v) ;
    if(!directed)
        adjList[v].insertItem(u) ;
}
void Graph::removeEdge(int u, int v)
{
    //write this function
    if(u >= nVertices|| v >= nVertices)
    {
        printf("Vertex is out of Range!!!\n");
    }
    if(u < 0 || v < 0)
    {
        printf("Invalid Input!!!!\n");
    }
    adjList[u].removeItem(v);
    if(!directed)
        adjList[v].removeItem(u);
}
bool Graph::isEdge(int u, int v)
{
    //returns true if (u,v) is an edge, otherwise should return false
   if(u >= nVertices|| v >= nVertices)
    {
        printf("Vertex is out of Range!!!\n");
        return false;
    }
    if(u < 0 || v < 0)
    {
        printf("Invalid Input!!!!\n");
        return false;
    }
    if((adjList[u].searchItem(v) != NULL_VALUE) || (adjList[v].searchItem(u) != NULL_VALUE))
        return true;
    else
        return false;
}
int Graph::getDegree(int u)
{
    //returns the degree of vertex u
    if(u<0 || u >= nVertices)
    {
        printf("Invalid Input!!!\n");
        return 0;
    }
    else
        return adjList[u].getLength();
}
bool Graph::hasCommonAdjacent(int u, int v)
{
    //returns true if vertices u and v have common adjacent vertices
    if(u >= nVertices|| v >= nVertices)
    {
        printf("Vertex is out of Range!!!\n");
        return false;
    }
    if(u < 0 || v < 0)
    {
        printf("Invalid Input!!!!\n");
        return false;
    }
    int len,value;
    len=adjList[u].getLength();
    for(int i=0; i<len; i++)
    {
        value=adjList[u].getItem(i);
        if(adjList[v].searchItem(value) != NULL_VALUE)
            return true;
    }
    return false;
}
void Graph::bfs(int source)
{
    //complete this function
    //initialize BFS variables
    int len,val;
    for(int i=0; i<nVertices; i++)
    {
        color[i] = WHITE ;
        parent[i] = -1 ;
        dist[i] = INFINITY ;
    }
    Queue q ;
    color[source] = GREY;
    dist[source] = 0 ;
    q.enqueue(source) ;
    while(q.empty() == false)
    {
        //complete this part
        int u=q.dequeue();
        len=adjList[u].getLength();
        for(int i=0; i<len; i++)
        {
            val=adjList[u].getItem(i);
            if((dist[val]>dist[u]+1) && (color[val] == WHITE))
            {
                q.enqueue(val);
                dist[val] = dist[u]+1;
                parent[val] = u;
                color[val] = GREY;
            }
        }
        color[u]=BLACK;
    }
}
void Graph::dfsVisit()
{
    time=0;
    for(int i=0; i<nVertices; i++)
    {
        color[i] = WHITE ;
        parent[i] = -1 ;
        dist[i] = INFINITY ;
        start[i]=0;
        finish[i]=0;
    }
    for(int i=0; i<nVertices; i++)
    {
        if(color[i]==WHITE)
            dfs(i);
    }
}
void Graph::dfs(int source)
{
    //write this function
    time++;
    start[source]=time;
    printf("The Source : %d\n",source);
    color[source]=GREY;
    int len=adjList[source].getLength();
    for(int i=0; i<len; i++)
    {
        if(color[adjList[source].getItem(i)]==WHITE)
        {
            parent[adjList[source].getItem(i)]=source;
            dfs(adjList[source].getItem(i));
        }
    }
    color[source]=BLACK;
    time++;
    finish[source]=time;
}
int Graph::getDist(int u, int v)
{
    //returns the shortest path distance from u to v
    //must call bfs using u as the source vertex, then use distance array to find the distance
    if(u >= nVertices|| v >= nVertices)
    {
        printf("Vertex is out of Range!!!\n");
        return INFINITY;
    }
    if(u < 0 || v < 0)
    {
        printf("Invalid Input!!!!\n");
    }
    bfs(u);
    return dist[v];
}
void Graph::printGraph()
{
    printf("\nNumber of vertices: %d , Number of edges: %d\n", nVertices, nEdges);
    for(int i=0; i<nVertices; i++)
    {
        printf("%d: ", i);
        for(int j=0; j<adjList[i].getLength(); j++)
        {
            printf(" %d ", adjList[i].getItem(j));
        }
        printf("\n");
    }
}
Graph::~Graph()
{
    //write your destructor here
    if(start)
    {
        delete[] start;
        start=0;
    }
    if(finish)
    {
        delete[] finish;
        finish=0;
    }
    if(color)
    {
        delete[] color;
        color=0;
    }
    if(parent)
    {
        delete[] parent;
        parent=0;
    }
    if(dist)
    {
        delete[] dist;
        dist=0;
    }
    if(adjList)
    {
        delete[] adjList;
        adjList=0;
    }
}

//**********************Graph class ends here******************************

//******main function to test your code*************************
int main(void)
{
    Graph g;
    printf("\tTHE GRAPH WITH ADJACENT LIST\n");
    printf("-----------------------------------------------------\n");
    while(1)
    {
        printf("1.Create new Graph 2. Add edge. 3. Remove Edge 4.IsEdge \n");
        printf("5. Get Degree of Certain Vertex. 6. Has Common Adjacent Vertex 7. Get Distance of two Vertices\n");
        printf("8. Run DFS on graph 9. Print Graph 10. Exit\n");
        int ch;
        scanf("%d",&ch);
        if(ch == 1)
        {
            int n;
            printf("Enter number of Vertices : \n");
            scanf("%d", &n);
            printf("New Graph Created!!!!\n");
            g.setnVertices(n);
        }
        else if(ch == 2)
        {
            int v1, v2;
            scanf("%d %d", &v1, &v2);
            g.addEdge(v1,v2);
        }
        else if(ch == 3)
        {
            int v1, v2;
            scanf("%d%d", &v1, &v2);
            g.addEdge(v1, v2);
        }
        else if(ch == 4)
        {
            int v1, v2;
            scanf("%d%d", &v1, &v2);
            if(g.isEdge(v1,v2))
                printf("Edge between %d and %d exists!!!!\n",v1,v2);
            else
                printf("No edge between %d and %d!!!!\n",v1,v2);
        }
        else if(ch == 5)
        {
            int v;
            scanf("%d",&v);
            printf("Degree of Vertex %d is : %d\n",v,g.getDegree(v));
        }
        else if(ch == 6)
        {
            int v1, v2;
            scanf("%d%d", &v1, &v2);
            if(g.hasCommonAdjacent(v1,v2))
                printf("Vertex %d and Vertex %d has a common vertex!!!!\n",v1,v2);
            else
                printf("Vertex %d and Vertex %d do not have common vertex!!!!\n",v1,v2);
        }
        else if(ch == 7)
        {
            int v1, v2;
            scanf("%d%d", &v1, &v2);
            printf("Distance between Vertex %d and Vertex %d is : %d\n",v1,v2,g.getDist(v1,v2));
        }
        else if(ch == 8)
        {
            printf("Running DFS on the Graph :\n");
            g.dfsVisit();
        }
        else if(ch == 9)
        {
            g.printGraph();
        }
        else if(ch == 10)
        {
            printf("Exiting From Here!!!!");
            break;
        }
    }
}
