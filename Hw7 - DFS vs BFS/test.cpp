#include <iostream>

using namespace std;

int main(){
    int **arr = new int*[4];
    for (int i = 0; i< 4; i++)
    {
        arr[i] = new int(5);
    }
    arr[0][1] = 2;
    cout << arr[0][1];
}