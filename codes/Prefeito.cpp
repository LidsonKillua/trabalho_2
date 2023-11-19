#include "../headers/Prefeito.hpp"

Prefeito::Prefeito(Eleitor eleitor, std::string partido, std::string cidade, std::string numero) : 
    Eleitor(eleitor), partido(partido), cidade(cidade), numero(numero)
{
}

Prefeito::~Prefeito()
{
}

std::string Prefeito::getPartido()
{
    return this->partido;
}

void Prefeito::setPartido(std::string partido)
{
    this->partido = partido;
}

std::string Prefeito::getCidade()
{
    return this->cidade;
}

std::string Prefeito::getNumero()
{
    return this->numero;
}

void Prefeito::setCidade(std::string cidade)
{
    this->cidade = cidade;
}

bool Prefeito::IsPrefeitoCadastrado(std::string titulo)
{
    for (int i = 0; i < eleitoresValidos->size(); i++)
        if (Prefeito::prefeitos->at(i).getTitulo() == titulo)
            return true; // prefeito cadastrado retorna true

    return false;
}

void Prefeito::display()
{
    std::cout << "Prefeito" << std::endl;
    std::cout << "Titulo: " << this->getTitulo() << std::endl;
    std::cout << "Nome: " << this->getNome() << std::endl;
    std::cout << "Zona: " << this->getZona() << std::endl;
    std::cout << "Secao: " << this->getSecao() << std::endl;
    std::cout << "Cidade: " << this->getCidade() << std::endl;
    std::cout << "Partido: " << this->getPartido() << std::endl;
    std::cout << "Numero: " << this->numero << std::endl;
}