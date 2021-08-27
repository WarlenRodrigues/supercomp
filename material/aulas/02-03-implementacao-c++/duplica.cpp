#include <iostream>

using namespace std;

void duplica(int v) {
  v = v * 2;
  cout << "O valor duplicado é = " << v << endl;
}

void duplicav2(int &v) {
  v = v * 2;
  cout << "O valor duplicado é = " << v << endl;
}

int main() {

  int x = 10;

  duplica(x);

  cout << "x = " << x << endl;

  duplicav2(x);

  cout << "x = " << x << endl;

  return 0;
}
