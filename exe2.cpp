/*Johann Batson
400000715
Algorithms Lab 3.2*/
#include <iostream>
#include <random>
using namespace std;
void merge(int *, int, int, int); //declares the function merge
void mergeSort(int* arr, int low, int high)
{
	int mid;
	if (low < high)
	{
		//divide the array at mid and sort indepensdently using merge sort
		mid = (low + high) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		//merge or conquer sorted arrays
		merge(arr, low, high, mid);
	}
}
//Merge
void merge(int *arr, int low, int high, int mid)
{
	int i, j, k, c[50];
	i = low;
	k = low;
	j = mid + 1;
	while (i <= mid && j <= high) {
		if (arr[i] < arr[j])
		{
			c[k] = arr[i];
			k++;
		    i++;
		}
		else
		{
			c[k] = arr[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		c[k] = arr[i];
		k++;
		i++;
	}
	while (j <= high) 
	{
		c[k] = arr[j];
		k++;
		j++;
	}
	for (i = low; i < k; i++)
	{
		arr[i] = c[i];
	}
}

//reads the input array and calls the mergeSort function

int main()
{
	int randomNumber[16] = { 0 };
	int randomNsize = sizeof(randomNumber) / sizeof(randomNumber[0]);
	random_device rd;
     mt19937 gen(rd());  //randomly generates numbers 1 through 150
	uniform_int_distribution<> dis(1, 150);
	for (int n = 0; n < 16; n++) {
		cout << dis(gen) << ' ';
	}
	cout << '\n';

	int myarray[30], num;
	cout << "Please enter the number of elements to be sorted:";
	cin >> num;
	cout << "Enter the " << num << " elements above to be sorted:";
	for (int i = 0; i < num; i++) 
	{
		cin >> myarray[i];
	}

	cout << "Before the sorted array list, aka unsorted array \n" << endl;
	for (int i = 0; i < num; i++)
	{
		cout  << myarray[i] << "\t";
	}

	cout << endl;

	mergeSort(myarray, 0, num - 1);
	cout << "The sorted array \n" << endl;
	for (int i = 0; i < num; i++)
	{
		cout << myarray[i] << "\t";
	}
	system("pause");
}