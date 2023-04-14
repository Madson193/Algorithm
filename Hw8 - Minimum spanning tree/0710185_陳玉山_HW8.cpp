#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
#define V 9
int graph[V][V];
bool path_visited[V][V];
bool edge_visited[V];
int visit_count = 1;

struct link
{
    int u;
    int v;
    int value;
};

link *create_link(int u, int v, int value)
{
    link *temp = new link();
    temp->u = u;
    temp->v = v;
    temp->value = value;
    return temp;
}

struct compare
{
    bool operator()(const link *a, const link *b)
    {
        return a->value > b->value;
    }
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
        edge_visited[i] = false;
        for (int j = 0; j < V; j++)
        {
            graph[i][j] = 0;
            path_visited[i][j] = false;
        }
    }
    add_vertex(0, 1, 4);
    add_vertex(0, 7, 8);

    add_vertex(1, 7, 11);
    add_vertex(1, 2, 8);

    add_vertex(2, 8, 2);
    add_vertex(2, 3, 7);
    add_vertex(2, 5, 4);

    add_vertex(3, 5, 14);
    add_vertex(3, 4, 9);

    add_vertex(4, 5, 10);

    add_vertex(5, 6, 2);

    add_vertex(6, 8, 6);

    add_vertex(6, 7, 1);

    add_vertex(7, 8, 7);
}

priority_queue<link *, vector<link *>, compare> pq;
vector<link *> stack;
void prim(int start)
{ // start = 6
    link *min_path;
    edge_visited[start] = true;
    while (1)
    {
        if (visit_count == V)
            break;
        // cout << "something!";
        for (int j = 0; j < V; j++)
        {
            if (graph[start][j] != 0)
            {
                link *temp = create_link(start, j, graph[start][j]);
                pq.push(temp);
            }
        }
        min_path = pq.top();
        pq.pop();

        while (edge_visited[min_path->v] == true && pq.empty() == false)
        {
            // cout << "pq.size()= " <<pq.size() << endl;

            min_path = pq.top();
            pq.pop();
        }

        cout << "u = " << min_path->u << " v = " << min_path->v << " weight = " << min_path->value << endl;
        // cout << "count = " << visit_count << endl;

        start = min_path->v;
        stack.push_back(min_path);
        edge_visited[min_path->v] = true;
        visit_count++;
    }
}
void stack_print()
{
    int total = 0;
    for (int i = 0; i < V - 1; i++)
    {
        total = total + stack[i]->value;
        cout << stack[i]->value << " ";
    }
    cout << endl
         << "total = " << total;
}
void visited_print()
{
    cout << "Visited = ";
    for (int i = 0; i < V; i++)
    {
        cout << edge_visited[i] << " ";
    }
}
//////////////////////////////////////////////////////////////////////////////////
// Krustal part
// Krustal

struct node
{
    int u;
    int v;
    int value;
};
node *create_node(int u, int v, int value)
{
    node *temp = new node();
    temp->u = u;
    temp->v = v;
    temp->value = value;
    return temp;
}


vector<node *> node_store;
vector<node *> mst;
vector<int> set;
vector<int> new_stack;
int start1;

bool pop[V];

struct
{
    bool operator()(node *a, node *b)
    {
        return a->value > b->value;
    }
} comparator;

