#include <iostream>
#include "pagamento.hpp"
#include "renovacao.hpp"

using namespace std;

int main() {
    
    listarMultasDisponiveis();
    int indiceMulta;
    cout << "Selecione uma multa: ";
    cin >> indiceMulta;
    Multa multaSelecionada = selecionarMulta(indiceMulta);
    realizarPagamento(multaSelecionada);

    std::vector<Livro> acervo = {
        {"A Revolucao dos Bichos", "George Orwell", 14, true},
        {"O Senhor dos Aneis", "J.R.R. Tolkien", 7, false},
        {"1984", "George Orwell", 21, true}
    };

    listarLivrosDisponiveis(acervo);

    std::string titulo;
    std::cout << "\nDigite o titulo do livro que deseja renovar o emprestimo: ";
    std::getline(std::cin, titulo);

    renovarEmprestimo(acervo, titulo);
    
    return 0;
}
