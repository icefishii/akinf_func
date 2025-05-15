#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct wuerfel
{
  const int Volumen;
  const int Oberfläche;
  const float Diagonale;
  const float Inkreisradius;
  const float Umkreisradius;
};
auto volumen = [](const int a)
{
  return static_cast<int>(pow(a, 3));
};
auto oberflaeche = [](const int a)
{
  return static_cast<int>(6 * pow(a, 2));
};
auto diagonale = [](const int a)
{
  return static_cast<float>(a * sqrt(3));
};
auto inkreisradius = [](const int a)
{
  return static_cast<float>(a / 2.0 * sqrt(3));
};
auto umkreisradius = [](const int a)
{
  return static_cast<float>(a / 2.0);
};

auto calculate = [](const int a)
{
  return wuerfel{
      volumen(a),
      oberflaeche(a),
      diagonale(a),
      inkreisradius(a),
      umkreisradius(a)};
};

auto output = [](const int volumen)
{
  return [=](const int oberflaeche)
  {
    return [=](const float diagonale)
    {
      return [=](const float inkreisradius)
      {
        return [=](const float umkreisradius)
        {
          return string("Volumen:") + to_string(volumen) + " Oberfläche:" + to_string(oberflaeche) + " Diagonale:" + to_string(diagonale) + " Inkreisradius:" + to_string(inkreisradius) + " Umkreisradius:" + to_string(umkreisradius);
        };
      };
    };
  };
};

int main()
{
  const int a = 2;
  const wuerfel w = calculate(a);
  cout << output(w.Volumen)(w.Oberfläche)(w.Diagonale)(w.Inkreisradius)(w.Umkreisradius) << endl;
  return 0;
}