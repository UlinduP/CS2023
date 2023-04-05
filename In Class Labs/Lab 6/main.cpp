#include <iostream>
#include <chrono>
#define MAX_SIZE 100

using namespace std;
using namespace std::chrono;

int stack_size = 0,number_of_elements = 0;

// define the Node structure
struct Node {
    int data;
    Node* next;
};

class Stack_LinkedList {
    private:
        Node* top;

    public:
        Stack_LinkedList() {
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


class Stack_Array {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack_Array() {
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
};


int main() {
    int time_taken_array[10] = {}, time_taken_linked_list[10] = {};
    int random[14]={};
    for (int i=0; i<10; i++){
    
    for (int j=0; j<14; j++){
        random[j] = rand() % 201 - 100;
    }
    auto start1 = high_resolution_clock::now();
    Stack_LinkedList s;
    stack_size = 100;
    s.push(random[0]);
    s.push(random[1]);
    s.push(random[2]);
    s.push(random[3]);
    s.push(random[4]);
    s.push(random[5]);
    s.push(random[6]);
    s.push(random[7]);
    s.push(random[8]);
    s.push(random[9]);
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display();
    s.push(random[10]);
    s.push(random[11]);
    s.push(random[12]);
    s.push(random[13]);
    s.display();
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    time_taken_linked_list[i] = duration1.count();

    auto start2 = high_resolution_clock::now();
    Stack_Array st;
    stack_size = 100;
    st.push(random[0]);
    st.push(random[1]);
    st.push(random[2]);
    st.push(random[3]);
    st.push(random[4]);
    st.push(random[5]);
    st.push(random[6]);
    st.push(random[7]);
    st.push(random[8]);
    st.push(random[9]);
    st.display();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.display();
    st.push(random[10]);
    st.push(random[11]);
    st.push(random[12]);
    st.push(random[13]);
    st.display();
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    time_taken_array[i] = duration2.count();
    }

    printArr(time_taken_linked_list, 10);
    cout<<"           "<<endl;
    printArr(time_taken_array, 10); 

    return 0;
}