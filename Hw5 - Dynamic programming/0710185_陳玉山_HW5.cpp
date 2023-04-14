#include <iostream>
using namespace std;


int index_a, index_b,index_a1, index_b1;

int max(int a, int b)
{
    if (a>=b)
        return a;
    else return b;
}
int cut_rod(int p[], int n,int* memoized)
{   int q = INT16_MIN;

 
    if(memoized[n]>0)
    {   
        return memoized[n];
    }

    if (n == 0)
    {
        return 0;
    }
    else 
    {
        
        for (int i=1; i<=n;i++)
        {
            q = max(q,p[i]+cut_rod(p,n-i,memoized));
 
        }
        // cout << "n = " << n;
    }
    memoized[n] = q;
    return q;
}

int bottom_up_cut_rod(int p[],int n,int r[])
{
    
    
    r[0] = 0;
    // cout << n;
    for (int j=1;j<=n;j++)
    {
        int q = INT16_MIN;
        for (int i = 1;i<=j;i++)
        {
            q = max(q,p[i]+r[j-i]);
            if (q<=p[i]+r[j-i])
            {
                index_a = i;
                index_b = j-i;
            }
        }
        // cout << "q = " << q << endl;
        r[j] = q;
    }
    return r[n];
}


// int bottom_up_cut_rod(int p[],int n,int r[])
// {
    
    
//     r[0] = 0;
//     cout << n;
//     for (int j=1;j<=n;j++)
//     {
//         int q = INT16_MAX;
//         for (int i = 1;i<=j;i++)
//         {
//             q = min(q,p[i]+r[j-i]);
//         }
//         cout << "q = " << q << endl;
//         r[j] = q;
//     }
//     return r[n];
// }

int main()
{   ///////////0 1 2 3 4 5  6  7  8  9  10
    int p[] = {0,1,5,8,9,10,17,17,20,24,30};
    const int n = sizeof(p)/sizeof(p[0]);
    // cout << n << endl;
    int n1;
    cout << "cin >> n = "; cin >> n1;
    while (!((0<=n1) &&(n1<=10)))
    {
        cout << "n must inside 0 to 10" << endl;
        cout << "cin >> n = "; cin >> n1;
    }
    int memoized[n+1], r[n+1]; 
    for (int i =0; i<=n; i++)
    {
        memoized[i] = INT32_MIN;
    }




    

    int best_value1 = bottom_up_cut_rod(p,n1,r);
    cout << endl;
    cout << "Bottom-up: " << endl;
    cout << "Total length: " << n1 << endl;
    cout << "Price: " << best_value1 << endl;
    cout << index_b << " " << index_a << endl;
    cout << endl << endl;

    int best_value = cut_rod(p,n1,memoized);
    cout << "Top-down: " << endl;
    cout << "Total length: " << n1 << endl;
    cout << "Price: " << best_value << endl;
    cout << index_b << " " << index_a << endl;
    // cout << best_value <<" " << best_value1; 
   
    return 0;
}