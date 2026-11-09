
#include <iostream>
using namespace std;

class PriorityQueue{
    int *arr;
    int capacity;
    int size;

public:
    PriorityQueue(int cap){
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    // Insert a new element according to its priority.
    bool Insert(int value){
        if(size == capacity){
            cout << "Priority Queue Overflow!" << endl;
            return false;
        }

        int i = size;
        size++;

        // Move the new element upwards.
        while(i > 0 && value > arr[(i-1)/2]){
            arr[i] = arr[(i-1)/2];
            i = (i-1)/2;
        }

        arr[i] = value;
        return true;
    }

    // Remove the highest-priority element.
    bool Delete(int &value){
        if(size == 0){
            cout << "Priority Queue Underflow!" << endl;
            return false;
        }

        value = arr[0];
        arr[0] = arr[size-1];
        size--;

        int i = 0;
        int j = 2*i + 1;

        // Restore the Max Heap property.
        while(j < size){

            if(j+1 < size && arr[j+1] > arr[j]){
                j = j+1;
            }

            if(arr[i] >= arr[j]){
                break;
            }

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i = j;
            j = 2*i + 1;
        }

        return true;
    }

    // Return the highest-priority element without deleting it.
    bool Peek(int &value){
        if(size == 0){
            return false;
        }

        value = arr[0];
        return true;
    }

    void Display(){
        cout << "[";
        for(int i=0; i<size; i++){
            cout << arr[i];
            if(i < size-1){
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    ~PriorityQueue(){
        delete[] arr;
    }
};

int main(){
    PriorityQueue pq(10);

    pq.Insert(30);
    pq.Insert(10);
    pq.Insert(50);
    pq.Insert(20);
    pq.Insert(40);

    cout << "Priority Queue: ";
    pq.Display();

    int value;

    if(pq.Peek(value)){
        cout << "Highest Priority: " << value << endl;
    }

    if(pq.Delete(value)){
        cout << "Removed Element: " << value << endl;
    }

    cout << "After Deletion: ";
    pq.Display();

    cout << "\nRemoval Order: ";

    while(pq.Delete(value)){
        cout << value << " ";
    }

    cout << endl;

    return 0;
}
