#include <iomanip> // std::setprecision
#include <iostream>
#include <math.h> /* pow */

using namespace std;

int main() {

  int n;
  int i = 0;
  double soma = 0;

  cout << "Entre com um número N..." << endl;
  cin >> n;

  while (i <= n) {
    soma += 1 / pow(2.0, i);
    i++;
  }

  cout << "A somatória é " << fixed << setprecision(15) << soma << endl;

  return 0;
}