bool isAllVisited(int *visited)
{
    int count = 0;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] >= 1)
            count++;
    }
    if (count == set.size())
        return true;
    else
        return false;
}
void print_visited(int *visited)
{

    for (int i = 0; i < V; i++)
    {
        cout << visited[i] << " ";
    }
    cout << endl;
}
bool find(vector<int> vec, int value)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == value)
            return true;
    }
    return false;
}
bool isCycle()
{



        for (int i =0; i<set.size();i++){
            cout << "set[i] = " << set[i]; 
        }
    
    
    cout<<endl << "set.size() = " << set.size() <<endl; 

    
    int *visited = new int[V];
    const int temp_size = V;
    
    int **graph_temp = new int *[temp_size];
    
    for (int i = 0; i < V; i++)
    {

        graph_temp[i] = new int(temp_size);
        visited[i] = 0;
        pop[i] = false;
    }
    
    for (int i = 0; i < V; i++)
    {
        // edge_visited[i] = false;
        for (int j = 0; j < V; j++)
        {

            graph_temp[i][j] = 0;
            // path_visited[i][j] = false;
        }
    }
    // cout << "u v " << mst[2]->u << " " << mst[2]->v ;
    cout << endl<<endl;
    
    cout << "mst[0] -> u = "<<mst[mst.size()-1] -> u << endl;
    start1 = mst[mst.size()-1] -> u;
    visited[mst[mst.size()-1] -> u] = 1;
    for (int i = 0; i < mst.size(); i++)
    {

        graph_temp[mst[i]->u][mst[i]->v] = mst[i]->value;
        graph_temp[mst[i]->v][mst[i]->u] = mst[i]->value;
    }
    for (int i = 0; i < V; i++)
    {
        // edge_visited[i] = false;
        for (int j = 0; j < V; j++)
        {
            cout << graph_temp[i][j]<< " ";
            // path_visited[i][j] = false;
        }
        cout << endl;
    }
    cout << endl;
    for (int i =0; i<V ; i++){
        cout << pop[i] << " ";
    }
    cout << endl << endl;
    // visited[0] = 1;
    // int i = 0;
    int j = 0;
    bool flag;

    int visited_count = 0;
    while (1)
    {
        flag = true;
        cout << " visit_count "<<visit_count << " "<<endl;
        if (isAllVisited(visited) && new_stack.size() == 0)
            break;
        print_visited(visited);
        
        for (int j = 0; j < V; j++)
        {
            //  cout << "somthing" << endl;
            // cout << "start = " << start1 << " " << "j = " << j << endl;
            cout << "stack size = " << new_stack.size();
            if (graph_temp[start1][j] != 0 && visited[j] == 0)
            {
                cout << "True";
                visited[j] = 1;
                cout << "visited[j] = " <<visited[j];
                cout << "start " <<start1 << endl;
                new_stack.push_back(start1);
                start1 = j;
                visited_count++;
                break;
            }
            else if (j == V - 1 )
            {

                cout << "stack size " << new_stack.size() << endl;
        
                    
                
                start1 = new_stack[new_stack.size() - 1];
                cout << "pop = " << start1 << endl;
                visited[start1]--;
                new_stack.pop_back();
                pop[start1] = true;
            }
            else if (graph_temp[start1][j] != 0 && visited[j] == 1 && pop[start1] == false)
            {
                visited[j] = 2;
            }
            else if (graph_temp[start1][j] != 0 && visited[j] == 2 && visited_count >= 2 && pop[start1] == false)
            {
                
                cout << "start = , j = " << start1 << " " << j << endl;
                return true;

                
            }

            // cout << "visited[j] = " << visited[j] <<" " << visited_count << endl;
        }
    }
    // for (int i = 0; i < temp_size; i++)
    // {
    //     delete[] graph_temp[i];
    // }
    // delete[] graph_temp;
    // delete[] visited;
    // new_stack.clear();
    return false;
}

void sortedNode()
{
    bool node_visited[V];
    for (int i = 0; i < V; i++)
        node_visited[i] = false;

    for (int i = 0; i < V; i++)
    {

        for (int j = 0; j < V; j++)
        {
            if (node_visited[j] == false && graph[i][j] != 0)
            {
                // cout << "something";
                node *temp = create_node(i, j, graph[i][j]);
                node_store.push_back(temp);
            }
        }
        node_visited[i] = true;
    }

    cout << endl;
    sort(node_store.begin(), node_store.end(), comparator);
    for (int i = 0; i < node_store.size(); i++)
    {
        cout << node_store[i]->value << " ";
    }
}


void kruskal()
{

    mst.push_back(node_store[node_store.size() - 1]);
    set.push_back(mst[mst.size() - 1]->u);
    set.push_back(mst[mst.size() - 1]->v);
    node_store.pop_back();
    mst.push_back(node_store[node_store.size() - 1]);
    if (!find(set, mst[mst.size() - 1]->u))
        set.push_back(mst[mst.size() - 1]->u);
    if (!find(set, mst[mst.size() - 1]->v))
        set.push_back(mst[mst.size() - 1]->v);
    node_store.pop_back();
    // cout << mst[0]->value << " " << mst[1]->value;
    while (node_store.size() > 0)
    {

        mst.push_back(node_store[node_store.size() - 1]);
        if (!find(set, mst[mst.size() - 1]->u))
            set.push_back(mst[mst.size() - 1]->u);
        if (!find(set, mst[mst.size() - 1]->v))
            set.push_back(mst[mst.size() - 1]->v);
        node_store.pop_back();
        cout << "something";
        if (isCycle())
        {
            
            mst.pop_back();
        }
        cout << mst[mst.size() - 1]->value << " ";
    }
    cout << endl;
    for (int i = 0; i < mst.size(); i++)
    {
        cout << mst[i]->value << " ";
    }
}
int main()
{

    create_graph();
    print_graph();
    // cout << "Input which algorithm? 1: Prim    2: Kruskal   ";
    // int input;
    // cin >> input;

    // if (input == 1)
    // {
        prim(6);
        stack_print();
        cout << endl;
        visited_print();
    // }
    // else if (input == 2){
    //     sortedNode();

    // }

    // sortedNode();
    // cout << endl;
    // kruskal();
}