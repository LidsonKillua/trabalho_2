#include "../headers/Tribunal.hpp"

Tribunal::Tribunal()
{
}

Tribunal::~Tribunal()
{
}

boolean Tribunal::IsEleitor(std::string titulo){
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
    std::cout << "Eleitor não encontrado!" << std::endl;
}

boolean Tribunal::IsPrefeito(std::string titulo){
    for(auto prefeito : prefeitos){
        if(prefeito.getTitulo() == titulo){
            return true;
        }
    }
    return false;
}

boolean Tribunal::IsVereador(std::string titulo){
    for(auto vereador : vereadores){
        if(vereador.getTitulo() == titulo){
            return true;
        }
    }
    return false;
}

Tribunal::criarEleitor(const std::string titulo, const std::string nome, const std::string zona, const std::string secao){
    if(IsEleitor(titulo)){
        std::cerr << "Eleitor já cadastrado!" << std::endl;
        return;
    }
    eleitores.push_back(Eleitor(titulo, nome, zona, secao));
}

Tribunal::lerEleitor(std::string titulo){
    for(auto eleitor : eleitores){
        if(eleitor.getTitulo() == titulo){
            eleitor.display();
            return;
        }
    }
    std::cout << "Eleitor não encontrado!" << std::endl;
}

Tribunal::atualizarEleitor(const std::string titulo, const std::string nome, const std::string zona, const std::string secao){
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

Tribunal::deletarEleitor(std::string titulo){
    for(auto eleitor : eleitores){
        if(eleitor.getTitulo() == titulo){
            eleitores.erase(eleitor);
            return;
        }
    }
    std::cout << "Eleitor não encontrado!" << std::endl;
}

Tribunal::criarPrefeito(const std::string titulo, const std::string nome, const std::string zona, 
    const std::string secao, const std::string partido, const std::string cidade, const std::string numero)
{
    // Se já existir um eleitor com o título, criar um prefeito e associar a ele
    if(IsEleitor(titulo)){
        prefeitos.push_back(Prefeito(getEleitor(titulo), partido, cidade, numero));
        return;
    }   
    else{
        // Se não existir, criar um eleitor e um prefeito
        prefeitos.push_back(Prefeito(Eleitor(titulo, nome, zona, secao), partido, cidade, numero));
    }
}

Tribunal::criarPrefeito(const Eleitor& eleitor, const std::string partido, const std::string cidade, const std::string numero){
    if(IsEleitor(eleitor.getTitulo())){
        prefeitos.push_back(Prefeito(eleitor, partido, cidade, numero));
        return;
    }
    else{
        std::cerr << "Eleitor não cadastrado!" << std::endl;
        return;
    }
}

Tribunal::lerPrefeito(std::string titulo){
    for(auto prefeito : prefeitos){
        if(prefeito.getTitulo() == titulo){
            prefeito.display();
            return;
        }
    }
    std::cout << "Prefeito não encontrado!" << std::endl;
}

Tribunal::atualizarPrefeito(std::string titulo, const std::string nome, const std::string zona, const std::string secao, const std::string partido, const std::string cidade, const std::string numero){
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

Tribunal::deletarPrefeito(std::string titulo){
    for(auto prefeito : prefeitos){
        if(prefeito.getTitulo() == titulo){
            prefeitos.erase(prefeito);
            return;
        }
    }
    std::cout << "Prefeito não encontrado!" << std::endl;
}

Tribunal::criarVereador(const std::string titulo, const std::string nome, const std::string zona, 
    const std::string secao, const std::string partido, const std::string cidade, const std::string numero)
{
    // Se já existir um eleitor com o título, criar um vereador e associar a ele
    if(IsEleitor(titulo)){
        vereadores.push_back(Vereador(getEleitor(titulo), partido, cidade, numero));
        return;
    }   
    else{
        // Se não existir, criar um eleitor e um vereador
        vereadores.push_back(Vereador(Eleitor(titulo, nome, zona, secao), partido, cidade, numero));
    }
}

Tribunal::criarVereador(const Eleitor& eleitor, const std::string partido, const std::string cidade, const std::string numero){
    if(IsEleitor(eleitor.getTitulo())){
        vereadores.push_back(Vereador(eleitor, partido, cidade, numero));
        return;
    }
    else{
        std::cerr << "Eleitor não cadastrado!" << std::endl;
        return;
    }
}

Tribunal::lerVereador(std::string titulo){
    for(auto vereador : vereadores){
        if(vereador.getTitulo() == titulo){
            vereador.display();
            return;
        }
    }
    std::cout << "Vereador não encontrado!" << std::endl;
}

Tribunal::atualizarVereador(std::string titulo, const std::string nome, const std::string zona, const std::string secao, const std::string partido, const std::string cidade, const std::string numero){
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

Tribunal::deletarVereador(std::string titulo){
    for(auto vereador : vereadores){
        if(vereador.getTitulo() == titulo){
            vereadores.erase(vereador);
            return;
        }
    }
    std::cout << "Vereador não encontrado!" << std::endl;
}

Tribunal::realizarEleicao(){
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

Tribunal::votarPrefeito(){
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
    std::cout << "Digite o titulo do prefeito em que quer votar: ";
    std::cin >> numero;

    for(auto prefeito : prefeitos){
        if(prefeito.gettitulo() == numero){
            prefeito.setVotos(prefeito.getVotos() + 1);
            getEleitor(titulo).setJaVotouPrefeito(true);
            return;
        }
    }
    std::cout << "Prefeito não encontrado!" << std::endl;
}

Tribunal::votarVereador(){
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
    std::cout << "Digite o titulo do vereador em que quer votar: ";
    std::cin >> numero;

    for(auto vereador : vereadores){
        if(vereador.gettitulo() == numero){
            vereador.setVotos(vereador.getVotos() + 1);
            getEleitor(titulo).setJaVotouVereador(true);
            return;
        }
    }
    std::cout << "Vereador não encontrado!" << std::endl;
}

Tribunal::relatorioEleicao(){
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
        std::cout << prefeito.getNome() << " - " << prefeito.getVotos() << " votos" << std::endl;
        qtd--;
    }

    std::cout << "15 Vereadores mais votados:" << std::endl;

    // Ordenar vereadores por votos
    std::sort(vereador.begin(), vereador.end(), [](Vereador a, Vereador b){
        return a.getVotos() > b.getVotos();
    });

    qtd = 15;

    for(auto vereador : vereadores){
        if(qtd == 0){
            break;
        }
        std::cout << vereador.getNome() << " - " << vereador.getVotos() << " votos" << std::endl;
        qtd--;
    }

    std::cout << "---" << std::endl;   
}

Tribunal::finalizarEleicao(){
    std::cout << "Finalizando eleição..." << std::endl;
    std::cout << "Contabilizando votos..." << std::endl;

    relatorioEleicao();

    std::cout << "O prefeito eleito é: " << prefeitos[0].getNome() << std::endl;

    std::cout << "Os 10 vereadores eleitos são: " << std::endl;
    qtd = 10;

    for(auto vereador : vereadores){
        if(qtd == 0){
            break;
        }
        std::cout << vereador.getNome() << std::endl;
        qtd--;
    }    
}