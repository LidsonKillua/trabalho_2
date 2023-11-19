#include "../headers/Tribunal.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

Tribunal::Tribunal()
{
}

Tribunal::~Tribunal()
{
}

bool Tribunal::IsEleitor(std::string titulo){
    for(auto eleitor : eleitores){
        if(eleitor.getTitulo() == titulo){
            return true;
        }
    }
    return false;
}

Eleitor Tribunal::getEleitor(std::string titulo){
    for(auto eleitor : eleitores){
        if(eleitor.getTitulo() == titulo){
            return eleitor;
        }
    }
    std::cout << "Eleitor não encontrado e criado" << std::endl;
    return Eleitor(titulo, "", "", "");
}

bool Tribunal::IsPrefeito(std::string titulo){
    for(auto prefeito : prefeitos){
        if(prefeito.getTitulo() == titulo){
            return true;
        }
    }
    return false;
}

bool Tribunal::IsVereador(std::string titulo){
    for(auto vereador : vereadores){
        if(vereador.getTitulo() == titulo){
            return true;
        }
    }
    return false;
}

void Tribunal::criarEleitor(const std::string titulo, const std::string nome, const std::string zona, const std::string secao){
    if(IsEleitor(titulo)){
        std::cerr << "Eleitor já cadastrado!" << std::endl;
        return;
    }
    eleitores.push_back(Eleitor(titulo, nome, zona, secao));
}

void Tribunal::lerEleitor(std::string titulo){
    for(auto eleitor : eleitores){
        if(eleitor.getTitulo() == titulo){
            eleitor.display();
            return;
        }
    }
    std::cout << "Eleitor não encontrado!" << std::endl;
}

void Tribunal::atualizarEleitor(const std::string titulo, const std::string nome, const std::string zona, const std::string secao){
    for(auto eleitor : eleitores){
        if(eleitor.getTitulo() == titulo){
            eleitor.setNome(nome);
            eleitor.setZona(zona);
            eleitor.setSecao(secao);
            return;
        }
    }
    std::cout << "Eleitor não encontrado!" << std::endl;
}

void Tribunal::deletarEleitor(std::string titulo){
    for(int i = 0; i < eleitores.size(); i++){
        if(eleitores[i].getTitulo() == titulo){
            eleitores.erase(eleitores.begin() + i);
            return;
        }
    }  
    std::cout << "Eleitor não encontrado!" << std::endl;
}

void Tribunal::criarPrefeito(const std::string titulo, const std::string nome, const std::string zona, 
    const std::string secao, const std::string partido, const std::string cidade, const std::string numero)
{
    // Se já existir um eleitor com o título, criar um prefeito e associar a ele
    if(IsEleitor(titulo)){
        prefeitos.push_back(Prefeito(getEleitor(titulo), partido, cidade, numero));
        return;
    }   
    else{
        // Se não existir, criar um eleitor e um prefeito
        Eleitor eleitor(titulo, nome, zona, secao);
        eleitores.push_back(eleitor);
        prefeitos.push_back(Prefeito(eleitor, partido, cidade, numero));
    }
}

void Tribunal::criarPrefeito(const Eleitor& eleitor, const std::string partido, const std::string cidade, const std::string numero){
    prefeitos.push_back(Prefeito(eleitor, partido, cidade, numero));
}

void Tribunal::lerPrefeito(std::string titulo){
    for(auto prefeito : prefeitos){
        if(prefeito.getTitulo() == titulo){
            prefeito.display();
            return;
        }
    }
    std::cout << "Prefeito não encontrado!" << std::endl;
}

void Tribunal::atualizarPrefeito(std::string titulo, const std::string nome, const std::string zona, const std::string secao, const std::string partido, const std::string cidade, const std::string numero){
    for(auto prefeito : prefeitos){
        if(prefeito.getTitulo() == titulo){
            prefeito.setNome(nome);
            prefeito.setZona(zona);
            prefeito.setSecao(secao);
            prefeito.setPartido(partido);
            prefeito.setCidade(cidade);
            prefeito.setNumero(numero);
            return;
        }
    }
    std::cout << "Prefeito não encontrado!" << std::endl;
}

