#include <iostream>
#include <ctime>
#define COUNT 10
using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
    Node* parent;
};

Node* get_node(int data)
{
    Node* temp = new Node();
    temp -> value = data;
    temp -> left = NULL;
    temp -> right = NULL;
    temp -> parent = NULL;
    return temp;
}
Node* Tree_insert(Node* root, Node* new_node)
{
    if (root == NULL)
    {
        root = new_node;
        new_node -> parent = NULL;
    }
    else 
    {
        Node* x = root;
        Node* y; //this one is to track the parent node
        while (x!=NULL)
        {
            y = x;
            if (new_node->value <= x->value)
                x = x->left;
            else x = x -> right;
        }
        new_node -> parent = y;
        if (new_node -> value < y->value)
            y -> left = new_node;
        else y -> right = new_node;

    }
    return root;   
}

void inorder_tree_walk(Node* root)
{   
    Node* x = root;
    if (x == NULL)
        return;
    
    inorder_tree_walk(x->left);
    cout << x->value << " ";
    inorder_tree_walk(x->right);
    // cout << x -> value << " ";
}
Node* tree_minimum(Node* root)
{
    Node* x = root;
    Node* y;
    while (x!=NULL)
    {   y = x; 
        x = x->left;
    }
    cout << y->value;
    return y;
    
}
Node* tree_maximum(Node* root)
{
    Node* x = root;
    Node* y;
    while (x!=NULL)
    {
        y = x;
        x = x->right;
    }
    cout << y->value;
    return y;
}
Node* search(Node* root, int data)
{
    Node* x = root;
    
    while (x!= NULL)
    {   
        if (x->value == data)
            return x;
        else if (x->value > data)
            x = x->left;
        else x = x -> right;
    }
    return 0;
}

// void tree_delete(Node* root, int data)
// {
//     Node* temp = search(root, data);
//     book check1, check2;
//     check1 = false; check2 = false;
//     int case;
//     Node* y;
//     if (temp->right==NULL)
//         check2 = true;
//     if (temp->left ==NULL)
//         check1 = true;

//     if (check1 == true && check2 == true)
//         case = 1;
//     else if (check1 == false && check2 == true)
//         case = 2;
//     else if (check1 == true && check2 == false)
//         case = 3;
//     else if (check1 == false && check2 == false)
//         case = 4;

    
//     if (case == 1)
//     {

//     }
// }

