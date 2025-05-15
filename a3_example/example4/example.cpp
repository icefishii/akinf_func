#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct oktaeder
{
  const float Volumen;
  const float Oberfläche;
  const float Inkreisradius;
  const float Umkreisradius;
};

auto volumen = [](const int a)
{
  return static_cast<float>(pow(a, 3) * sqrt(2) / 3);
};
auto oberflaeche = [](const int a)
{
  return static_cast<float>(2 * pow(a, 2) * sqrt(3));
};
auto inkreisradius = [](const int a)
{
  return static_cast<float>(a * sqrt(6) / 6);
};
auto umkreisradius = [](const int a)
{
  return static_cast<float>(a * sqrt(2) / 2);
};

auto calculate = [](const int a)
{
  return oktaeder{
      volumen(a),
      oberflaeche(a),
      inkreisradius(a),
      umkreisradius(a)};
};

auto output = [](const float volumen)
{
  return [=](const float oberflaeche)
  {
    return [=](const float inkreisradius)
    {
      return [=](const float umkreisradius)
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