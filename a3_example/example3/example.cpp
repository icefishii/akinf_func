#include <iostream>
#include <cmath>
#include <string>

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

// Curried lambda for output
auto output = [](float volumen)
{
  return [=](float oberflaeche)
  {
    return [=](float inkreisradius)
    {
      return [=](float umkreisradius)
      {
        return string("Volumen:") + to_string(volumen) + " Oberfläche:" + to_string(oberflaeche) + " Inkreisradius:" + to_string(inkreisradius) + " Umkreisradius:" + to_string(umkreisradius);
      };
    };
  };
};

int main()
{
  const int a = 2;
  const tetraeder t = calculate(a);
  cout << output(t.Volumen)(t.Oberfläche)(t.Inkreisradius)(t.Umkreisradius) << endl;
  return 0;
}