Node* tree_delete(Node* root, int data)
{
    Node* temp = search(root,data);
    Node* x = NULL;
    Node* root_temp = root;
    Node* y;
    // if(root->right==NULL)
    //     cout << "yes";
    // if(root->left!=NULL)
    //     // cout << "Yes";
    if (temp == root)
    {
         
        if (root->left == NULL && root -> right != NULL)
        {
            root->right->parent =NULL;
            root_temp = root->right;
        }
        if (root->left != NULL && root -> right == NULL)
        {
            // cout <<"thid";
            root->left->parent =NULL;
            root_temp = root->left;
        }
        if (root->left != NULL && root -> right != NULL)
        {
            if(temp->left > temp->right)
            {
                temp->left->parent = NULL;
                temp->right->parent =NULL;
                root_temp = temp -> right;
                root_temp = Tree_insert(temp->left,temp->right);
            }
            else 
            {
                temp->left->parent = NULL;
                temp->right->parent =NULL;
                root_temp = temp -> left;
                root_temp = Tree_insert(temp->right,temp->left);           
            }
        }
        if (root->left == NULL && root -> right == NULL)
        {
            root_temp = NULL;
        }

    }
    else 
    {
        if (temp->right !=NULL)
        {
            x = tree_minimum(temp->right);
            if (x != temp->right)
                x->parent->left = NULL;
            
        }
        else
        {
            if(temp->left!=NULL)
                x = temp->left;
            else 
            {
                if (temp->value < temp->parent->value)
                    temp->parent ->left = NULL;
                else temp->parent->right = NULL;
            }
        }

        
        if(x!=NULL)
        {
            
            y = x->parent;
            x->parent = temp->parent;
            
            if(temp->value > temp->parent->value)
            {
                temp->parent->right = x;
            }
            else 
            {
                temp->parent->left = x;
            }

            if(temp->left != NULL && temp->right!=NULL)
            {   
                if (x->right !=NULL && x== temp->right) // Important
                {  
                    // x->right = temp->right;
                    x->left = temp->left;
                }
                // else if (x->right ==NULL && x== temp->right)
                // {
                //     x->left = temp->left;
                // }
                else if (x->right ==NULL && x->left == NULL && x!= temp->right)
                {   
                    x->right = temp->right;
                    x->left = temp->left;
                }
                else if (x->right ==NULL && x->left == NULL && x== temp->right)
                {   
                    // x->right = NULL;
                    x->left = temp->left;
                }
                else if (x->right !=NULL && x->left == NULL && x!= temp->right)
                 {
                    //  cout <<"here";
                     y ->left = x->right;
                    x->right = temp->right;
                    x->left = temp->left;
                 }
            }
            else if (temp->left == NULL && temp->right!=NULL)
            {
                if (x->right !=NULL && x== temp->right) // Important
                {  
                    // x->right = temp->right;
                    x->left = temp->left;
                }
                else if (x->right ==NULL && x->left == NULL && x!= temp->right)
                {   
                    x->right = temp->right;
                    x->left = temp->left;
                }
                else if (x->right !=NULL && x->left == NULL && x!= temp->right)
                 {
                     y ->left = x->right;
                    x->right = temp->right;
                    x->left = temp->left;
                 }
            }
            // else if (temp->left == NULL && temp->right==NULL)
            // {
            //     if ()
            // }
        }
        else 
        {
            if (temp->value > temp->parent->value)
            {
                temp->parent ->right = NULL;
            }
            else 
                temp->parent->left = NULL;
        }
    }
    return root_temp;

}
void print(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
  
    space += COUNT;
 
 
    print(root->right, space);
 
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->value<<"\n";
    print(root->left, space);
}
int main(){
    Node a;
    Node* root = NULL;
    Node* new_node;

    
    // n is the size of binary tree
    const int n = 10;
     int arr[n];
    // int arr[] ={3,5,8,9,1,10,7,4,0,2,6};
    // int arr[] = {4,5,10,7,8,3,6,0,1,2,9};
    // int arr[] = {0,7,1,4,9,5,10,3,8,2,6}; 
    // int arr[] = {3,5,10,6,4,8,2,9,7,0,1};
    // int arr[] ={7,5,6,3,10,2,8,1,4,0,9};
    int data;
    srand(time(NULL));
    cout << "Original array is = ";
    int value;
    for (int i=0; i<n; i++)
    {
        arr[i] = i;
        // data = rand()%100+1;
        
        // data = i;

    }

    // Randomize
    for (int i = 0; i<n; i++)
    {
        swap(arr[i],arr[rand()%n]);
    }

        for (int i = 0; i<n; i++)
    {

        data = arr[i];
        cout << data << " ";
        
        new_node = get_node(data);
        root = Tree_insert(root,new_node);
    }
    

    cout << endl;
    print(root,0);
    // cout << root  ->value << endl;
    cout << "Inordered array is = ";
    inorder_tree_walk(root);

    cout << "\n";
    cout << "The minimum is = ";
    tree_minimum(root);


    cout << "\n";
    cout << "The maximum is = ";
    tree_maximum(root);

    cout << "\n";
    bool check = false;
    Node* temp = search(root, data);
    // cout << temp -> value; 





    // Delete a node with pass in a root and value
    int randnum = rand()%n;
    root = tree_delete(root,randnum);
    cout << endl;
    cout << "Array after deleting " << randnum;
    cout << endl;
    inorder_tree_walk(root);
    cout << endl;
    print(root,0);
    // cout << root ->left->value;
    


    
    return 0;
}
