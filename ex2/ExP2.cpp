#include <iostream>
// Robot
// Matricula: A01422699
// Nombre: Ricardo Lopez Canales

using namespace std;
#define MAX 100

//Complejidad: n^2
int robot(int mat[MAX][MAX], int n, int m){
// Aquí va tu codigo
	int finalPoint, grid[n][m];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			grid[i][j] = mat[i][j];
			if (j > 0 && i > 0 )
			{
				if(grid[i - 1][j] < grid[i][j - 1]){
					grid[i][j] += grid[i - 1][j];
				}
				else
					grid[i][j] += grid[i][j - 1];
				//cout << grid [i][j]<<endl;
			}
			else if (i > 0 && j == 0 )
			{
				//cout << "entre"<<endl;
				grid[i][0] += grid[i - 1][0];
			}
			else if (i == 0 && j > 0)
				grid[0][j] += grid[0][j - 1];
			else
				continue;
		}
	}
	finalPoint = grid[n - 1][m - 1];
	return finalPoint;
}

void print(int mat[MAX][MAX], int n, int m){
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
		 cout << mat[i][j]<< " ";
		}
		cout << endl;
	}	
}

int main(){
	int n, m;
	int mat[MAX][MAX];
	cin >> n  >> m;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cin >> mat[i][j];
		}
	}
//	print(mat, n, m);
	cout << robot(mat, n, m)<<endl;
}

/*
5 4
2  2 15  1
5  1 15  1
5  3 10  1
5  2  1  1
8 13  2 15

Resp 2 + 2 + 1 + 3 + 2 + 1 + 1 + 15 = 27 


5 5
1 1 5 3 2
4 1 4 2 6
3 1 1 3 3
5 2 3 1 2
2 1 1 1 1

Resp 10

3 3
1 2 3
4 5 6
7 8 9

resp = 1 + 2 + 3 + 6 + 9 = 21  */