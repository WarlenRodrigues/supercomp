#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct objeto
{
    int peso;
    int valor;
    int index;
};

// Funções de comparação para ordenação

bool comparaPorIndice(const objeto &a, const objeto &b)
{
    return a.index < b.index;
}

bool comparaPorValor(const objeto &a, const objeto &b)
{
    return a.valor > b.valor;
}

int main()
{
    // Declarando variáveis necessárias
    int n, capacidade;
    vector<objeto> objetos;

    // Recebendo dados necessários
    cin >> n >> capacidade;

    // cout << n << " elementos disponíveis para uma mochila de capacidade " << capacidade << "kg" << endl;

    for (int i = 0; i < n; i++)
    {
        objeto obj;
        obj.index = i;
        cin >> obj.peso >> obj.valor;
        objetos.push_back(obj);
    }

    // Ordenando vetor
    sort(objetos.begin(), objetos.end(), comparaPorValor);

    // Guardando o valor do tamanho do vetor de objetos e gerando lista de objetos adicionados à mochila
    int s = objetos.size();
    vector<objeto> mochila;

    // Coletando objetos para a mochila
    for (int i = 0; i < s; i++)
    {
        if (objetos[i].peso <= capacidade)
        {
            mochila.push_back(objetos[i]);
            capacidade -= objetos[i].peso;
        }
        // cout << "Objeto " << i << " com peso " << objetos[i].peso << " e valor " << objetos[i].valor << endl;
    }

    int ms = mochila.size();
    int W = 0;
    int V = 0;
    int opt = 0;

    // Ordenando objetos por indice na mochila
    sort(mochila.begin(), mochila.end(), comparaPorIndice);

    // Seção de Output
    for (int i = 0; i < ms; i++)
    {
        W += mochila[i].peso;
        V += mochila[i].valor;
    }

    cout << W << " " << V << " " << opt << endl;
    for (int i = 0; i < ms; i++)
    {
        cout << mochila[i].index << " ";
    }

    cout << endl;

    return 0;
}