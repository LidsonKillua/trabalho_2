#include "headers/Tribunal.hpp"
#include <iostream>

int main()
{
    Tribunal* TribunalPrincipal; 
    int op;
    std::cout << "Bem vindo ao sistema de eleição!" << std::endl;

    bool rodar = true;
    while(rodar){   
        std::cout << "\nEscolha uma opção:" << std::endl; 
        std::cout << "1 - Cadastro de eleitores" << std::endl;
        std::cout << "2 - Cadastro de prefeitos" << std::endl;
        std::cout << "3 - Cadastro de vereadores" << std::endl;
        std::cout << "4 - Listar cadastrados" << std::endl;
        std::cout << "5 - Iniciar Eleição" << std::endl;
        std::cout << "6 - Cadastrar automaticamente(Testes)" << std::endl;
        std::cout << "9 - Sair" << std::endl;
        std::cin >> op;

        switch(op)
        {
        case 1:
            TribunalPrincipal->CadastroEleitor();
            break;
        case 2:
            TribunalPrincipal->CadastroPrefeito();
            break;
        case 3:
            TribunalPrincipal->CadastroVereador();
            break;
        case 4:
            TribunalPrincipal->listarTodos();
            break;
        case 5:
            TribunalPrincipal->realizarEleicao();
            break;
        case 6:
            TribunalPrincipal->LerVarios();
            break;
        case 9:
            std::cout << "Saindo..." << std::endl;
            rodar = false;
            break;
        default:
            std::cout << "Opção inválida!" << std::endl;
            break;
        }   
    }

    delete TribunalPrincipal;

    return 0;
}
