#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct ikosaeder
{
  const float Volumen;
  const float Oberfläche;
  const float Inkreisradius;
  const float Umkreisradius;
};

auto volumen = [](const int a)
{
  return static_cast<float>(5 * pow(a, 3) * (3 + sqrt(5)) / 12);
};
auto oberflaeche = [](const int a)
{
  return static_cast<float>(5 * pow(a, 2) * sqrt(3));
};
auto inkreisradius = [](const int a)
{
  return static_cast<float>(a * sqrt(3) * (3 + sqrt(5)) / 12);
};
auto umkreisradius = [](const int a)
{
  return static_cast<float>(a / 4.0 * sqrt(2 * (5 + sqrt(5))));
};

auto calculate = [](const int a)
{
  return ikosaeder{
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
  const ikosaeder i = calculate(a);
  cout << output(i.Volumen)(i.Oberfläche)(i.Inkreisradius)(i.Umkreisradius) << endl;
  return 0;
}