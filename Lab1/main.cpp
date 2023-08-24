#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#define MAX 50000
using namespace std;
int main() {
  
	// PARTE CREACION
    srand(time(0));

    vector<vector<double>> A(MAX, vector<double>(MAX));
    vector<double> x(MAX), y(MAX);
     // Generate random values for matrix A
    for (int i = 0; i < MAX; i++)
      {
        auto f = []() -> double { return rand() % MAX; };
        generate(A[i].begin(), A[i].end(), f);
      }
/*
   for (int i = 0; i < MAX; i++)
     {
        for (int j = 0; j < MAX; j++)
         cout << A[i][j] << " ";
      cout<< endl;      
     }
    cout<< endl; 
*/
  
    // Generate random values for vector x
    auto f = []() -> double { return rand() % MAX; };
    generate(x.begin(), x.end(), f);
  /*
     for (int i = 0; i < MAX; i++)
     {
         cout << x[i] << " ";      
     }
    cout<< endl<<endl; 
*/


  //Inicializar vector y a 0's
  for (int i = 0; i < MAX; i++)
    y[i] = 0.0;
  
  // First pair of loops 
  unsigned start = clock();
  
  for (int i = 0; i < MAX; i++)
    for (int j = 0; j < MAX; j++)
      y[i] += A[i][j] * x[j];
  
  unsigned end = clock();
  double elapsed = double(end - start)/CLOCKS_PER_SEC;

  cout << "tiempo del primer bucle: " << elapsed<<endl;

  //Reiniciar vector y a 0's
  for (int i = 0; i < MAX; i++)
    y[i] = 0.0;
  
  // Second pair of loops 
  unsigned start2 = clock();
  
  for (int j = 0; j < MAX; j++)
    for (int i = 0; i < MAX; i++)
      y[i] += A[i][j] * x[j];

  unsigned end2 = clock();
  double elapsed2 = double(end2 - start2)/CLOCKS_PER_SEC;

 cout << "tiempo del segundo bucle: " << elapsed2<<endl;


}
