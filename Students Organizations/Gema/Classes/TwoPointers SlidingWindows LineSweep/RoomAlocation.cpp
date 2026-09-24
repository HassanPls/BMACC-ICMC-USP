#include <bits/stdc++.h>
using namespace std;

struct cliente {
    int a, b, id;
};

bool ComparaChegada(const cliente& c1, const cliente& c2) {
    return c1.a < c2.a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<cliente> clientes(n);
    for (int i = 0; i < n; i++)
    {
        cin >> clientes[i].a >> clientes[i].b;
        clientes[i].id = i;
    }
    
    sort(clientes.begin(), clientes.end(), ComparaChegada);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;
    vector<int> quarto_designado(n);
    int total_quartos = 0;

    for (int i = 0; i < n; i++)
    {
        int chegada = clientes[i].a;
        int saida = clientes[i].b;
        int id_original = clientes[i].id;

        int quarto_atual;

        if (!minheap.empty() && minheap.top().first < chegada) {
            quarto_atual = minheap.top().second;
            minheap.pop();
        } else {
            total_quartos++;
            quarto_atual = total_quartos;
        }

        quarto_designado[id_original] = quarto_atual;
        minheap.push({saida, quarto_atual});
    }
    
    cout << total_quartos << endl;
    for (int i = 0; i < n; i++)
    {
        cout << quarto_designado[i] << " ";
    }

    return 0;
}