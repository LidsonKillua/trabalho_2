#include <bits/stdc++.h>
#include "headers/Tribunal.hpp"

void LerVarios(){
    nomeArquivo = "eleitor.txt";
    std::ifstream arquivo(nomeArquivo);
    std::string linha;
    std::string titulo, nome, zona, secao;

    if(arquivo.is_open()){
        while(getline(arquivo, linha)){
            std::stringstream ss(linha);
            getline(ss, titulo, ',');
            getline(ss, nome, ',');
            getline(ss, zona, ',');
            getline(ss, secao, '\n');

            Tribunal::criarEleitor(titulo, nome, zona, secao);
        }

        arquivo.close();
    }

    nomeArquivo = "prefeito.txt";
    arquivo.open(nomeArquivo);
    std::string partido, cidade, numero;

    if(arquivo.is_open()){
        while(getline(arquivo, linha)){
            std::stringstream ss(linha);
            getline(ss, titulo, ',');
            getline(ss, nome, ',');
            getline(ss, zona, ',');
            getline(ss, secao, ',');
            getline(ss, partido, ',');
            getline(ss, cidade, ',');
            getline(ss, numero, '\n');

            Tribunal::criarPrefeito(titulo, nome, zona, secao, partido, cidade, numero);
        }

        arquivo.close();
    }

    nomeArquivo = "vereador.txt";
    arquivo.open(nomeArquivo);

    if(arquivo.is_open()){
        while(getline(arquivo, linha)){
            std::stringstream ss(linha);
            getline(ss, titulo, ',');
            getline(ss, nome, ',');
            getline(ss, zona, ',');
            getline(ss, secao, ',');
            getline(ss, partido, ',');
            getline(ss, cidade, ',');
            getline(ss, numero, '\n');

            Tribunal::criarVereador(titulo, nome, zona, secao, partido, cidade, numero);
        }

        arquivo.close();
    }
}

int main()
{
    int op;

    std::cout << "1 - Cadastro de eleitores" << std::endl;
    std::cout << "2 - Cadastro de prefeitos" << std::endl;
    std::cout << "3 - Cadastro de vereadores" << std::endl;
    std::cout << "4 - Iniciar Eleição" << std::endl;
    std::cout << "5 - Cadastrar automaticamente(Testes)" << std::endl;
    std::cout << "6 - Sair" << std::endl; 
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
        LerVarios();
        break;
    case 6:
        std::cout << "Saindo..." << std::endl;
        break;
    default:
        std::cout << "Opção inválida!" << std::endl;
        break;
    }

    return 0;
}
