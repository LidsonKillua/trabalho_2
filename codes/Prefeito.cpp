#include "../headers/Prefeito.hpp"

Prefeito::Prefeito(Eleitor eleitor, std::string partido, std::string cidade, std::string numero) : Eleitor(eleitor.getTitulo(), eleitor.getNome(), eleitor.getZona(), eleitor.getSecao())
{
    this->partido = partido;
    this->numero = numero;
    this->cidade = cidade;
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

void Prefeito::lerPrefeito(std::vector<Prefeito> *prefeitos)
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Digite o titulo, nome, zona, seção, partido, cidade e numero do candidato " << std::endl;
        std::string titulo, nome, zona, secao, partido, cidade, numero;
        std::getline(std::cin, titulo, ',');
        std::getline(std::cin, nome, ',');
        std::getline(std::cin, zona, ',');
        std::getline(std::cin, secao, ',');
        std::getline(std::cin, partido, ',');
        std::getline(std::cin, cidade, ',');
        std::getline(std::cin, numero, '\n');

        if (prefeitos->size() == 0)
        {
            prefeitos->push_back(Prefeito(Eleitor(titulo, nome, zona, secao), partido, cidade, numero));
            if(!validarPrefeitoEmEleitor(titulo)) Eleitor::eleitoresValidos->push_back(Eleitor(titulo, nome, zona, secao));
        }
        else
        {
            for (int i = 0; i < prefeitos->size(); i++)
            {
                if (prefeitos->at(i).getTitulo() == titulo)
                {
                    std::cout << "Prefeito já cadastrado!" << std::endl;
                    break;
                }
                else
                {
                    prefeitos->push_back(Prefeito(Eleitor(titulo, nome, zona, secao), partido, cidade, numero));
                    Eleitor::eleitoresValidos->push_back(Eleitor(titulo, nome, zona, secao));
                    break;
                }
            }
        }
    }

}

bool validarPrefeitoEmEleitor(std::string titulo)
{

    for (int i = 0; i < Eleitor::eleitoresValidos->size(); i++)
        if (Eleitor::eleitoresValidos->at(i).getTitulo() == titulo)
            return true; // eleitor cadastrado retorna true

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