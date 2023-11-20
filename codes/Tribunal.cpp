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
    // Deletando eleitores, prefeitos e vereadores
    for(int i = 0; i < eleitores.size(); i++){
        delete eleitores[i];
    }
    for(int i = 0; i < prefeitos.size(); i++){
        delete prefeitos[i];
    }
    for(int i = 0; i < vereadores.size(); i++){
        delete vereadores[i];
    }
}

bool Tribunal::IsEleitor(std::string titulo){
    for(int i = 0; i < eleitores.size(); i++){
        if(eleitores[i]->getTitulo() == titulo){
            return true;
        }
    }
    return false;
}

Eleitor* Tribunal::getEleitor(std::string titulo){
    for(int i = 0; i < eleitores.size(); i++){
        if(eleitores[i]->getTitulo() == titulo){
            return eleitores[i];
        }
    }
    std::cout << "Eleitor não encontrado e criado" << std::endl;
    criarEleitor(titulo, "", "", "");
    return getEleitor(titulo);
}

bool Tribunal::IsPrefeito(std::string titulo){
    for(int i = 0; i < prefeitos.size(); i++){
        if(prefeitos[i]->getTitulo() == titulo){
            return true;
        }
    }
    return false;
}

bool Tribunal::IsVereador(std::string titulo){
    for(int i = 0; i < vereadores.size(); i++){
        if(vereadores[i]->getTitulo() == titulo){
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
    Eleitor* eleitor = new Eleitor(titulo, nome, zona, secao);
    eleitores.push_back(eleitor);
}

void Tribunal::lerEleitor(std::string titulo){
    for(int i = 0; i < eleitores.size(); i++){
        if(eleitores[i]->getTitulo() == titulo){
            eleitores[i]->display();
            return;
        }
    }
    std::cout << "Eleitor não encontrado!" << std::endl;
}

void Tribunal::atualizarEleitor(const std::string titulo, const std::string nome, const std::string zona, const std::string secao){
    for(int i = 0; i < eleitores.size(); i++){
        if(eleitores[i]->getTitulo() == titulo){
            eleitores[i]->setNome(nome);
            eleitores[i]->setZona(zona);
            eleitores[i]->setSecao(secao);
            return;
        }
    }
    std::cout << "Eleitor não encontrado!" << std::endl;
}

void Tribunal::deletarEleitor(std::string titulo){
    for(int i = 0; i < eleitores.size(); i++){
        if(eleitores[i]->getTitulo() == titulo){
            delete eleitores[i];
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
        Prefeito* prefeito = new Prefeito(getEleitor(titulo), partido, cidade, numero);
        prefeitos.push_back(prefeito);
        return;
    }   
    else{
        // Se não existir, criar um eleitor e um prefeito
        Eleitor* eleitor = new Eleitor(titulo, nome, zona, secao);
        Prefeito* prefeito = new Prefeito(eleitor, partido, cidade, numero);
        eleitores.push_back(eleitor);
        prefeitos.push_back(prefeito);
    }
}

void Tribunal::criarPrefeito(Eleitor* eleitor, const std::string partido, const std::string cidade, const std::string numero){
    Prefeito* prefeito = new Prefeito(eleitor, partido, cidade, numero);
    prefeitos.push_back(prefeito);
}

void Tribunal::lerPrefeito(std::string titulo){
    for(int i = 0; i < prefeitos.size(); i++){
        if(prefeitos[i]->getTitulo() == titulo){
            prefeitos[i]->display();
            return;
        }
    }
    std::cout << "Prefeito não encontrado!" << std::endl;
}

void Tribunal::atualizarPrefeito(std::string titulo, const std::string nome, const std::string zona, const std::string secao, const std::string partido, const std::string cidade, const std::string numero){
    for(int i = 0; i < prefeitos.size(); i++){
        if(prefeitos[i]->getTitulo() == titulo){
            prefeitos[i]->setNome(nome);
            prefeitos[i]->setZona(zona);
            prefeitos[i]->setSecao(secao);
            prefeitos[i]->setPartido(partido);
            prefeitos[i]->setCidade(cidade);
            prefeitos[i]->setNumero(numero);
            return;
        }
    }
    std::cout << "Prefeito não encontrado!" << std::endl;
}

void Tribunal::deletarPrefeito(std::string titulo){
    for(int i = 0; i < prefeitos.size(); i++){
        if(prefeitos[i]->getTitulo() == titulo){
            delete prefeitos[i];
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
        Vereador* vereador = new Vereador(getEleitor(titulo), partido, cidade, numero);
        vereadores.push_back(vereador);
        return;
    }   
    else{
        // Se não existir, criar um eleitor e um vereador
        Eleitor* eleitor = new Eleitor(titulo, nome, zona, secao);
        Vereador* vereador = new Vereador(eleitor, partido, cidade, numero);
        eleitores.push_back(eleitor);
        vereadores.push_back(vereador);
    }
}

void Tribunal::criarVereador(Eleitor* eleitor, const std::string partido, const std::string cidade, const std::string numero){
    Vereador* vereador = new Vereador(eleitor, partido, cidade, numero);
    vereadores.push_back(vereador);
}

void Tribunal::lerVereador(std::string titulo){
    for(int i = 0; i < vereadores.size(); i++){
        if(vereadores[i]->getTitulo() == titulo){
            vereadores[i]->display();
            return;
        }
    }
    std::cout << "Vereador não encontrado!" << std::endl;
}

void Tribunal::atualizarVereador(std::string titulo, const std::string nome, const std::string zona, const std::string secao, const std::string partido, const std::string cidade, const std::string numero){
    for(int i = 0; i < vereadores.size(); i++){
        if(vereadores[i]->getTitulo() == titulo){
            vereadores[i]->setNome(nome);
            vereadores[i]->setZona(zona);
            vereadores[i]->setSecao(secao);
            vereadores[i]->setPartido(partido);
            vereadores[i]->setCidade(cidade);
            vereadores[i]->setNumero(numero);
            return;
        }
    }
    std::cout << "Vereador não encontrado!" << std::endl;
}

void Tribunal::deletarVereador(std::string titulo){
    for(int i = 0; i < vereadores.size(); i++){
        if(vereadores[i]->getTitulo() == titulo){
            delete vereadores[i];
            vereadores.erase(vereadores.begin() + i);
            return;
        }
    }
    std::cout << "Vereador não encontrado!" << std::endl;
}

void Tribunal::votarPrefeito(){
    std::string titulo;
    std::cout << "Digite o título do eleitor: ";
    std::cin >> titulo;

    if(!IsEleitor(titulo)){
        std::cerr << "Eleitor não cadastrado!" << std::endl;
        return;
    }
    else if(getEleitor(titulo)->IsJaVotouPrefeito()){
        std::cerr << "Este eleitor já votou para prefeito!" << std::endl;
        return;
    }

    std::string numero;
    std::cout << "Digite o numero do prefeito em que quer votar: ";
    std::cin >> numero;

    for(int i = 0; i < prefeitos.size(); i++){
        if(prefeitos[i]->getNumero() == numero){
            prefeitos[i]->ReceberVoto();
            getEleitor(titulo)->setJaVotouPrefeito(true);
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
    else if(getEleitor(titulo)->IsJaVotouVereador()){
        std::cerr << "Este eleitor já votou para vereador!" << std::endl;
        return;
    }

    std::string numero;
    std::cout << "Digite o numero do vereador em que quer votar: ";
    std::cin >> numero;

    for(int i = 0; i < vereadores.size(); i++){
        if(vereadores[i]->getNumero() == numero){
            vereadores[i]->ReceberVoto();
            getEleitor(titulo)->setJaVotouVereador(true);
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
    std::sort(prefeitos.begin(), prefeitos.end(), [](Prefeito* a, Prefeito* b){
        return a->getVotos() > b->getVotos();
    });

    for(int i = 0; i < prefeitos.size(); i++){
        if(qtd == 0){
            break;
        }
        std::cout << prefeitos[i]->getNumero() << " - " << prefeitos[i]->getNome() << " - " << prefeitos[i]->getVotos() << " votos" << std::endl;
        qtd--;
    }

    std::cout << "15 Vereadores mais votados:" << std::endl;

    // Ordenar vereadores por votos
    std::sort(vereadores.begin(), vereadores.end(), [](Vereador* a, Vereador* b){
        return a->getVotos() > b->getVotos();
    });

    qtd = 15;

    for(int i = 0; i < vereadores.size(); i++){
        if(qtd == 0){
            break;
        }
        std::cout << vereadores[i]->getNumero() << " - " << vereadores[i]->getNome() << " - " << vereadores[i]->getVotos() << " votos" << std::endl;
        qtd--;
    }

    std::cout << "---" << std::endl;   
}

void Tribunal::finalizarEleicao(){
    std::cout << "Finalizando eleição..." << std::endl;
    std::cout << "Contabilizando votos..." << std::endl;

    relatorioEleicao();

    // Ordenar prefeitos por votos
    std::sort(prefeitos.begin(), prefeitos.end(), [](Prefeito* a, Prefeito* b){
        return a->getVotos() > b->getVotos();
    });

    std::cout << "\nO prefeito eleito é: " << prefeitos[0]->getNome() << " com " << prefeitos[0]->getVotos() << " votos." << std::endl;

    std::cout << "Os 10 vereadores eleitos são: \n" << std::endl;
    int qtd = 10;

    // Ordenar vereadores por votos
    std::sort(vereadores.begin(), vereadores.end(), [](Vereador* a, Vereador* b){
        return a->getVotos() > b->getVotos();
    });

    for(int i = 0; i < vereadores.size(); i++){
        if(qtd == 0){
            break;
        }
        std::cout << vereadores[i]->getNome() << " com " << vereadores[i]->getVotos() << " votos." << std::endl;
        qtd--;
    }    
    std::cout << std::endl;
}

void Tribunal::listarEleitores(){
    std::cout << "Eleitores cadastrados:" << std::endl;

    for(int i = 0; i < eleitores.size(); i++){
        eleitores[i]->display();
    }
}

void Tribunal::listarEleitoresNaoCandidatos(){
    std::cout << "Eleitores não candidatos cadastrados:" << std::endl;

    for(int i = 0; i < eleitores.size(); i++){
        if(!IsPrefeito(eleitores[i]->getTitulo()) && !IsVereador(eleitores[i]->getTitulo())){
            eleitores[i]->display();
        }
    }
}

void Tribunal::listarPrefeitos(){
    std::cout << "Candidatos a Prefeito cadastrados:" << std::endl;

    for(int i = 0; i < prefeitos.size(); i++){
        prefeitos[i]->display();
    }
}

void Tribunal::listarVereadores(){
    std::cout << "Candidatos a Vereador cadastrados:" << std::endl;

    for(int i = 0; i < vereadores.size(); i++){
        vereadores[i]->display();
    }
}

void Tribunal::listarTodos(){
    listarPrefeitos();
    listarVereadores();
    listarEleitoresNaoCandidatos();
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
        std::cout << "\nEscolha uma opção:" << std::endl;
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
        std::cout << "\nEscolha uma opção:" << std::endl;
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

void Tribunal::EleicaoAutomatica(){
    std::cout << "Iniciando eleição automática..." << std::endl;
    std::cout << "Lendo votos para prefeito..." << std::endl;

    std::ifstream arquivo("geradores/votosPrefeito.txt");
    if (!arquivo.is_open()){
        std::cerr << "Erro ao abrir arquivo de votos para prefeito!" << std::endl;
        return;
    }

    std::string linha, titulo, numero;

    while(getline(arquivo, linha)){
        std::stringstream ss(linha);
        getline(ss, titulo, ',');
        getline(ss, numero, '\n');

        for(int i = 0; i < prefeitos.size(); i++){
            if(prefeitos[i]->getNumero() == numero){
                prefeitos[i]->ReceberVoto();
                getEleitor(titulo)->setJaVotouPrefeito(true);
                break;
            }
        }
    }

    arquivo.close();

    std::cout << "Lendo votos para vereador..." << std::endl;

    arquivo.open("geradores/votosVereador.txt");
    if (!arquivo.is_open()){
        std::cerr << "Erro ao abrir arquivo de votos para vereador!" << std::endl;
        return;
    }

    while(getline(arquivo, linha)){
        std::stringstream ss(linha);
        getline(ss, titulo, ',');
        getline(ss, numero, '\n');

        for(int i = 0; i < vereadores.size(); i++){
            if(vereadores[i]->getNumero() == numero){
                vereadores[i]->ReceberVoto();
                getEleitor(titulo)->setJaVotouVereador(true);
                break;
            }
        }
    }

    arquivo.close();
    std::cout << "Finalizando eleição automática..." << std::endl;
}

void Tribunal::realizarEleicao(){
    std::cout << "Iniciando o processo de eleição..." << std::endl;
    int op = 1;

    while (op != 0){
        std::cout << "\nEscolha uma opção:" << std::endl; 
        std::cout << "1 - Votar para prefeito" << std::endl;
        std::cout << "2 - Votar para vereador" << std::endl;
        std::cout << "3 - Verificar mais votados no momento" << std::endl;
        std::cout << "4 - Eleição automática" << std::endl;
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
        case 4:
            EleicaoAutomatica();
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
