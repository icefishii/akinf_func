#include <iostream>
#include <cmath>

using namespace std;

struct wuerfel
{
  const int Volumen;
  const int Oberfläche;
  const float Diagonale;
  const float Inkreisradius;
  const float Umkreisradius;
};

wuerfel calculate(const int a)
{
  return {
    static_cast<int>(pow(a, 3)),          // Volumen
    static_cast<int>(6 * pow(a, 2)),     // Oberfläche
    static_cast<float>(a * sqrt(3)),     // Diagonale
    static_cast<float>(a / 2.0 * sqrt(3)), // Inkreisradius
    static_cast<float>(a / 2.0)          // Umkreisradius
  };
}

int main()
{
  const int a = 2;
  const wuerfel w = calculate(a);
  cout << "Volumen:" << w.Volumen 
       << " Oberfläche:" << w.Oberfläche 
       << " Diagonale:" << w.Diagonale 
       << " Inkreisradius:" << w.Inkreisradius 
       << " Umkreisradius:" << w.Umkreisradius 
       << endl;
  return 0;
}