void Tribunal::deletarPrefeito(std::string titulo){
    for(int i = 0; i < prefeitos.size(); i++){
        if(prefeitos[i].getTitulo() == titulo){
            prefeitos.erase(prefeitos.begin() + i);
            return;
        }
    }
    std::cout << "Prefeito não encontrado!" << std::endl;
}

void Tribunal::criarVereador(const std::string titulo, const std::string nome, const std::string zona, 
    const std::string secao, const std::string partido, const std::string cidade, const std::string numero)
{
    // Se já existir um eleitor com o título, criar um vereador e associar a ele
    if(IsEleitor(titulo)){
        vereadores.push_back(Vereador(getEleitor(titulo), partido, cidade, numero));
        return;
    }   
    else{
        // Se não existir, criar um eleitor e um vereador
        Eleitor eleitor(titulo, nome, zona, secao);
        eleitores.push_back(eleitor);
        vereadores.push_back(Vereador(eleitor, partido, cidade, numero));
    }
}

void Tribunal::criarVereador(const Eleitor& eleitor, const std::string partido, const std::string cidade, const std::string numero){
    vereadores.push_back(Vereador(eleitor, partido, cidade, numero));
}

void Tribunal::lerVereador(std::string titulo){
    for(auto vereador : vereadores){
        if(vereador.getTitulo() == titulo){
            vereador.display();
            return;
        }
    }
    std::cout << "Vereador não encontrado!" << std::endl;
}

void Tribunal::atualizarVereador(std::string titulo, const std::string nome, const std::string zona, const std::string secao, const std::string partido, const std::string cidade, const std::string numero){
    for(auto vereador : vereadores){
        if(vereador.getTitulo() == titulo){
            vereador.setNome(nome);
            vereador.setZona(zona);
            vereador.setSecao(secao);
            vereador.setPartido(partido);
            vereador.setCidade(cidade);
            vereador.setNumero(numero);
            return;
        }
    }
    std::cout << "Vereador não encontrado!" << std::endl;
}

void Tribunal::deletarVereador(std::string titulo){
    for(int i = 0; i < vereadores.size(); i++){
        if(vereadores[i].getTitulo() == titulo){
            vereadores.erase(vereadores.begin() + i);
            return;
        }
    }
    std::cout << "Vereador não encontrado!" << std::endl;
}

void Tribunal::realizarEleicao(){
    std::cout << "Iniciando o processo de eleição..." << std::endl;
    int op = 1;

    while (op != 0){
        std::cout << "Escolha uma opção:" << std::endl; 
        std::cout << "1 - Votar para prefeito" << std::endl;
        std::cout << "2 - Votar para vereador" << std::endl;
        std::cout << "3 - Verificar mais votados no momento" << std::endl;
        std::cout << "0 - Finalizar eleição" << std::endl;
        std::cin >> op;

        switch (op)
        {
        case 1:
            votarPrefeito();
            break;
        case 2:
            votarVereador();
            break;
        case 3:
            relatorioEleicao();
            break;        
        case 0:
            finalizarEleicao();
            break;
        default:
            std::cout << "Opção inválida!" << std::endl;
            break;
        }
    }
}

void Tribunal::votarPrefeito(){
    std::string titulo;
    std::cout << "Digite o título do eleitor: ";
    std::cin >> titulo;

    if(!IsEleitor(titulo)){
        std::cerr << "Eleitor não cadastrado!" << std::endl;
        return;
    }
    else if(getEleitor(titulo).IsJaVotouPrefeito()){
        std::cerr << "Este eleitor já votou para prefeito!" << std::endl;
        return;
    }

    std::string numero;
    std::cout << "Digite o numero do prefeito em que quer votar: ";
    std::cin >> numero;

    for(auto prefeito : prefeitos){
        if(prefeito.getNumero() == numero){
            prefeito.ReceberVoto();
            getEleitor(titulo).setJaVotouPrefeito(true);
            return;
        }
    }
    std::cout << "Prefeito não encontrado!" << std::endl;
}

