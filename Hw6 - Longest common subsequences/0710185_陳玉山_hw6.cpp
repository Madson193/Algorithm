#include <iostream>
#include <vector>
#include <time.h> 
#include <chrono>

using namespace std::chrono;
using namespace std; 
// int x[] = {1, 4, 6, 2, 8,1,5,6};
// int y[] = {1,6,9,8,5,1,6,3,2};
// int x[]  ={6,6,6,0,8,9,4,5,7,9,4,5,3};
// int y[] ={1,6,8,0,4,8,7,5,4,8,7,7,4,1,4};
// int x[] = {2,5,7,9,3,1,2};
// int y[] = {3,5,3,2,8};
 
const int n = 10;
const int m = 10;
int x[n];
int y[m];
// const int n = sizeof(x)/sizeof(x[0])-1;
// const int m = sizeof(y)/sizeof(y[0])-1;
int b[n+1][m+1];
int c[n+1][m+1];
const int upleft= -100;
const int up = -101;
const int _left = -102;
int length1 = 0;



class option1{
    public:
 

    bool flag = false;


    void initial(){
        // int x[]  ={6,6,6,0,8,9,4,5,7,9,4,5,3};
        // int y[] ={1,6,8,0,4,8,7,5,4,8,7,7,4,1,4};
        cout << "X = ";
        for (int i=0; i<=n; i++)
        {
            cout << x[i] << " ";
            c[i][0] = 0;
        }

        cout << endl;
        cout << "Y = ";
        for (int j=0;j<=m; j++)
        {
            cout << y[j] << " ";
            c[0][j] = 0;
        }
        
        cout << endl;
        for (int i =1; i<=n; i++)
        {
            for (int j=1; j<=m;j++)
            {
                if(x[i]==y[j])
                {
                    c[i][j] = c[i-1][j-1]+1;
                    b[i][j] = upleft;
                }
                else if(c[i-1][j]>=c[i][j-1])
                {
                    c[i][j] = c[i-1][j];
                    b[i][j] = up;
                }
                else 
                {
                    c[i][j] = c[i][j-1];
                    b[i][j] = _left;
                }
            }
        }
        cout << "Z= ";
        if (x[0]==y[0])
            {
                cout<< x[0] << " ";
                length1++;
            }   
        print_out(n,m);
        cout << endl << "Length = " << length1;
    }

    void print_out(int i, int j){
        if (i==0 || j==0)
            return;
        if (b[i][j]==upleft)
        {
            print_out(i-1,j-1);
            // if ((i==1 && flag == false) || (j==1 && flag ==false))
            //     {
            //         cout << x[0] << " ";
            //         flag = true;
            //         cout << x[i] << " ";
            //         length1 = length1 + 2;
            //     }

            // else{
                cout << x[i] << " ";
                length1 ++;
            // }
        }

        else if (b[i][j]==up)
            print_out(i-1,j);
        else if (b[i][j] == _left)
            print_out(i,j-1);

        }
};
int main(){
 
    srand( time(NULL) );
    for (int i =0; i<n; i++)
    {
        x[i] = rand()%10;  
    }
    for (int i =0; i<m; i++)
    {
        y[i] = rand()%10;  
    }
    option1 lcs1;
    auto start = high_resolution_clock::now();
    lcs1.initial();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout << endl<< "Running time (n = " << n+1 << ") (m = "<< m+1 <<") = " << duration.count() << " microseconds"<< endl;
    
    return 0;
}
