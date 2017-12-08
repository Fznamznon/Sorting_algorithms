#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cmath>

using namespace std;

#define TYPE double

unsigned int bubble_sort(vector<TYPE> &A) 
{
	unsigned int start_time = clock();
	for (size_t i = 0; i < A.size() - 1; ++i)
	{
		for (size_t j = 0; j < A.size() - 1; ++j)
		{
			if (A[j] > A[j + 1])
				swap(A[j], A[j + 1]);
		}
	}
	unsigned int end_time = clock();
	unsigned int time = end_time - start_time;
	return time;
}

void insertion_sort(vector<TYPE> &A) 
{
	TYPE key;
	for (int j = 1; j < A.size(); ++j) 
	{
		key = A[j];

		int i = j - 1;
		while (i >= 0 && A[i] > key) 
		{
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
}

unsigned int bucket_sort(vector<TYPE> &A)
{
	size_t n = A.size();
	vector<vector<TYPE>> B(n + 1);
	unsigned int start_time = clock();
	for (size_t i = 0; i < n; ++i)
	{
		int index =  floor(n * A[i]);
		B[index].push_back(A[i]);
	}

	for (size_t i = 0; i < n; ++i)
	{
		insertion_sort(B[i]);
		//sort(B[i].begin(), B[i].end());
	}
	
	
	size_t j = 0;
	for (size_t i = 0; i <= n; ++i) 
	{
		for (size_t q = 0; q < B[i].size(); ++q) 
		{
			A[j] = B[i][q];
			j++;
		}
	}
	
	unsigned int end_time = clock();
	unsigned int time = end_time - start_time;
	return time;
}



void qs(vector <TYPE> &A, int p, int r)
{
	if (p < r)
	{
		//int t = rand() % r + p;
		
		//swap(A[r], A[t]);
		
		//cout << t << " ";
		

		TYPE x = A[r];
		int i = p - 1;
		for (size_t j = p; j < r; ++j)
		{
			if (A[j] <= x)
			{
				i++;
				swap(A[i], A[j]);
			}
		}
		swap(A[i + 1], A[r]);

		int q = i + 1;

		qs(A, p, q - 1);
		qs(A, q + 1, r);
	}
}

unsigned int quick_sort(vector <TYPE> &A)
{
	unsigned int start_time = clock();
	qs(A, 0, A.size() - 1);
	unsigned int end_time = clock();
	unsigned int time = end_time - start_time;
	return time;
}

int main()
{
	srand(time(0));
	int n;
	cout << "Enter n: ";
	cin >> n;

	vector<TYPE> A(n);
	for (int i = 0; i < n; ++i)
	{
		A[i] = (TYPE)(rand()) / RAND_MAX;
		cout << A[i] << " ";
	}
	vector<TYPE> B = { 0.568377, 0.223884, 0.41908, 0.136845, 0.207923, 0.418714, 0.722709, 0.876156, 0.0961943, 0.265572 }; //B(A); // = { 0.547838, 0.65276, 0.113804, 0.85992, 0.364116, 0.732871, 0.155889, 0.278787, 0.294107, 0.916166 };
	cout << "Data generated" << endl;
	unsigned int qsort_time = quick_sort(A);
	//unsigned int bucket_time = bucket_sort(B);


	for (int i = 0; i < n; ++i)
	{
		cout << A[i] << " ";
	}
	cout << "Quick sort time in seconds = " << (float)qsort_time / CLOCKS_PER_SEC << endl;
	//cout << "Bucket sort time in seconds = " << (float)bucket_time / CLOCKS_PER_SEC << endl;


	return 0;
}
