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
