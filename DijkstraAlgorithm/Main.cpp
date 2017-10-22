/*
Algoritm Dijkstra
created by worldown

*/

#include <iostream>

#define  X  6
#define CMP > //if you want get maximal volumes change comparison sign on opposite

int* calc(const int arr[X][X], int n);
int getMinOrMax(const int arr[X], bool *flag);

int main() {
//test matrix
	 int matrix[X][X] = {
		{ 0, -1, 3200, -1, -1, 17000},
		{ 2150, 0, -1, -1, -1, -1 },
		{ 3800, -1, 0, -1, 2180, 10000 },
		{ -1, -1, -1, 0, -1, -1 },
		{ -1, -1, 3000, -1, 0, 2345 },
		{ 17000, 4000, -1, -1, -1, 0 }
	};


	int *tmp = calc(matrix,3);
	for (int i = 0; i < X; i++)	{
		std::cout << tmp[i] << " ";
	}
	return 0;
}

int* calc(const int arr[X][X], int n) {
	int *p = new int[X];
	bool *flags = new bool[X];
	int index = -1;
	
	for (int i = 0; i < X; i++) {
		p[i] = arr[n][i];
		flags[i] = true;
	}

	while ((index = getMinOrMax(p, flags)) != -1) {
			
		for (int j = 0; j < X; j++) {
			if (arr[index][j] != -1 && arr[index][j] != 0 && p[j] != 0) {
				if (p[j] CMP (p[index] + arr[index][j]) || p[j] == -1) {
					p[j] = p[index] + arr[index][j];
				}
			}
		}
	}
	return p;
}
//get index for min or max integer
int getMinOrMax(const int arr[X], bool *flag) {

	int buf;
	int it = -1;
	bool first = true;
	for (int i = 0; i < X; i++)	{
		if (arr[i] != -1 && arr[i] != 0 && flag[i]) {
			if (first) {
				buf = arr[i];
				first = false;
				it = i;
			} else {
				if (buf CMP arr[i]) {
					buf = arr[i];
					it = i;
				}
			}
			
		}
	}
	if(it != -1)
		flag[it] = false;
	return it;
}