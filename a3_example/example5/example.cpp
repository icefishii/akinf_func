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

// Individual lambdas for each calculation
auto volumen = [](int a)
{
  return static_cast<float>(5 * pow(a, 3) * (3 + sqrt(5)) / 12);
};
auto oberflaeche = [](int a)
{
  return static_cast<float>(5 * pow(a, 2) * sqrt(3));
};
auto inkreisradius = [](int a)
{
  return static_cast<float>(a * sqrt(3) * (3 + sqrt(5)) / 12);
};
auto umkreisradius = [](int a)
{
  return static_cast<float>(a / 4.0 * sqrt(2 * (5 + sqrt(5))));
};

// Pure, immutable lambda for calculate
auto calculate = [](int a)
{
  return ikosaeder{
      volumen(a),
      oberflaeche(a),
      inkreisradius(a),
      umkreisradius(a)};
};

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