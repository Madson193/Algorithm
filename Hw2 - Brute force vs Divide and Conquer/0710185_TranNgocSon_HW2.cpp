#include <iostream>
#include <ctime>
#include <chrono>

using namespace std::chrono;
using namespace std;

class Brute_force
{
    public: 
    int brute_force(int arr[], int n)
    {
        int max=INT_MIN;
        int sum;
        for (int i=0; i<=n;i++)
        {
            sum =0;
            for (int j=i; j<=n;j++)
            {
                sum = sum+arr[j];  
                if (sum>max)
                max = sum; 
            }
        }
        return max;
    }
};
class Divide_method
{
    public:
    int find_max_mid(int arr[],int low, int mid, int high)
    {
        int max_left = INT_MIN;
        int sum=0;
        int left_index, right_index;
        for (int i=mid; i >=low; i--)
        {
            sum = sum + arr[i];
            if (sum>max_left)
            {  
                max_left = sum;
            }
        }
        int max_right = INT_MIN;
        sum = 0;
        for (int i=mid+1; i<=high;i++)
        {
            sum = sum + arr[i];
            if (sum>max_right)
            {
                max_right = sum;
            }
        }
        int max_overall = max(max(max_left,max_right),max_left+max_right);
        return max_overall;
    }
    int max_sub(int arr[],int low, int high)
    {
        if (low==high) return arr[low];
        int mid = low + (high-low)/2;
        int max_left = max_sub(arr, low,mid);
        int max_right = max_sub(arr, mid+1, high);
        int max_middle = find_max_mid(arr,low,mid,high);
        int max_overall = max(max(max_left,max_right),max_middle);
        return max_overall;
    }
};
int main()
{   
    int n;
    cout << "Input array size = "; cin >> n;
    int arr1[n], arr2[n];
    srand((unsigned) time(0));
    for (int i=0; i<n; i++)
    {
        arr1[i] = arr2[i] = rand()%n;
    }

    Divide_method divide;
    Brute_force brute;
    //int arr[] = {-3,5,-3,7,10};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int mid = 0 + (n1-1)/2;
    //int max = find_max_mid(arr,0,mid,n1-1);
    auto start = high_resolution_clock::now();
    int max1 = divide.max_sub(arr1,0,n1-1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout << "Max Sub-array and running time (Divide and Conquer) = " << max1 << " / " << duration.count() << " microseconds"<< endl;
    
    start = high_resolution_clock::now();
    int max2 = brute.brute_force(arr2,n1-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop-start);
    cout << "Max Sub-array and running time (Brute_force method) = " << max2 << " / " << duration.count() << " microseconds"<< endl; 
    return 0;
}