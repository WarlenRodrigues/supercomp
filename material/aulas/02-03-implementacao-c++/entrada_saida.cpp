#include <iostream>
#include <string>

int main() {

  int x;
  std::cout << "Entre com um número " << std::endl;
  std::cin >> x;

  std::cout << "Você digitou o número " << x << std::endl;

  std::string s;
  std::cout << "Digite uma string " << std::endl;
  std::cin >> s;

  std::cout << "Você digitou a string " << s << std::endl;

  return 0;
}
