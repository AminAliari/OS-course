#include <iostream>
#include <time.h>
#include <windows.h>
#include <tchar.h>
#include <sstream>

using namespace std;

void makeArray(int n);
void print(int n);

LPCTSTR mergeSort(int low, int high);
void merge(int low, int high, int mid);

int* a;

int main(int argc, char *argv[]) {
	srand(time(NULL));

	int n = 0;
	cout << "size of array: ";
	cin >> n;

	makeArray(n);
	//cout << "Orginal Array: ";
	//print(n);

	time_t start, end;
	double elapsed;
	start = time(0);

	mergeSort(0, n - 1);
	//cout << "New Array: ";
	//print(n);

	end = time(0);
	elapsed = end - start;
	cout << "elapsed time: " << elapsed << endl;
	cin.get();
	cin.ignore();
	return 0;
}

LPCTSTR mergeSort(int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;

		mergeSort(low, mid);

		// create process
		STARTUPINFO si;
		PROCESS_INFORMATION pi;

		ZeroMemory(&si, sizeof(si));
		si.cb = sizeof(si);
		ZeroMemory(&pi, sizeof(pi));

		if (!
			CreateProcess
			(
				mergeSort(mid+1,high),
				NULL, NULL, NULL, FALSE,
				CREATE_NEW_CONSOLE,
				NULL, NULL,
				&si,
				&pi
			)
			) {
		}
		WaitForSingleObject(pi.hProcess, INFINITE);


		merge(low, high, mid);
	}
	return 0;
}

void merge(int low, int high, int mid) {

	int i, j, k;
	int *temp = new int[high - low + 1];
	i = low;
	k = 0;
	j = mid + 1;

	while (i <= mid && j <= high) {
		if (a[i] < a[j]) {
			temp[k] = a[i];
			k++;
			i++;
		} else {
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	while (i <= mid) {
		temp[k] = a[i];
		k++;
		i++;
	}

	while (j <= high) {
		temp[k] = a[j];
		k++;
		j++;
	}

	for (i = low; i <= high; i++) {
		a[i] = temp[i - low];
	}
}

void makeArray(int n) {
	a = new int[n];

	for (int i = 0; i<n; i++) {
		a[i] = (rand() % n) + 1;
	}
}


void print(int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
