#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct quader
{
  const int Volumen;
  const int Oberfläche;
  const float Diagonale;
};

auto volumen = [](const int a, const int b, const int c)
{
  return a * b * c;
};
auto oberflaeche = [](const int a, const int b, const int c)
{
  return 2 * (a * b + a * c + b * c);
};
auto diagonale = [](const int a, const int b, const int c)
{
  return static_cast<float>(sqrt(a * a + b * b + c * c));
};

auto calculate = [](const int a)
{
  return [=](const int b)
  {
    return [=](const int c)
    {
      return quader{
          volumen(a, b, c),
          oberflaeche(a, b, c),
          diagonale(a, b, c)};
    };
  };
};

auto output = [](int volumen)
{
  return [=](int oberflaeche)
  {
    return [=](float diagonale)
    {
      return string("Volumen:") + to_string(volumen) + " Oberfläche:" + to_string(oberflaeche) + " Diagonale:" + to_string(diagonale);
    };
  };
};

int main()
{
  const int a = 2;
  const int b = 3;
  const int c = 4;
  const quader q = calculate(a)(b)(c);
  cout << output(q.Volumen)(q.Oberfläche)(q.Diagonale) << endl;
  return 0;
}