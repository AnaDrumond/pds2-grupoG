#include <iostream>
#include "pagamento.hpp"

using namespace std;

int main() {
    
    listarMultasDisponiveis();
    int indiceMulta;
    cout << "Selecione uma multa: ";
    cin >> indiceMulta;
    Multa multaSelecionada = selecionarMulta(indiceMulta);
    realizarPagamento(multaSelecionada);

    return 0;
}
