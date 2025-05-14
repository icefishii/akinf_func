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

// Individual lambdas for each calculation
auto volumen = [](int a)
{
  return static_cast<int>(pow(a, 3));
};
auto oberflaeche = [](int a)
{
  return static_cast<int>(6 * pow(a, 2));
};
auto diagonale = [](int a)
{
  return static_cast<float>(a * sqrt(3));
};
auto inkreisradius = [](int a)
{
  return static_cast<float>(a / 2.0 * sqrt(3));
};
auto umkreisradius = [](int a)
{
  return static_cast<float>(a / 2.0);
};

// Pure, immutable lambda for calculate
auto calculate = [](int a)
{
  return wuerfel{
      volumen(a),
      oberflaeche(a),
      diagonale(a),
      inkreisradius(a),
      umkreisradius(a)};
};

// Curried lambda for output
auto output = [](int volumen)
{
  return [=](int oberflaeche)
  {
    return [=](float diagonale)
    {
      return [=](float inkreisradius)
      {
        return [=](float umkreisradius)
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