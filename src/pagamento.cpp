#include "pagamento.hpp"
#include <vector>

using namespace std;

void realizarPagamento(const Multa& multa) {
    cout << "Pagamento de multa online:\n";
    cout << "Tipo de multa: " << multa.tipoMulta << "\n";
    cout << "Valor: R$ " << multa.valor << "\n";
}

void listarMultasDisponiveis() {
    vector<Multa> multas = {
        {"Atraso na devolucao", 15.50},
        {"Danos ao livro", 25.00},
        {"Perda do livro", 50.00}
    };

    cout << "Multas para pagamento:\n";
    for (size_t i = 0; i < multas.size(); ++i) {
        cout << i + 1 << ". " << multas[i].tipoMulta << "\n";
    }
}

Multa selecionarMulta(int indice) {
    vector<Multa> multas = {
        {"Atraso na devolucao", 15.50},
        {"Danos ao livro", 25.00},
        {"Perda do livro", 50.00}
    };

    if (indice >= 1 && indice <= static_cast<int>(multas.size())) {
        return multas[indice - 1]; 
    } else {
        return {"", 0.0};
    }
}
