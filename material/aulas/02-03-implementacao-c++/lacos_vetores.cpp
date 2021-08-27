#include <iostream>
#include <vector>
using namespace std;

int main() {

  int x;

  int w[] = {1, 2, 3};
  cout << w[0] << endl;

  vector<int> v;
  cout << "Entre quantos numeros desejar: " << endl;

  while (cin >> x) {
    v.push_back(x); //insere x em v
  }

  size_t index = 0;
  size_t greaterItemIndex = 0;
  size_t lowerItemIndex = 0;

  if (v.empty()) {
    cout << "O vetor é vazio..." << endl;
  } else {
    while (index < v.size()) {
      if (v[index] > v[greaterItemIndex]) {
        greaterItemIndex = index;
      }

      if (v[index] < v[lowerItemIndex]) {
        lowerItemIndex = index;
      }

      index++;
    }
  }

  cout << "Biggest value: " << v[greaterItemIndex] << " found at index " << greaterItemIndex << endl;
  cout << "Smallest value: " << v[lowerItemIndex] << " found at index " << lowerItemIndex << endl;

  cout << "Elementos do vetor..." << endl;
  for (auto &e : v)
    cout << e << "\t";
  cout << "\n";
  return 0;
}
