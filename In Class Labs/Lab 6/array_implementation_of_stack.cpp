#include <iostream>
#include <chrono>
#define MAX_SIZE 100

using namespace std;
using namespace std::chrono;

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool push(int x) {
        if (top >= MAX_SIZE - 1) {
            cout << "Error: stack overflow\n";
            return false;
        }
        arr[++top] = x;
        return true;
    }

    bool pop() {
        if (top < 0) {
            cout << "Error: stack underflow\n";
            return false;
        }
        top--;
        return true;
    }

    int stackTop() {
        if (top < 0) {
            cout << "Error: stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top < 0;
    }

    bool isFull(){
        if (top>=MAX_SIZE-1){
            return true;
        }
        return false;
    }

    void display() {
        if(top>=0) {
            cout<<"Stack elements are: ";
            for(int i=0; i<=top; i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        } else
            cout<<"Stack is empty";
}
};

// A utility function to print contents of arr
void printArr(int arr[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
		cout << arr[i] << ",";
    cout<<endl;
}

int main() {
    int time_taken[10] = {};
    for (int i=0; i<10; i++){
    auto start1 = high_resolution_clock::now();
    Stack s;
    s.push(rand() % 201 - 100);
    s.push(rand() % 201 - 100);
    s.push(rand() % 201 - 100);
    s.push(rand() % 201 - 100);
    s.push(rand() % 201 - 100);
    s.push(rand() % 201 - 100);
    s.push(rand() % 201 - 100);
    s.push(rand() % 201 - 100);
    s.push(rand() % 201 - 100);
    s.push(rand() % 201 - 100);
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display();
    s.push(rand() % 201 - 100);
    s.push(rand() % 201 - 100);
    s.push(rand() % 201 - 100);
    s.push(rand() % 201 - 100);
    s.display();
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    time_taken[i] = duration1.count();
    }

    printArr(time_taken, 10);
    return 0;
}








    // cout<<s.isEmpty()<<endl;
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.display();   // Output: 30
    // s.pop();
    // s.display();   // Output: 20
    // s.pop();
    // cout<<s.isEmpty()<<endl;
    // s.pop();
    // cout << s.isFull() << endl;   // Output: 1 (true)