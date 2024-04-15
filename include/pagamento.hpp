#ifndef PAGAMENTO_HPP
#define PAGAMENTO_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Multa {
    string tipoMulta;
    float valor;
};

void realizarPagamento(const Multa& multa);
void listarMultasDisponiveis();
Multa selecionarMulta(int indice);

#endif
