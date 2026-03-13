#include <iostream>
using namespace std;

void swapValues(int* p1, int* p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int findMax(int* arr, int size) {
    int max = *arr;

    for (int i = 1; i < size; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
}

void reverseArray(int* arr, int size) {
    int* start = arr;
    int* end = arr + size - 1;

    while (start < end) {
        swapValues(start, end);
        start++;
        end--;
    }
}

int* createArray(int size) {
    int* arr = new int[size];
    return arr;
}

void deleteArray(int* arr) {
    delete[] arr;
}

int main() {
 cout<<"Creating dynamic array...\n";
    int size;
    cout<<"Enter array size:";
    cin >> size;

    int* arr = createArray(size);
    cout<<"Enter values:";
    for (int i = 0; i < size; i++) {
        cin >> *(arr + i);
    }
    cout<<"\nArray elements:\n";
    printArray(arr, size);

    cout<<"\nMaximum element:"<<findMax(arr, size) << endl;

     cout<<"----------------------------------";
    cout<<"\nSwapping two numbers\n";

    int a =5;
    int b =6;

    cout<<"Before swap\n";
    cout<<"a ="<<a<<endl;
    cout<<"b ="<<b<<endl;

    swapValues(&a, &b);

    cout<<"\nAfter swap\n";
    cout<<"a ="<<a<<endl;
    cout<<"b ="<<b<<endl;

    cout<<"----------------------------------";
    cout<<"\nReversing array...\n";
    reverseArray(arr, size);
    cout<<"\nArray after reverseArray:\n";
    printArray(arr, size);

    cout<<"----------------------------------";
    cout<<"\nDeleting array...\n";
    deleteArray(arr);

    cout<<"Memory released successfully.\n";

    return 0;

}
