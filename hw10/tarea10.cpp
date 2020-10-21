//TAREA10
//RICARDO LOPEZ CANALES
//A01422699

#include<iostream>
#include<vector>
#define medida 20

using namespace std;

int grid[medida][medida];

void setTriangle(){
	for(int x = 0; x < medida; x++){
		for(int y = 0 ; y < x + 1; y++){
			cin >> grid[x][y];
		}
	}
}

void addition(int iN) {
	for(int i = iN - 1; i > 0; i--){ 
		for (int j = 0; j < i; j++) {
			if (grid[i][j] > grid[i][j + 1])
				grid[i - 1][j] = grid[i - 1][j] + grid[i][j];
			else 
				grid[i - 1][j] = grid[i - 1][j] + grid[i][j + 1];
		}
	}	
}

int main(){
	int iRepeticiones, iN;
	vector<int> results;
	cin >> iRepeticiones;

	while (iRepeticiones) {
		cin >> iN;
		for (int x = 0; x < iN; x++) 
			for (int y = 0; y < x + 1; y++) {
				cin >> grid[x][y];
			}
		addition(iN);
		iRepeticiones--;
		results.push_back(grid[0][0]);
	}

	for (int i = 0; i < results.size(); i++)
	{
		cout<<results[i]<<endl;
	}

}