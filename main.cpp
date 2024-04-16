#include <iostream>
#include "chat.hpp"
#include "biblioteca.hpp"
#include "pagamento_multas.hpp"
#include "notificacoes.hpp"

using namespace std;
using namespace Notificacoes;
using namespace Biblioteca;

int main() {
    cout << "Bem-vindo ao Chat Online da Biblioteca!\n";

    string pergunta;
    while (true) {
        cout << "\nVoce: ";
        getline(cin, pergunta);

        if (pergunta.empty()) {
            cout << "Saindo do Chat Online...\n";
            break;
        }

        string resposta = ChatOnline::responderDuvida(pergunta);
        cout << "Biblioteca: " << resposta << "\n";
    }

    cout << "Livros Disponiveis:\n";
    auto livros = Biblioteca::listarLivrosDisponiveis();
    for (const auto& livro : livros) {
        cout << livro.titulo << " - " << livro.autor << " (" << (livro.disponivel ? "Disponivel" : "Indisponivel") << ")\n";
    }

    string tituloParaReserva;
    cout << "\nDigite o titulo do livro que deseja reservar: ";
    getline(cin, tituloParaReserva);

    if (Biblioteca::reservarLivro(tituloParaReserva)) {
        enviarNotificacaoDisponibilidade();
    } else {
        cout << "Desculpe, o livro '" << tituloParaReserva << "' nao esta disponivel para reserva.\n";
    }

    listarMultasDisponiveis();

    int indiceSelecionado;
    cout << "\nSelecione o numero da multa que deseja pagar: ";
    cin >> indiceSelecionado;

    Multa multaSelecionada = selecionarMulta(indiceSelecionado);

    if (multaSelecionada.tipoMulta.empty()) {
        cout << "Multa invalida. Encerrando o programa.\n";
        return 1;
    }

    PagamentoMultas::realizarPagamento(multaSelecionada);
    
    return 0;
}
