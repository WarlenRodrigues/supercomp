#include <iomanip> // std::setprecision
#include <iostream>
#include <math.h> /* pow */
#include <vector>

// Testing push settings from monstrao

using namespace std;

int main() {

  int n;
  double media = 0;
  double desvpad = 0;
  vector<double> vec;

  cout << "Entre com um número N..." << endl;
  cin >> n;
  cout << "Entre N números..." << endl;

  for (int i = 0; i < n; i++) {
    double x;
    cin >> x;
    vec.push_back(x);
  }

  for (int j = 0; j < n; j++) {
    media += vec[j] / n;
  }

  for (int j = 0; j < n; j++) {
    desvpad += pow(vec[j] - media, 2.0) / n;
  }

  cout << "A média é " << fixed << setprecision(10) << media << endl;
  cout << "O desvio padrão é " << fixed << setprecision(10) << desvpad << endl;

  return 0;
}
