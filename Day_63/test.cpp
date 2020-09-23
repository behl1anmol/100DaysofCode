
#include <iostream> 
using namespace std; 
#define N 4 
int arr[N][N];
void predictMatrix( int K) 
{ 


	int c = 0; 

		for (int i = 0; i < K; i++) { 
			for (int j = 0; j < K; j++) { 
				c = 0; 

				if (i > 0 && arr[i - 1][j] == 1) 
					c++; 
				if (j > 0 && arr[i][j - 1] == 1) 
					c++; 
				if (i > 0 && j > 0 
					&& arr[i - 1][j - 1] == 1) 
					c++; 
				if (i < N - 1 && arr[i + 1][j] == 1) 
					c++; 
				if (j < N - 1 && arr[i][j + 1] == 1) 
					c++; 
				if (i < N - 1 && j < N - 1 
					&& arr[i + 1][j + 1] == 1) 
					c++; 
				if (i < N - 1 && j > 0 
					&& arr[i + 1][j - 1] == 1) 
					c++; 
				if (i > 0 && j < N - 1 
					&& arr[i - 1][j + 1] == 1) 
					c++; 
				if (arr[i][j] == 1) { 
					if (c >= 2 && c <= 3) 
						arr[i][j] = 1; 
					else
						arr[i][j] = 0; 
				} 
			} 
		} 
} 

int main(){
    int n;
    cin>>n;
    //int arr[N][N];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    predictMatrix(n);

    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    //cout<<arr[0][-4];


}
