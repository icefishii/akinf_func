#include <iostream>
#include <cmath>

using namespace std;


// immutable struct mit const
struct quader
{
  const int Volumen;  
  const int Oberfläche;
  const float Diagonale;
};

// calculate funktion returned ein struct, es gibt keinen quader der verändert wird
quader calculate(const int a, const int b, const int c)
{
  return {
    a * b * c, // Volumen
    2 * (a * b + a * c + b * c), // Oberfläche
    static_cast<float>(sqrt(a * a + b * b + c * c)) // Diagonale
  };
}

int main()
{
  const int a = 2;
  const int b = 3;
  const int c = 4;
  const quader q = calculate(a, b, c);
  cout << "Volumen:" << q.Volumen 
        << " Oberfläche:" << q.Oberfläche 
        << " Diagonale:" << q.Diagonale 
        << endl;
  return 0;
}