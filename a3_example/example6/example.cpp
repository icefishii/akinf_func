#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct dodekaeder
{
  const float Volumen;
  const float Oberfläche;
  const float Inkreisradius;
  const float Umkreisradius;
};

auto volumen = [](const int a)
{
  return static_cast<float>(pow(a, 3) * (15 + 7 * sqrt(5)) / 4.0);
};
auto oberflaeche = [](const int a)
{
  return static_cast<float>(3 * pow(a, 2) * sqrt(5 * (5 + 2 * sqrt(5))));
};
auto inkreisradius = [](const int a)
{
  return static_cast<float>(a * sqrt(10 * (25 + 11 * sqrt(5))) / 20.0);
};
auto umkreisradius = [](const int a)
{
  return static_cast<float>(a * sqrt(3) * (1 + sqrt(5)) / 4.0);
};

auto calculate = [](int a)
{
  return dodekaeder{
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
  const dodekaeder d = calculate(a);
  cout << output(d.Volumen)(d.Oberfläche)(d.Inkreisradius)(d.Umkreisradius) << endl;
  return 0;
}