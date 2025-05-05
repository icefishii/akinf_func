#include <iostream>
#include <cmath>

using namespace std;

// Immutable struct to hold the results
struct tetraeder
{
  const float Volumen;
  const float Oberfläche;
  const float Inkreisradius;
  const float Umkreisradius;
};

tetraeder calculate(const int a)
{
  return {
    static_cast<float>(pow(a, 3) * sqrt(2) / 12),  // Volumen
    static_cast<float>(pow(a, 2) * sqrt(3)),       // Oberfläche
    static_cast<float>(a * sqrt(6) / 12),          // Inkreisradius
    static_cast<float>(a * sqrt(6) / 4)            // Umkreisradius
  };
}

int main()
{
  const int a = 2;
  const tetraeder t = calculate(a);
  cout << "Volumen:" << t.Volumen 
        << " Oberfläche:" << t.Oberfläche 
        << " Inkreisradius:" << t.Inkreisradius 
        << " Umkreisradius:" << t.Umkreisradius 
        << endl;
  return 0;
}