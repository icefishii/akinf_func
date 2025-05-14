#include <iostream>
#include <cmath>

using namespace std;

struct quader
{
  const int Volumen;
  const int Oberfläche;
  const float Diagonale;
};

// Curried lambda for calculate
auto calculate = [](int a)
{
  return [a](int b)
  {
    return [a, b](int c)
    {
      return quader{
          a * b * c,                                      // Volumen
          2 * (a * b + a * c + b * c),                    // Oberfläche
          static_cast<float>(sqrt(a * a + b * b + c * c)) // Diagonale
      };
    };
  };
};

int main()
{
  const int a = 2;
  const int b = 3;
  const int c = 4;
  const quader q = calculate(a)(b)(c);
  cout << "Volumen:" << q.Volumen
       << " Oberfläche:" << q.Oberfläche
       << " Diagonale:" << q.Diagonale
       << endl;
  return 0;
}