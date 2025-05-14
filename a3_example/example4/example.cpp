#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Immutable struct to hold the results
struct oktaeder
{
  const float Volumen;
  const float Oberfläche;
  const float Inkreisradius;
  const float Umkreisradius;
};

// Individual lambdas for each calculation
auto volumen = [](int a)
{
  return static_cast<float>(pow(a, 3) * sqrt(2) / 3);
};
auto oberflaeche = [](int a)
{
  return static_cast<float>(2 * pow(a, 2) * sqrt(3));
};
auto inkreisradius = [](int a)
{
  return static_cast<float>(a * sqrt(6) / 6);
};
auto umkreisradius = [](int a)
{
  return static_cast<float>(a * sqrt(2) / 2);
};

// Pure, immutable lambda for calculate
auto calculate = [](int a)
{
  return oktaeder{
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
  const oktaeder o = calculate(a);
  cout << output(o.Volumen)(o.Oberfläche)(o.Inkreisradius)(o.Umkreisradius) << endl;
  return 0;
}