#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std;

//


//        3 (0)
//    5 (1)        1 (2)
// 4 (3) 9 (4)  3 (5)  7 (6)

void print(int arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        cout  << arr[i] << " ";
    }
    cout << endl;
}
class Heapsort{
public:

void heapify (int arr[], int i, int arr_size)
{
    //cout << "111";
    int left = 2*i+1;
    int right =2*i+2;
    int largest;
    if (arr[left] > arr[i] && 2*i+1 <=arr_size)
        largest = left;
    else largest = i;
    
    if (arr[right] > arr[largest] && 2*i + 2 <= arr_size)
        largest = right;
    
    if (i!=largest)

    {   //printf("i = %d largest = %d \n", i, largest);
        swap (arr[i], arr[largest]);
        //print(arr,arr_size+1);
        heapify(arr,largest, arr_size);
    }
}

void heap_sort( int arr[],  int n)
{
    //cout << "111";
    for (int i = ((n-1)-1)/2; i>=0; i--)
       {    //cout  << i << " ";
            heapify(arr,i,n-1);
       }
    int i = n;
    while (i>0)
    {
        swap(arr[0],arr[i]);
        heapify(arr,0,i-1);
        i--;
    }
    
}
};

class InsertionSort{
public:
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
};
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
 
    //int n = sizeof(arr)/sizeof(arr[0]); // (7)
    int n1; 
    cout << "Input array size n = " ; cin >> n1;
    const int n = n1;
    int arr1[n], arr2[n], arr3[n];
    srand((unsigned) time(0));
    for (auto i=0; i<n; i++)
    {
        arr1[i] = arr2[i] = arr3[i] = rand()%n;
    }
    
    // Print out array before sorting
    // print(arr1,n); // Insertion method
    // print(arr2,n); // Heapsort method
    // print(arr3,n); // Mergesort method
    
    // heapify(arr,0,n-1);
    Heapsort heapsort;
    InsertionSort Insertionsort;
    mergesort mergesort;

    auto start = high_resolution_clock::now();
    Insertionsort.insert_sort(arr2,n-1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout << "Insertion sort running time = " << duration.count() << " microseconds"<< endl;

    start = high_resolution_clock::now();
    //cout << "Unsort array = ";
    //print(arr1,n); cout << endl;
    //cout << "Sorted array = ";
    heapsort.heap_sort(arr1,n-1);
    //print(arr1,n);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop-start);
    cout << "Heapsort running time = " << duration.count() << " microseconds"<< endl;
    

    start = high_resolution_clock::now();
    mergesort.sort(arr3,0,n-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop-start);
    cout << "Merge sort running time = " << duration.count() << " microseconds"<< endl;


    //Print out arrays before sorting
    // print(arr1,n); // Insertion method
    // print(arr2,n); // Heapsort method
    // print(arr3,n); // Mergesort method
    return 0;
}