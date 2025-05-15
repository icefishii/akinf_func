#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct tetraeder
{
  const float Volumen;
  const float Oberfläche;
  const float Inkreisradius;
  const float Umkreisradius;
};

auto volumen = [](const int a)
{
  return static_cast<float>(pow(a, 3) * sqrt(2) / 12);
};
auto oberflaeche = [](const int a)
{
  return static_cast<float>(pow(a, 2) * sqrt(3));
};
auto inkreisradius = [](const int a)
{
  return static_cast<float>(a * sqrt(6) / 12);
};
auto umkreisradius = [](const int a)
{
  return static_cast<float>(a * sqrt(6) / 4);
};

auto calculate = [](const int a)
{
  return tetraeder{
      volumen(a),
      oberflaeche(a),
      inkreisradius(a),
      umkreisradius(a)};
};

// Curried lambda for output
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
  const tetraeder t = calculate(a);
  cout << output(t.Volumen)(t.Oberfläche)(t.Inkreisradius)(t.Umkreisradius) << endl;
  return 0;
}