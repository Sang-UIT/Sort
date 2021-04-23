// Sort.cpp : Defines the entry polong long for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include<algorithm>
using namespace std;

void swap(long long &a, long long &b)
{
	long long t = a;
	a = b;
	b = t;
}
//=================================xu ly cho so nguyen===============================/
long long partition(long long arr[], long long low, long long high)
{
	long long pivot = arr[low + rand() % (high + 1 - low)];    // pivot
	long long left = low;
	long long right = high - 1;
	while (true) {
		while (left <= right && arr[left] < pivot) left++;
		while (right >= left && arr[right] > pivot) right--;
		if (left >= right) break;
		swap(arr[left], arr[right]);
		left++;
		right--;
	}
	swap(arr[left], arr[high]);
	return left;
}

void quickSort(long long arr[], long long low, long long high)
{
	if (low < high)
	{
		long long pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
void heapify(long long arr[], long long n, long long i)
{
	long long largest = i; // Initialize largest as root 
	long long l = 2 * i + 1; // left = 2*i + 1 
	long long r = 2 * i + 2; // right = 2*i + 2 

							 // If left child is larger than root 
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far 
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root 
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest);
	}
}

// main function to do heap sort 
void heapSort(long long arr[], long long n)
{
	// Build heap (rearrange array) 
	for (long long i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap 
	for (long long i = n - 1; i>0; i--)
	{
		// Move current root to end 
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap 
		heapify(arr, i, 0);
	}
}

//================================xu ly danh cho so thuc==============================================//
void swap(long double &a, long double &b)
{
	long double t = a;
	a = b;
	b = t;
}
long long partition(long double arr[], long long low, long long high)
{
	long double pivot = arr[low + rand() % (high + 1 - low)];    // pivot
	long long left = low;
	long long right = high - 1;
	while (true) {
		while (left <= right && arr[left] < pivot) left++;
		while (right >= left && arr[right] > pivot) right--;
		if (left >= right) break;
		swap(arr[left], arr[right]);
		left++;
		right--;
	}
	swap(arr[left], arr[high]);
	return left;
}

void quickSort(long double arr[], long long low, long long high)
{
	if (low < high)
	{
		long long pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
void heapify(long double arr[], long long n, long long i)
{
	long long largest = i; // Initialize largest as root 
	long long l = 2 * i + 1; // left = 2*i + 1 
	long long r = 2 * i + 2; // right = 2*i + 2 

					   // If left child is larger than root 
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far 
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root 
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest);
	}
}

// main function to do heap sort 
void heapSort(long double arr[], long long n)
{
	// Build heap (rearrange array) 
	for (long long i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap 
	for (long long i = n - 1; i>0; i--)
	{
		// Move current root to end 
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap 
		heapify(arr, i, 0);
	}
}

void pA(long double arr[],long long n)
{
	for (int i = 0; i<n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}
int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}
void runfloat(string s, int i)
{
	cout << "testcase " << i << endl;
	clock_t start, end;
	double ctu;
	fstream ip;
	ip.open(s, ios::out | ios::in);
	long long n;
	ip >> n;
	cout << "check open: " << ip.is_open() << endl<<"size: "<< n;
	long double *a1 = new long double[n];
	long double *a2 = new long double[n];
	long double *a3 = new long double[n];
	long double *a4 = new long double[n];

	for (long long i = 0; i < n; i++)
	{
		ip >> a1[i];
		a2[i] = a3[i] = a4[i] = a1[i];
	}
	start = clock();
	quickSort(a1,0,n-1);
	end = clock();
	ctu = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout <<endl<< "qsort :"<<ctu << endl;
	start = clock();
	heapSort(a2,n);
	end = clock();
	ctu = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl << "hsort :" << ctu << endl;
	start = clock();
	qsort(a3, n,4,compare);
	end = clock();
	ctu = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl << "qsort C :" << ctu << endl;
	start = clock();
	sort(a4, a4 + n);
	end = clock();
	ctu = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl << "sort C++ :" << ctu << endl;
	ip.close();
	delete(a1);
	delete(a2);
	delete(a3);
	delete(a4);
	cout << "================================="<<endl;
}
void runint(string s, int i)
{
	cout << "testcase " << i << endl;
	clock_t start, end;
	double ctu;
	fstream ip;
	ip.open(s, ios::out | ios::in);
	long long n;
	ip >> n;
	cout << "check open: " << ip.is_open() << endl << "size: " << n;
	long long *a1 = new long long[n];
	long long *a2 = new long long[n];
	long long *a3 = new long long[n];
	long long *a4 = new long long[n];

	for (long long i = 0; i < n; i++)
	{
		ip >> a1[i];
		a2[i] = a3[i] = a4[i] = a1[i];
	}
	start = clock();
	quickSort(a1, 0, n - 1);
	end = clock();
	ctu = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl << "qsort :" << ctu << endl;
	start = clock();
	heapSort(a2, n);
	end = clock();
	ctu = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl << "hsort :" << ctu << endl;
	start = clock();
	qsort(a3, n, 4, compare);
	end = clock();
	ctu = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl << "qsort C :" << ctu << endl;
	start = clock();
	sort(a4, a4 + n);
	end = clock();
	ctu = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl << "sort C++ :" << ctu << endl;
	ip.close();
	delete(a1);
	delete(a2);
	delete(a3);
	delete(a4);
	cout << "=================================" << endl;
}
int main()
{
	for (int n = 1; n <= 10; n++)
	{
		string s1 = to_string(n);
		string s = "D:\\Sort\\testcase\\testcase " + s1 + ".txt";
		if (n <= 5)
			runint(s, n);
		else
			runfloat(s, n);
	}

    return 0;
}

