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

// Individual lambdas for each calculation
auto volumen = [](int a)
{
  return static_cast<float>(pow(a, 3) * sqrt(2) / 12);
};
auto oberflaeche = [](int a)
{
  return static_cast<float>(pow(a, 2) * sqrt(3));
};
auto inkreisradius = [](int a)
{
  return static_cast<float>(a * sqrt(6) / 12);
};
auto umkreisradius = [](int a)
{
  return static_cast<float>(a * sqrt(6) / 4);
};

// Pure, immutable lambda for calculate
auto calculate = [](int a)
{
  return tetraeder{
      volumen(a),
      oberflaeche(a),
      inkreisradius(a),
      umkreisradius(a)};
};

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