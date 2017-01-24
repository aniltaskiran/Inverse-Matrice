// inverse of matrice
#include <iostream>
#include <stdlib.h>
//Anıl Taşkıran
using namespace std;

int rows;
void ekrana(float ** ekran);
void identity_maker(float ** identity);
void delete_point(float ** deleting);
void elimination(float ** array,float ** identity,int i, int j);
void array_input(float ** array);
void elimination_order(float ** array,float ** identity);

int main ()
{
  float ** array;
  string in;
  do
  {
    cout << "---------------" <<
  "Welcome to The Finder the inverse"<<
   "---------------";
   cout << endl << "It can work with with all matrice."<<endl;
   cout << " If you want to solve 6x6" <<
    " matrice please add only 6"<<endl
    <<"And just use square matrice."<<endl;
     cout << "please enter only row number."<<endl
     <<" its just work with NxN matrice:  ";

       cin >> rows;

    array= new float*[rows];
      for (int j=0; j<rows; j++){
         array[j] = new float[rows];
      }

  float ** identity;
    identity= new float*[rows];
      for (int j=0; j<rows; j++){
         identity[j] = new float[rows];
      }
    
    identity_maker(identity);
    array_input(array);

    ekrana(array);

    elimination_order(array,identity);
    cout << "This is 'A' matrice we reduced that"<< endl;
    ekrana(array);

    cout << "This is inverse of 'A' " <<endl;
    ekrana(identity);

   delete_point(identity);
   delete_point(array);
 cout << "for quit please enter 'exit'"<<endl;
}while ((cin >> in) && (in != "exit"));
  
  return 0;
}

void array_input(float ** array)
{
  for (int i = 0; i <rows; i++)
  { for (int j = 0; j<rows ; j++)
    {
      cout << "please enter 'A' matrice's element a" << i+1 << j+1 <<": ";
      cin >> array[i][j];
    }
  }
}


void elimination_order(float ** array,float ** identity)
{
  for (int t = 0; t < rows; t++)
  { 
    elimination(array,identity,t,t);
      for (int y = 0; y < rows; y++)
      {
        if (t!=y)
        {
          elimination(array,identity,y,t);
        }
      }
  }
}
  
void elimination(float ** array,float ** identity,int i, int j)
{
  float q,d;
  if(i==j)
  {
    d = array[i][i];
    for (int k = 0; k <rows; k++)
    {
      array[i][k] = array[i][k] / d;

      identity[i][k] = identity[i][k] / d;
    }
  }
  else
  {
    q = -array[i][j] / array[j][j];
    for (int k = 0; k <rows; k++)
    {
      array[i][k] = q*array[j][k] + array[i][k];

      identity[i][k] = q*identity[j][k] + identity[i][k];

    }
  }
}



void ekrana(float ** ekran)
{

  cout << "Matrix:  "<<endl;

  for (int n=0; n<rows; n++)
  {   for (int m=0; m< rows; m++)
      {
        cout<< ekran[n][m]<<" ";
      }
    cout << endl;
  }
}
void identity_maker(float ** identity)
{
  for (int n = 0; n <rows; n++)
  {
    for (int j= 0; j <rows; j++)
    {
      if(n==j)
      {
        identity[n][j]=1;
      }
      else
      {
        identity[n][j]=0;
      }
      
    }
    
  }

}
void delete_point(float ** deleting)
{
   for (int n=0; n<rows; n++)
   {
     delete [] deleting[n];
   }
      
    delete[] deleting;
}