#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<string> data;
vector<int> adjacency[6];
const int Elements = 6;
bool visited[Elements];
map<string, int> string_to_int;
vector<int> visit_order;

vector<int> stack;

int **distance_table = new int *[5];

string alphabet[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

void print_graph()
{
    cout << endl;
    for (int i = 0; i < Elements; i++)
    {
        // const int a = i;
        for (int j = 0; j < adjacency[i].size(); j++)
        {
            cout << alphabet[adjacency[i][j]] << " ";
        }

        cout << endl;
    }
}
void adjacency_list(int u, int v)
{
    adjacency[u].push_back(v);
    // adjacency[v].push_back(u);
}

void create_list()
{
    for (int i = 0; i < 26; i++)
    {
        string_to_int.insert(std::pair<string, int>(alphabet[i], i));
    }
    for (int i = 0; i < 6; i++)
    {
        visited[i] = false;
    }

    adjacency_list(string_to_int["a"], string_to_int["b"]);
    adjacency_list(string_to_int["a"], string_to_int["d"]);
    adjacency_list(string_to_int["a"], string_to_int["e"]);

    adjacency_list(string_to_int["b"], string_to_int["a"]);
    adjacency_list(string_to_int["b"], string_to_int["c"]);

    adjacency_list(string_to_int["c"], string_to_int["b"]);
    adjacency_list(string_to_int["c"], string_to_int["e"]);

    adjacency_list(string_to_int["d"], string_to_int["a"]);
    adjacency_list(string_to_int["d"], string_to_int["e"]);

    adjacency_list(string_to_int["e"], string_to_int["a"]);
    adjacency_list(string_to_int["e"], string_to_int["d"]);
    adjacency_list(string_to_int["e"], string_to_int["f"]);
    adjacency_list(string_to_int["e"], string_to_int["c"]);

    adjacency_list(string_to_int["f"], string_to_int["e"]);
}

class Queue
{
private:
    // string data;
    int root;
    int _end;
    vector<int> vec;

public:
    Queue()
    {
        root = 0;
        _end = 0;
    }
    int queue_size()
    {
        return _end - root + 1;
    }
    bool is_emty()
    {
        if (_end == root)
            return true;
        else
            return false;
    }
    void print_queue()
    {
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
    }

    void enqueue(int string)
    {
        vec.push_back(string);
        _end = _end + 1;
    }
    int dequeue()
    {
        int temp = vec[root];
        root = root + 1;
        // vec.pop_back();
        return temp;
    }
};
int minimum(int a, int b)
{
    if (a >= b)
        return b;
    else
        return a;
}
void print_visited()
{
    cout << "Visited = ";
    for (int i = 0; i < Elements; i++)
    {
        cout << visited[i] << " ";
    }
}

Queue myQueue = Queue();
void BFS()
{
    visited[0] = true; //"A is visited"
    // Initialize

    distance_table[0][0] = 0;
    visit_order.push_back(0);
    for (int j = 0; j < adjacency[0].size(); j++)
    {
        distance_table[0][adjacency[0][j]] = 1;
        myQueue.enqueue(adjacency[0][j]);
    }
    // myQueue.print_queue();
    for (int i = 1; i < Elements - 1; i++)
    {
        int index = myQueue.dequeue();
        cout << "index = " << index << " " << endl;
        int value = distance_table[i - 1][index];
        cout << "value = " << value << endl;
        visit_order.push_back(index);
        for (int k = 0; k < Elements; k++)
        {
            distance_table[i][k] = distance_table[i - 1][k];
        }
        for (int j = 0; j < adjacency[index].size(); j++)
        {
            cout << " adjacency[index][j] " << adjacency[index][j] << endl;
            if (visited[adjacency[index][j]] == false)
            {
                int temp_min = value + 1;
                int min = minimum(temp_min, distance_table[i - 1][adjacency[index][j]]);
                // cout << "temp_min = " << temp_min;
                distance_table[i][adjacency[index][j]] = min;
                myQueue.enqueue(adjacency[index][j]);
            }
        }
        visited[index] = true;
    }
    print_visited();
    cout << endl;
}
void stack_print()
{
    cout << "stack = ";
    for (int i = 0; i < stack.size(); i++)
        cout << stack[i] << " ";

    cout << endl;
}
void DFS()
{
    int i = 0;
    int j = 0;
    bool flag = true;
    visited[0] = true;
    visit_order.push_back(0);
    while (1)
    {
        // cout << "somthing";
        if (stack.size() == 0 && adjacency[i][j] == adjacency[i][adjacency[i].size() - 1])
            break;

        stack_print();
        print_visited();
        cout << endl;
        cout << i << "   " << j << "    " << adjacency[i][j] << "   " << adjacency[i][adjacency[i].size() - 1] << endl;
        flag = true;
        if (adjacency[i][j] == adjacency[i][adjacency[i].size() - 1] && visited[adjacency[i][j]] == true)
        {
            cout << "pop!!! " << endl;
            i = stack[stack.size() - 1];
            stack.pop_back();
            j = 0;
            flag = false;
        }

        if (visited[adjacency[i][j]] == false)
        {
            stack.push_back(i);
            i = adjacency[i][j];
            j = 0;
            visited[i] = true;
            visit_order.push_back(i);
            flag = false;
        }

        if (j < adjacency[i].size() && flag == true)
            j++;
    }
    print_visited();
    cout << endl;
}

int main()
{
    // Create graph
    create_list();

    for (int i = 0; i < Elements - 1; i++)
    {

        distance_table[i] = new int(Elements);
    }
    for (int i = 0; i < Elements - 1; i++)
    {
        for (int j = 0; j < Elements; j++) // distance_table 5x6
        {
            distance_table[i][j] = INT16_MAX;
        }
    }

    int temp1, temp2, method;
    cout << "Please input 1 for BFS()  2 for DFS() ";
    cin >> method;

    
    // print_graph();
    if (method == 1)
    {
        BFS();
        cout << endl
             << "Visting order is : " << endl;
        
        for (int j = 0; j < Elements; j++)
        {
            if (j > 0 && visit_order[j] == 0)
                visit_order[j] = 5;

            cout << alphabet[visit_order[j]] << " ";
        }
        cout << endl;

        for (int j = 0; j < Elements; j++)
        {
            cout << distance_table[3][j] << " ";
        }
    }

    if (method == 2)
    {
        DFS();
        cout << endl
             << "Visting order is : " << endl;
        
        for (int j = 0; j < Elements; j++)
        {
            // if (j > 0 && visit_order[j] == 0)
            //     visit_order[j] = 5;

            cout << alphabet[visit_order[j]] << " ";
        }
        cout << endl;

        // for (int j = 0; j < Elements; j++)
        // {
        //     cout << distance_table[3][j] << " ";
        // }
    }
}
