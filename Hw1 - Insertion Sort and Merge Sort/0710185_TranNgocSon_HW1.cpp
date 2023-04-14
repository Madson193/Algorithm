/*NOTE
The code is compiled by C++11 and run in Visual studio code or Code::Blocks (with the C+11
option in the compiler setting).

The file name is written in English due to the compiling error when named in Mandarin.

If you have any problems when running the code, please let me know through the email below!
Thank you so much for your time to read this!

Student: Tran Ngoc Son （陳玉山）
ID: 0710185
Email: ngocsontran19398@gmail.com
*/

#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

void print(int arr[],int n) // To print the entire array
{

    for (int i=0; i<n; i++)
        cout << arr[i] << " ";

    cout << "\n";
}

void insert_sort(int arr[], int n)
{
    for (int i=1;i<=n;i++)
    {
        int current = arr[i];
        int j = i-1;
        // cout << "j= " << j << "\n";
        int current_index = i;
        while (j>=0)
        {
            if (arr[j]>current)
                {
                    swap(arr[j],arr[current_index]);
                    current_index = j;
                }
            j--;
        }
    }
}

class mergesort
{
    public:
    void merge (int arr[],int left, int middle, int right)
    {

        int left_size =  middle-left+1;
        int right_size =  right - (middle+1) +1;

        int *temp = new int[right-left+1];
        int *left_temp = new int[left_size];
        int *right_temp = new int[right_size];

        // cout << "left_temp= ";
        for (int i=left; i<=middle;i++)
            {
                left_temp[i-left] = arr[i];
                // cout << left_temp[i] << " ";
            }
        // cout << endl;
        // cout << "right_temp= ";
        for (int i=middle+1; i <=right; i++)
        {
            right_temp[i-middle-1] = arr[i]; //right_temp[i-middle-1] start at 0
            // cout  << right_temp[i] << " ";
        }
        int i=0, j=0;

        int arr_index = left;
        while (i<left_size && j <right_size)
        {

            if (left_temp[i]<right_temp[j])
             {
                arr[arr_index++] = left_temp[i];
                i++;
             }
            else if (left_temp[i]>right_temp[j])
            {
                arr[arr_index++] = right_temp[j];
                j++;
            }
            else if (left_temp[i]==right_temp[j])
            {
                arr[arr_index++] = left_temp[i];
                i++;
            }
            //i++; j++;
        }
        while (i<left_size)
            arr[arr_index++] = left_temp[i++];
        while (j<right_size)
        {
            arr[arr_index++] =right_temp[j++];
        }

    }
    ///Phai chia sao cho ben trai nhieu hon ben phai

    void sort(int arr[],int left, int right)
    {
        if (left>=right) return;
        int middle = left + (right-left)/2;
        sort(arr , left, middle);
        sort(arr, middle+1, right);
        merge(arr,left, middle, right);
    }
};
int main()
{
    int n;
    cout << "Input array size= ";
    cin >> n; //Input array size

    // n = sizeof(arr)/sizeof(arr[0]);
    int arr1[n],arr2[n];

    srand((unsigned) time(0)); //For letting the element in rand() function to be different each time
    for (int i=0; i<n;i++) //To create an random array size n
    {
        arr1[i] = arr2[i] = rand()%n;
    }
    //-----------------------------
    //excuting insertiong sort algorithm
    auto start = high_resolution_clock::now();
    insert_sort(arr1,n-1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout << endl << "The executive time of Insertion sort = " << duration.count() << " microseconds \n";
    //--------------------------
    cout << endl;
    //------------------------
    //Executing Mergesort algorithm
    mergesort sort;
    // int middle = 0 + (n-1)/2;
    start = high_resolution_clock::now();// Start counting time
    sort.sort(arr2,0,n-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop-start);
    cout << "The executive time of Merge sort = " << duration.count() << " microseconds" << endl;

    //----------------------------------------------------------------------------------
    // you can run the below part for checking the sorted array of the two sorting method
    //----------------------------------------------------------------------------------

    /*
    cout << endl;
    cout << "Array1[] = " ;
    print(arr1,n); // Print out all the element in an array
    cout << endl;
    cout << "Array2[] = ";
    print(arr2,n); // Print out all the element in an array
    */

    return 0;
}


