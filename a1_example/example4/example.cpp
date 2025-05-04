#include <iostream>
#include <cmath>

using namespace std;

// Immutable struct to hold the results
struct oktaeder
{
  const float Volumen;
  const float Oberfläche;
  const float Inkreisradius;
  const float Umkreisradius;
};

oktaeder calculate(const int a)
{
  return {
    static_cast<float>(pow(a, 3) * sqrt(2) / 3),   // Volumen
    static_cast<float>(2 * pow(a, 2) * sqrt(3)),  // Oberfläche
    static_cast<float>(a * sqrt(6) / 6),          // Inkreisradius
    static_cast<float>(a * sqrt(2) / 2)           // Umkreisradius
  };
}

int main()
{
  const int a = 2;
  const oktaeder o = calculate(a);
  cout << "Volumen:" << o.Volumen 
       << " Oberfläche:" << o.Oberfläche 
       << " Inkreisradius:" << o.Inkreisradius 
       << " Umkreisradius:" << o.Umkreisradius 
       << endl;
  return 0;
}