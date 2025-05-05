#include <iostream>
#include <cmath>

using namespace std;

struct ikosaeder
{
  const float Volumen;
  const float Oberfläche;
  const float Inkreisradius;
  const float Umkreisradius;
};

ikosaeder calculate(const int a)
{
  return {
    static_cast<float>(5 * pow(a, 3) * (3 + sqrt(5)) / 12),  // Volumen
    static_cast<float>(5 * pow(a, 2) * sqrt(3)),            // Oberfläche
    static_cast<float>(a * sqrt(3) * (3 + sqrt(5)) / 12),   // Inkreisradius
    static_cast<float>(a / 4.0 * sqrt(2 * (5 + sqrt(5))))   // Umkreisradius
  };
}

int main()
{
  const int a = 2;
  const ikosaeder i = calculate(a);
  cout << "Volumen:" << i.Volumen 
        << " Oberfläche:" << i.Oberfläche 
        << " Inkreisradius:" << i.Inkreisradius 
        << " Umkreisradius:" << i.Umkreisradius 
        << endl;
  return 0;
}