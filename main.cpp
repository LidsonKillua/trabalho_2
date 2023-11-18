#include <bits/stdc++.h>
#include "headers/Eleitor.hpp"
#include "headers/Prefeito.hpp"
#include "headers/Vereador.hpp"


int main()
{
    std::vector<Eleitor> eleitores;
    std::vector<Prefeito> prefeitos;
    std::vector<Vereador> vereadores;
    std::map<std::string, int> votosPrefeitos;
    std::map<std::string, int> votosVereadores;
    int op;

    std::cout << "1 - Cadastrar eleitor" << std::endl;
    std::cout << "2 - Cadastrar prefeito" << std::endl;
    std::cout << "3 - Cadastrar vereador" << std::endl;
    std::cout << "4 - Votar" << std::endl;
    std::cout << "5 - Sair" << std::endl;
    std::cout << "6 - Ler automaticamente" << std::endl; 
    std::cout << "Qual operação você deseja fazer?: ";
    std::cin >> op;

    switch(op)
    {
    case 1:
        Eleitor::lerEleitor(&eleitores);
        break;
    case 2:
        Prefeito::lerPrefeito(&prefeitos);
        break;
    case 3:
        Vereador::lerVereador(&vereadores);
        break;
    case 4:
        //Eleitor::votar(&eleitores, &prefeitos, &vereadores, &votosPrefeitos, &votosVereadores);
        break;
    case 5:
        std::cout << "Saindo..." << std::endl;
        break;
    case 6:
        Eleitor::lerEleitor(&eleitores);
        Prefeito::lerPrefeito(&prefeitos);
        Vereador::lerVereador(&vereadores);
        break;
    default:
        std::cout << "Opção inválida!" << std::endl;
        break;
    }

    return 0;
}
