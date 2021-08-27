#include <iostream>
using namespace std;

int main() {

  int x;
  cout << "Entre com um número: " << endl;
  cin >> x;

  if (!cin) {
    cout << "Você não digitou um número" << endl;
    return 1;
  }

  int y;

  cout << "Entre com outro número " << endl;

  if (!(cin >> y)) {
    cout << "Voce não digitou um número " << endl;
    return 1;
  }

  // TO DO: informar qual dos números é o maios com IF e COUT

  if (x > y) {
    cout << "x: " << x << " é maior que y: " << y << endl;
  } else if (x == y) {
    cout << "x e y são iguais" << endl;
  } else {
    cout << "y: " << y << " é maior que x: " << x << endl;
  }

  cout << "Entre com dois números " << endl;
  cin >> x >> y;
  cout << x << endl;
  cout << y << endl;

  return 0;
}