void Tribunal::votarVereador(){
    std::string titulo;
    std::cout << "Digite o título do eleitor: ";
    std::cin >> titulo;

    if(!IsEleitor(titulo)){
        std::cerr << "Eleitor não cadastrado!" << std::endl;
        return;
    }
    else if(getEleitor(titulo).IsJaVotouVereador()){
        std::cerr << "Este eleitor já votou para vereador!" << std::endl;
        return;
    }

    std::string numero;
    std::cout << "Digite o numero do vereador em que quer votar: ";
    std::cin >> numero;

    for(auto vereador : vereadores){
        if(vereador.getNumero() == numero){
            vereador.ReceberVoto();
            getEleitor(titulo).setJaVotouVereador(true);
            return;
        }
    }
    std::cout << "Vereador não encontrado!" << std::endl;
}

void Tribunal::relatorioEleicao(){
    std::cout << "---" << std::endl;
    std::cout << "Relatório da eleição:" << std::endl;
    std::cout << "---" << std::endl;

    std::cout << "3 Prefeitos mais votados:" << std::endl;
    int qtd = 3;

    // Ordenar prefeitos por votos
    std::sort(prefeitos.begin(), prefeitos.end(), [](Prefeito a, Prefeito b){
        return a.getVotos() > b.getVotos();
    });

    for(auto prefeito : prefeitos){
        if(qtd == 0){
            break;
        }
        std::cout << prefeito.getNumero() << " - " << prefeito.getNome() << " - " << prefeito.getVotos() << " votos" << std::endl;
        qtd--;
    }

    std::cout << "15 Vereadores mais votados:" << std::endl;

    // Ordenar vereadores por votos
    std::sort(vereadores.begin(), vereadores.end(), [](Vereador a, Vereador b){
        return a.getVotos() > b.getVotos();
    });

    qtd = 15;

    for(auto vereador : vereadores){
        if(qtd == 0){
            break;
        }
        std::cout << vereador.getNumero() << " - " << vereador.getNome() << " - " << vereador.getVotos() << " votos" << std::endl;
        qtd--;
    }

    std::cout << "---" << std::endl;   
}

void Tribunal::finalizarEleicao(){
    std::cout << "Finalizando eleição..." << std::endl;
    std::cout << "Contabilizando votos..." << std::endl;

    relatorioEleicao();

    std::cout << "O prefeito eleito é: " << prefeitos[0].getNome() << std::endl;

    std::cout << "Os 10 vereadores eleitos são: " << std::endl;
    int qtd = 10;

    for(auto vereador : vereadores){
        if(qtd == 0){
            break;
        }
        std::cout << vereador.getNome() << std::endl;
        qtd--;
    }    
}

void Tribunal::listarEleitores(){
    std::cout << "Eleitores cadastrados:" << std::endl;

    for(auto eleitor : eleitores){
        eleitor.display();
    }
}

void Tribunal::listarPrefeitos(){
    std::cout << "Candidatos a Prefeito cadastrados:" << std::endl;

    for(auto prefeito : prefeitos){
        prefeito.display();
    }
}

void Tribunal::listarVereadores(){
    std::cout << "Candidatos a Vereador cadastrados:" << std::endl;

    for(auto vereador : vereadores){
        vereador.display();
    }
}

void Tribunal::listarTodos(){
    listarPrefeitos();
    listarVereadores();
    listarEleitores();
}

