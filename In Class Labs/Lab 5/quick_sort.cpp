#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;
 
void swap(int *a,int *b)
{
    int temp = *a;
    *a=*b;
    *b = temp;
}
int partition (int A[], int p, int r)
{
    int x = A[r];
    int i = p - 1;
 
    for (int j = p; j <= r- 1; j++)
    {
        if (A[j] <= x)
        {
            i++;
            swap (&A[i], &A[j]);
        }
    }
    swap (&A[i + 1], &A[r]);
    return (i + 1);
}
 
void quickSortRecursive(int A[], int p, int r)
{
    if (p < r)
    {
        int q = partition(A, p,r);
        quickSortRecursive(A, p, q - 1);
        quickSortRecursive(A, q + 1, r);
    }
}


/* A[] --> Array to be sorted,
l --> Starting index,
h --> Ending index */
void quickSortIterative(int arr[], int l, int h)
{
	// Create an auxiliary stack
	int stack[h - l + 1];

	// initialize top of stack
	int top = -1;

	// push initial values of l and h to stack
	stack[++top] = l;
	stack[++top] = h;

	// Keep popping from stack while is not empty
	while (top >= 0) {
		// Pop h and l
		h = stack[top--];
		l = stack[top--];

		// Set pivot element at its correct position
		// in sorted array
		int p = partition(arr, l, h);

		// If there are elements on left side of pivot,
		// then push left side to stack
		if (p - 1 > l) {
			stack[++top] = l;
			stack[++top] = p - 1;
		}

		// If there are elements on right side of pivot,
		// then push right side to stack
		if (p + 1 < h) {
			stack[++top] = p + 1;
			stack[++top] = h;
		}
	}
}

// A utility function to print contents of arr
void printArr(int arr[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
		cout << arr[i] << ",";
    cout<<endl;
}


int main()
{
    // int arr[] = { 4, 3, 5, 2, 1, 3, 2, 3 };
	// int n = sizeof(arr) / sizeof(*arr);
	// quickSortIterative(arr, 0, n - 1);
	// printArr(arr, n);

    // cout<<""<<endl;

    // int Arr[] = {4, 3, 5, 2, 0, 1, 3, 2, -10};
    // n = sizeof(Arr) / sizeof(*Arr);
    // quickSortRecursive(Arr,0,n-1);
    // printArr(Arr,n);
	// return 0;

  int time_recursive[10]={};
  int time_iterative[10]={};
  int arr[10] = {100,200,300,400,500,600,700,800,900,1000};
  for (int i=0;i<10;i++)
  {
    int randArray[arr[i]];
    for (int j=0; j<arr[i]; j++)
    {
      randArray[j] = rand()%(100000);
    }

    int Arr[arr[i]]={};
    copy (randArray, randArray+arr[i], Arr);
    auto start1 = high_resolution_clock::now();
    quickSortIterative(Arr,0,arr[i]-1);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    time_iterative[i]=duration1.count();
    // cout << "Time taken by function (iterative merge sort): "<< duration1.count() << " microseconds" << endl;
    // cout << "Sorted array: \n";
    //printArray(arr, length);

    copy (randArray, randArray+arr[i], Arr);
    auto start2 = high_resolution_clock::now();
    quickSortRecursive(Arr,0, arr[i]-1);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    time_recursive[i]=duration2.count();
    // cout << "Time taken by function (iterative merge sort): "<< duration2.count() << " microseconds" << endl;
    // cout << "Sorted array: \n";
    
  }
  printArr(time_iterative, 10);
  cout<<"                 "<<endl;
  printArr(time_recursive, 10);

  return 0;
}