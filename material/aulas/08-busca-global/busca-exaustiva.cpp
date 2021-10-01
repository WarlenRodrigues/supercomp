#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct item
{
    int id;
    int peso;
    int valor;
};

int knapSack(int W, vector<item> items, vector<item> &usados, vector<item> &melhor)
{
    int valor = 0;
    int peso = 0;
    int sem_i = 0;
    int com_i = 0;
    vector<item> items2 = items;
    vector<item> usados2 = usados;
    if (items.empty() || W == 0)
        return 0;
    if (items[0].peso <= W)
    {
        usados.push_back(items[0]);
        valor = items[0].valor;
        peso = items[0].peso;
        items.erase(items.begin());
        com_i = knapSack(W - peso, items, usados, melhor);
    }
    //items2 é uma copia de items, antes do codigo que pode ter incluido ele.
    items2.erase(items2.begin());
    sem_i = knapSack(W, items2, usados2, melhor);

    int valor_atual = 0;
    int valor_melhor = 0;
    for (auto &el : usados)
        valor_atual += el.valor;
    for (auto &el : melhor)
        valor_melhor += el.valor;

    if (valor_atual > valor_melhor)
        melhor = usados;
    usados.clear();
    return max(sem_i, valor + com_i);
}

int main()
{

    int n = 0;
    int W = 0;
    vector<item> mochila;
    cin >> n >> W;
    vector<item> items;
    vector<item> usados;
    vector<item> melhor;
    items.reserve(n);
    melhor.reserve(n);

    int peso, valor;
    for (int i = 0; i < n; i++)
    {
        cin >> peso;
        cin >> valor;
        items.push_back({i, peso, valor});
    }

    cout << "RESULTADO = " << knapSack(W, items, usados, melhor) << endl;
    for (auto &el : melhor)
    {
        cout << el.id << " ";
    }

    return 0;
}