void Tribunal::CadastroEleitor(){
    std::cout << "Cadastro de eleitores...";
    int opc = 1;

    while(opc != 0){
        std::cout << "Escolha uma opção:" << std::endl;
        std::cout << "1 - Cadastrar eleitor" << std::endl;
        std::cout << "2 - Ler eleitor" << std::endl;
        std::cout << "3 - Atualizar eleitor" << std::endl;
        std::cout << "4 - Deletar eleitor" << std::endl;
        std::cout << "5 - Listar eleitores" << std::endl;
        std::cout << "0 - Voltar" << std::endl;
        std::cin >> opc;

        
        std::string titulo, nome, zona, secao;
        switch (opc)
        {
        case 1:            
            std::cout << "Digite o título do eleitor: ";
            std::cin >> titulo;
            std::cout << "Digite o nome do eleitor: ";
            std::cin >> nome;
            std::cout << "Digite a zona do eleitor: ";
            std::cin >> zona;
            std::cout << "Digite a seção do eleitor: ";
            std::cin >> secao;

            criarEleitor(titulo, nome, zona, secao);
            break;           

        case 2:
            std::cout << "Digite o título do eleitor: ";
            std::cin >> titulo;
            lerEleitor(titulo);
            break;

        case 3:
            std::cout << "Digite o título do eleitor: ";
            std::cin >> titulo;
            std::cout << "Digite o nome do eleitor: ";
            std::cin >> nome;
            std::cout << "Digite a zona do eleitor: ";
            std::cin >> zona;
            std::cout << "Digite a seção do eleitor: ";
            std::cin >> secao;

            atualizarEleitor(titulo, nome, zona, secao);
            break;
        case 4:
            std::cout << "Digite o título do eleitor: ";
            std::cin >> titulo;
            deletarEleitor(titulo);
            break;
        
        case 5:
            listarEleitores();
            break;
        
        case 0:
            break;

        default:
            std::cout << "Opção inválida!" << std::endl;
            break;
        }
    }    
}

void Tribunal::CadastroPrefeito(){
    std::cout << "Cadastro de prefeitos...";
    int op = 1;

    while(op != 0){
        std::cout << "Escolha uma opção:" << std::endl;
        std::cout << "1 - Cadastrar prefeito" << std::endl;
        std::cout << "2 - Ler prefeito" << std::endl;
        std::cout << "3 - Atualizar prefeito" << std::endl;
        std::cout << "4 - Deletar prefeito" << std::endl;
        std::cout << "5 - Listar prefeitos" << std::endl;
        std::cout << "0 - Voltar" << std::endl;
        std::cin >> op;

        std::string titulo, nome, zona, secao, partido, cidade, numero;
        switch (op)
        {
        case 1:
            std::cout << "Digite o título do eleitor: ";
            std::cin >> titulo;
            std::cout << "Digite o nome do eleitor: ";
            std::cin >> nome;
            std::cout << "Digite a zona do eleitor: ";
            std::cin >> zona;
            std::cout << "Digite a seção do eleitor: ";
            std::cin >> secao;
            std::cout << "Digite o partido do prefeito: ";
            std::cin >> partido;
            std::cout << "Digite a cidade do prefeito: ";
            std::cin >> cidade;
            std::cout << "Digite o número do prefeito: ";
            std::cin >> numero;

            criarPrefeito(titulo, nome, zona, secao, partido, cidade, numero);
            break;

        case 2:
            std::cout << "Digite o título do prefeito: ";
            std::cin >> titulo;
            lerPrefeito(titulo);
            break;
        
        case 3:
            std::cout << "Digite o título do prefeito: ";
            std::cin >> titulo;
            std::cout << "Digite o nome do prefeito: ";
            std::cin >> nome;
            std::cout << "Digite a zona do prefeito: ";
            std::cin >> zona;
            std::cout << "Digite a seção do prefeito: ";
            std::cin >> secao;
            std::cout << "Digite o partido do prefeito: ";
            std::cin >> partido;
            std::cout << "Digite a cidade do prefeito: ";
            std::cin >> cidade;
            std::cout << "Digite o número do prefeito: ";
            std::cin >> numero;
            atualizarPrefeito(titulo, nome, zona, secao, partido, cidade, numero);
            break;

        case 4:
            std::cout << "Digite o título do prefeito: ";
            std::cin >> titulo;
            deletarPrefeito(titulo);
            break;

        case 5:
            listarPrefeitos();
            break;

        case 0:
            break;
        
        default:
            std::cout << "Opção inválida!" << std::endl;
            break;
        }
    }
}

