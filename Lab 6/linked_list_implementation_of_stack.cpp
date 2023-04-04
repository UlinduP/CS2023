#include <iostream>
#include <chrono>
#define MAX_SIZE 100

using namespace std;
using namespace std::chrono;

#include <iostream>
using namespace std;

int stack_size = 0,number_of_elements = 0;

// define the Node structure
struct Node {
    int data;
    Node* next;
};

class Stack {
    private:
        Node* top;

    public:
        Stack() {
            top = NULL;
        }

        void push(int value) {
            Node* temp = new Node;
            temp->data = value;
            temp->next = top;
            top = temp;
            number_of_elements+=1;
        }

        int pop() {
            if (top == NULL) {
                cout << "Stack Underflow" << endl;
                return 0;
            }
            int value = top->data;
            Node* temp = top;
            top = top->next;
            delete(temp);
            number_of_elements-=1;
            return value;
        }

        int stackTop() {
            if (top == NULL) {
                cout << "Stack is empty" << endl;
                return 0;
            }
            return top->data;
        }

        bool isEmpty() {
            if (number_of_elements == 0){
                return true;
            }
            return false;
        }

        bool isFull(){
            if (stack_size == number_of_elements){
                return true;
            }
            return false;
        }

        void display() {
            Node* temp = top;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

// A utility function to print contents of arr
void printArr(int arr[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
		cout << arr[i] << ",";
    cout<<endl;
};

int main() {
    int time_taken[10] = {};
    for (int i=0; i<10; i++){
    auto start1 = high_resolution_clock::now();
    Stack s;
    stack_size = 100;
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








    // s.push(5);
    // s.push(10);
    // s.push(15);
    // s.push(20);
    // s.display();
    // cout << "Popped " << s.pop() << endl;
    // cout << "Popped " << s.pop() << endl;
    // s.display();
    // cout << "Peeked " << s.stackTop() << endl;
    // cout << "Is stack empty? " << s.isEmpty() << endl;
