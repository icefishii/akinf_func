#include <iostream>
#include <cmath>

using namespace std;

struct dodekaeder
{
  const float Volumen;
  const float Oberfläche;
  const float Inkreisradius;
  const float Umkreisradius;
};

dodekaeder calculate(const int a)
{
  return {
    static_cast<float>(pow(a, 3) * (15 + 7 * sqrt(5)) / 4.0),  // Volumen
    static_cast<float>(3 * pow(a, 2) * sqrt(5 * (5 + 2 * sqrt(5)))), // Oberfläche
    static_cast<float>(a * sqrt(10 * (25 + 11 * sqrt(5))) / 20.0),   // Inkreisradius
    static_cast<float>(a * sqrt(3) * (1 + sqrt(5)) / 4.0)            // Umkreisradius
  };
}

int main()
{
  const int a = 2;
  const dodekaeder d = calculate(a);
  cout << "Volumen:" << d.Volumen 
        << " Oberfläche:" << d.Oberfläche 
        << " Inkreisradius:" << d.Inkreisradius 
        << " Umkreisradius:" << d.Umkreisradius 
        << endl;
  return 0;
}