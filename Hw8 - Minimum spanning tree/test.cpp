#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define V 9
int graph[V][V];
int visited[V];
vector<int> stack;
bool pop[V];

struct node
{
    int u;
    int v;
    int value;
};
struct link
{
    int u;
    int v;
    int value;
};
void add_vertex(int u, int v, int value)
{
    graph[u][v] = value;
    graph[v][u] = value;
}
void print_graph()
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << graph[i][j] << "   ";
        }
        cout << endl;
    }
}
void create_graph()
{
    for (int i = 0; i < V; i++)
    {
        // edge_visited[i] = false;
        visited[i] = 0;
        pop[i] = false;
        for (int j = 0; j < V; j++)
        {
            graph[i][j] = 0;
            // path_visited[i][j] = false;
        }
    }
    // add_vertex(0, 1, 1);
    add_vertex(6, 7, 4);
    add_vertex(7, 8, 4);
    add_vertex(8, 6, 3);
    // add_vertex(0, 3, 3);
}
link *create_link(int u, int v, int value)
{
    link *temp = new link();
    temp->u = u;
    temp->v = v;
    temp->value = value;
    return temp;
}
struct
{
    bool operator()(node *a, node *b)
    {
        return a->value < b->value;
    }
} comparator;

bool isAllVisited()
{
    int count = 0;
    for (int i = 0; i < 9; i++)
    {
        if (visited[i] >= 1)
            count++;
    }
    if (count == 3)
        return true;
    else
        return false;
}
void print_visited()
{

    for (int i = 0; i < V; i++)
    {
        cout << visited[i] << " ";
    }
    cout << endl;
}
bool isCycle()
{

    // visited[0] = 1;
    // int i = 0;
    int j = 0;
    bool flag;
    int start = 6;
    int root = start;
    visited[6] = 1;
    int visited_count = 0;
    while (1)
    {
        flag = true;
        
        
        if (isAllVisited() && stack.size() == 0)
            break;
        print_visited();

        for (int j = 0; j < V; j++)
        {
            if (graph[start][j] != 0 && visited[j] == 0)
            {
                visited[j] = 1;
                cout << "start " <<start << endl;
                stack.push_back(start);
                start = j;
                visited_count++;
                break;
            }
            else if (j == V - 1 )
            {

                cout << "stack size " << stack.size() << endl;
        
                    
                
                start = stack[stack.size() - 1];
                cout << "pop = " << start << endl;
                visited[start]--;
                stack.pop_back();
                pop[start] = true;
            }
            else if (graph[start][j] != 0 && visited[j] == 1 && pop[start] == false)
            {
                visited[j] = 2;
            }
            else if (graph[start][j] != 0 && visited[j] == 2 && visited_count >= 2 && pop[start] == false)
            {
                cout << "start = , j = " << start << " " << j << endl;
                return true;
            }
            cout << "visited count " << visited_count << " ";
        
            // cout << "visited[j] = " << visited[j] <<" " << visited_count << endl;
        }
    }

    return false;
}
int main()
{
    node *temp = new node();
    temp->u = 0;
    temp->v = 1;
    temp->value = 10;
    vector<node *> vec;

    vec.push_back(temp);

    node *temp1 = new node();
    temp1->u = 0;
    temp1->v = 1;
    temp1->value = 3;
    vec.push_back(temp1);
    node *temp2 = new node();
    temp2->u = 0;
    temp2->v = 1;
    temp2->value = 4;
    vec.push_back(temp2);
    sort(vec.begin(), vec.end(), comparator);
    cout << vec[0]->value << "   " << vec[1]->value << "  " << vec[2]->value;
    cout << endl
         << endl;
    create_graph();
    print_graph();
    cout << endl
         << isCycle();
}