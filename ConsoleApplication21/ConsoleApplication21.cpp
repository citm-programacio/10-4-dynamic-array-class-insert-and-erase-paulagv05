#include <iostream>
#include <string>
using namespace std;

class DynamicArray {
private:
    string* arr;  
    int size;    
    int capacity;  

public:
    
    DynamicArray(int initial_capacity = 10) {
        size = 0;
        capacity = initial_capacity;
        arr = new string[capacity];
    }

   
    ~DynamicArray() {
        delete[] arr;
    }

    bool insert(const string& newElement, int position) 
    {
        if (position < 0 || position > size) 
        {
            return false; 
        }

        if (size == capacity) 
        {
            capacity *= 2;
            string* new_arr = new string[capacity];
            for (int i = 0; i < size; i++) 
            {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
        }

        for (int i = size; i > position; i--) 
        {
            arr[i] = arr[i - 1];
        }

        arr[position] = newElement;
        size++;
        return true;
    }

    bool remove(int position) 
    {
        if (position < 0 || position >= size) 
        {
            cout << "Posicio inexistent" << endl;
            return false; 
        }
        string* newarray = new string[capacity];

        for (int i = position; i < size - 1; i++) 
        {
            arr[i] = arr[i + 1];
        }

        size--;
        return true;
    }

    int getSize() const 
    {
        return size;
    }

    void print() const 
    {
        for (int i = 0; i < size; i++) 
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() 
{
    string start[10];

    DynamicArray arr(10);

    arr.insert("bli", 0);
    arr.print();
    arr.insert("blo", 0);
    arr.print();
    arr.insert("blu", 0);
    arr.print();
  
    arr.remove(2);
    arr.print();

    return 0;
}