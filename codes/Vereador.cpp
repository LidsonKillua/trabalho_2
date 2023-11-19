#include "../headers/Vereador.hpp"

Vereador::Vereador(Eleitor eleitor, std::string partido, std::string cidade, std::string numero) : 
    Eleitor(eleitor.getTitulo(), eleitor.getNome(), eleitor.getZona(), eleitor.getSecao()), partido(partido), 
    cidade(cidade), numero(numero)
{
}

Vereador::~Vereador()
{
}

std::string Vereador::getPartido()
{
    return this->partido;
}

std::string Vereador::getCidade()
{
    return this->cidade;
}

std::string Vereador::getNumero()
{
    return this->numero;
}

void Vereador::setCidade(std::string cidade)
{
    this->cidade = cidade;
}

void Vereador::setPartido(std::string partido)
{
    this->partido = partido;
}

void Vereador::setNumero(std::string numero)
{
    this->numero = numero;
}

void Vereador::display()
{
    std::cout << "Titulo: " << this->getTitulo() << std::endl;
    std::cout << "Nome: " << this->getNome() << std::endl;
    std::cout << "Zona: " << this->getZona() << std::endl;
    std::cout << "Secao: " << this->getSecao() << std::endl;
    std::cout << "Cidade: " << this->getCidade() << std::endl;
    std::cout << "Partido: " << this->getPartido() << std::endl;
    std::cout << "Numero: " << this->numero << std::endl;
}