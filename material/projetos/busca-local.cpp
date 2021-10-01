#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <random>

using namespace std;

struct subconjunto
{
    int index;
    vector<int> elementos;
};

bool operator==(const subconjunto &s1, const subconjunto &s2)
{
    if (s1.index == s2.index)
        return true;
    else
        return false;
}

typedef vector<subconjunto> data;

bool check_element_in_array(int x, vector<int> v)
{
    if (find(v.begin(), v.end(), x) != v.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool comparaConjuntos(subconjunto &a, subconjunto &b)
{
    return a.elementos.size() > b.elementos.size();
}

double calculaFitness(vector<int> elementosCobertos, vector<subconjunto> solucao)
{
    return (1.0 * elementosCobertos.size()) / (1.0 * solucao.size());
}

int main()
{

    default_random_engine generator;
    generator.seed(100);

    // DECLARANDO VARIÁVEIS NECESSÁRIAS
    int n_elementos, subconjuntos;
    vector<int> universo;
    data dados;

    // Recebendo dados de elementos e subconjuntos
    cin >> n_elementos >> subconjuntos;

    // Criando elementos
    for (int i = 1; i <= n_elementos; i++)
    {
        universo.push_back(i);
    }

    // Contador para adicionar subconjuntos ao vetor de subconjuntos "dados"
    int i = 0;

    // Lendo dados e adicionando subconjuntos em "dados"
    for (string line; getline(cin, line);)
    {
        subconjunto sub;
        sub.index = i;
        vector<int> line_data;
        string s = line;
        stringstream ss(s);
        istream_iterator<string> begin(ss);
        istream_iterator<string> end;
        vector<string> splited_line(begin, end);

        for (string el : splited_line)
        {
            int i = stoi(el);
            line_data.push_back(i);
        }

        sub.elementos = line_data;
        dados.push_back(sub);
        i++;
    }

    // Ordenando subconjuntos do maior para o menor
    sort(dados.begin(), dados.end(), comparaConjuntos);

    // criando variáveis para solução
    vector<int> elementos_cobertos;
    data solucao;
    int size = dados.size();

    // Passando conjunto por conjunto para pegar maior cobertura
    int j = 1;
    while (elementos_cobertos.size() != universo.size() && j <= size)
    {
        bool adicionou = false;

        // Variáveis de controle para definir melhor subconjunto a ser adicionado à solução
        subconjunto melhor_subconjunto;
        int mais_descobertos = 0;

        // Para cada conjunto em "dados"
        for (subconjunto conjunto : dados)
        {

            int descobertos_no_subconjunto = 0;

            // Para cada elemento no conjunto
            for (int el : conjunto.elementos)
            {
                // Se elemento não estiver nos cobertos, soma um na variável que definirá a escolha do melhor subconjunto
                if (!check_element_in_array(el, elementos_cobertos))
                {
                    descobertos_no_subconjunto++;
                }
            }

            // Se subconjunto atual melhor que o anterior, efetua as trocas
            if (mais_descobertos < descobertos_no_subconjunto)
            {
                mais_descobertos = descobertos_no_subconjunto;
                melhor_subconjunto = conjunto;
                adicionou = true;
            }
        }

        // Por fim, adiciona o subconjunto à solução e remove do vetor de possíveis subconjuntos, bem como adicionar seus elementos que faltam ao vetor dos cobertos
        if (adicionou)
        {
            for (int el : melhor_subconjunto.elementos)
            {
                if (!check_element_in_array(el, elementos_cobertos))
                {
                    elementos_cobertos.push_back(el);
                }
            }

            solucao.push_back(melhor_subconjunto);
            //Poderia remover os subconjutos já adicionados para economizar processamento
        }
        else
        {
            j++;
        }
    }

    data nao_utilizados;
    data solucao_2 = solucao;

    for (subconjunto s : dados)
    {
        if (!(find(solucao.begin(), solucao.end(), s) != solucao.end()))
        {
            nao_utilizados.push_back(s);
        }
    }

    uniform_int_distribution<int> remover(0, solucao.size());
    uniform_int_distribution<int> pegar(0, nao_utilizados.size());

    data nova_solucao = solucao;
    vector<int> novos_cobertos;

    int item_a_remover = remover(generator);
    int item_a_adicionar = pegar(generator);
    nova_solucao[item_a_remover].index = nao_utilizados[item_a_adicionar].index;
    nova_solucao[item_a_remover].elementos = nao_utilizados[item_a_adicionar].elementos;

    for (subconjunto s : nova_solucao)
    {
        for (int el : s.elementos)
        {
            novos_cobertos.push_back(el);
        }
    }

    double fitness_primeira_solucao = calculaFitness(elementos_cobertos, solucao);
    double fitness_segunda_solucao = calculaFitness(novos_cobertos, nova_solucao);

    data melhor_solucao = fitness_primeira_solucao >= fitness_segunda_solucao ? solucao : nova_solucao;

    // Seção de Output
    for (subconjunto s : melhor_solucao)
    {
        cout << s.index << " ";
    }

    cout << endl;
    return 0;
}