void Tribunal::CadastroVereador(){
    std::cout << "Cadastro de vereadores...";
    int op = 1;

    while(op != 0){
        std::cout << "Escolha uma opção:" << std::endl;
        std::cout << "1 - Cadastrar vereador" << std::endl;
        std::cout << "2 - Ler vereador" << std::endl;
        std::cout << "3 - Atualizar vereador" << std::endl;
        std::cout << "4 - Deletar vereador" << std::endl;
        std::cout << "5 - Listar vereadores" << std::endl;
        std::cout << "0 - Voltar" << std::endl;
        std::cin >> op;

        std::string titulo, nome, zona, secao, partido, cidade, numero;
        switch (op)
        {
        case 1:
            std::cout << "Digite o título do eleitor: ";
            std::cin >> titulo;
            std::cout << "Digite o nome do eleitor: ";
            std::cin >> nome;
            std::cout << "Digite a zona do eleitor: ";
            std::cin >> zona;
            std::cout << "Digite a seção do eleitor: ";
            std::cin >> secao;
            std::cout << "Digite o partido do vereador: ";
            std::cin >> partido;
            std::cout << "Digite a cidade do vereador: ";
            std::cin >> cidade;
            std::cout << "Digite o número do vereador: ";
            std::cin >> numero;

            criarVereador(titulo, nome, zona, secao, partido, cidade, numero);
            break;

        case 2:
            std::cout << "Digite o título do vereador: ";
            std::cin >> titulo;
            lerVereador(titulo);
            break;
        
        case 3:
            std::cout << "Digite o título do vereador: ";
            std::cin >> titulo;
            std::cout << "Digite o nome do vereador: ";
            std::cin >> nome;
            std::cout << "Digite a zona do vereador: ";
            std::cin >> zona;
            std::cout << "Digite a seção do vereador: ";
            std::cin >> secao;
            std::cout << "Digite o partido do vereador: ";
            std::cin >> partido;
            std::cout << "Digite a cidade do vereador: ";
            std::cin >> cidade;
            std::cout << "Digite o número do vereador: ";
            std::cin >> numero;
            atualizarVereador(titulo, nome, zona, secao, partido, cidade, numero);
            break;
        
        case 4:
            std::cout << "Digite o título do vereador: ";
            std::cin >> titulo;
            deletarVereador(titulo);
            break;

        case 5:
            listarVereadores();
            break;
        
        case 0:
            break;

        default:
            std::cout << "Opção inválida!" << std::endl;
            break;
        }
    }
}

void Tribunal::LerVarios(){
    std::cout << "Lendo arquivos de teste..." << std::endl;
    std::cout << "Lendo eleitores..." << std::endl;

    std::ifstream arquivo("geradores/eleitor.txt");    
    if (!arquivo.is_open()){
        std::cerr << "Erro ao abrir arquivo de eleitores!" << std::endl;
        return;
    }

    std::string linha, titulo, nome, zona, secao;

    while(getline(arquivo, linha)){
        std::stringstream ss(linha);
        getline(ss, titulo, ',');
        getline(ss, nome, ',');
        getline(ss, zona, ',');
        getline(ss, secao, '\n');

        criarEleitor(titulo, nome, zona, secao);
    }

    arquivo.close();

    std::cout << "Lendo prefeitos..." << std::endl;
    arquivo.open("geradores/prefeito.txt");

    if (!arquivo.is_open()){
        std::cerr << "Erro ao abrir arquivo de prefeitos!" << std::endl;
        return;
    }

    std::string partido, cidade, numero;

    while(getline(arquivo, linha)){
        std::stringstream ss(linha);
        getline(ss, titulo, ',');
        getline(ss, nome, ',');
        getline(ss, zona, ',');
        getline(ss, secao, ',');
        getline(ss, partido, ',');
        getline(ss, cidade, ',');
        getline(ss, numero, '\n');

        criarPrefeito(titulo, nome, zona, secao, partido, cidade, numero);
    }

    arquivo.close();

    std::cout << "Lendo vereadores..." << std::endl;
    arquivo.open("geradores/vereador.txt");

    if (!arquivo.is_open()){
        std::cerr << "Erro ao abrir arquivo de vereadores!" << std::endl;
        return;
    }

    while(getline(arquivo, linha)){
        std::stringstream ss(linha);
        getline(ss, titulo, ',');
        getline(ss, nome, ',');
        getline(ss, zona, ',');
        getline(ss, secao, ',');
        getline(ss, partido, ',');
        getline(ss, cidade, ',');
        getline(ss, numero, '\n');

        criarVereador(titulo, nome, zona, secao, partido, cidade, numero);
    }

    arquivo.close();
}
