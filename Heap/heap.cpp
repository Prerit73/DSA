#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        size = 0;
    }

    void insert(int data)
    {
        int index = size;
        arr[index] = data; // insert data at last and then maintain heap
        size++;

        while (index)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent; // check for parent.
            }
            else
            {
                return;
            }
        }
    }

    void deleteData()
    {
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }

        // step1: put the last element to first
        arr[0] = arr[size - 1];
        // step2: remove the last element
        size--;

        // step3: take root node to its right position
        int i = 0;

        while (i < size)
        {
            int leftNode = 2 * i + 1;
            int rightNode = 2 * i + 2;

            if (leftNode < size && arr[i] < arr[leftNode])
            {
                swap(arr[i], arr[leftNode]);
                i = leftNode;
            }
            else if (rightNode < size && arr[i] < rightNode)
            {
                swap(arr[i], arr[rightNode]);
                i = rightNode;
            }
            else
            {
                return;
            }
        }

        return;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n, int i) // max heap
{
    int leftNode = 2 * i + 1;
    int rightNode = 2 * i + 2;

    int largest = i; // for min heap opposite condition

    if (leftNode < n && arr[largest] < arr[leftNode])
    {
        largest = leftNode;
    }
    if (rightNode < n && arr[largest] < arr[rightNode])
    {
        largest = rightNode;
    }

    if (largest != i) // if child node contain large number
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    while (n)
    {
        swap(arr[0], arr[n - 1]); // swap Last element with node
        n--;
        heapify(arr, n, 0);
    }
}

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    // h.print();

    h.deleteData();
    // h.print();

    int arr[5] = {54, 53, 55, 52, 50};
    int n = 5;

    /*
        // heapify
        for (int i = ((n / 2) - 1); i >= 0; i--)
        {
            heapify(arr, 5, i);
        }
        cout << "print heapify " << endl;

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;*/

    
    // heapSort
    heapSort(arr,n);
    cout << "print sorted heap " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    //max Heap
    priority_queue<int> pq;
    pq.push(50);
    pq.top();


    //min Heap
    priority_queue<int,vector<int>,greater<int>> minHeap;

    return 0;
}