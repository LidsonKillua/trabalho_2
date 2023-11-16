#include "../headers/Vereador.hpp"

Vereador::Vereador(Eleitor eleitor, std::string partido, std::string cidade, std::string numero) : Eleitor(eleitor.getTitulo(), eleitor.getNome(), eleitor.getZona(), eleitor.getSecao())
{
    this->partido = partido;
    this->numero = numero;
    this->cidade = cidade;
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

void Vereador::lerVereador(std::vector<Vereador> *vereadores)
{
    for (int i = 0; i < 70; i++)
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

        if (vereadores->size() == 0)
        {
            vereadores->push_back(Vereador(Eleitor(titulo, nome, zona, secao), partido, cidade, numero));
            if (!validarVereadorEmEleitor(titulo)) Eleitor::eleitoresValidos->push_back(Eleitor(titulo, nome, zona, secao));
        }
        else
        {
            for (int i = 0; i < vereadores->size(); i++)
            {
                if (vereadores->at(i).getTitulo() == titulo)
                {
                    std::cout << "Vereador já cadastrado!" << std::endl;
                    break;
                }
                else
                {
                    vereadores->push_back(Vereador(Eleitor(titulo, nome, zona, secao), partido, cidade, numero));
                    if (!validarVereadorEmEleitor(titulo)) Eleitor::eleitoresValidos->push_back(Eleitor(titulo, nome, zona, secao));
                    break;
                }
            }
        }
    }
}

bool validarVereadorEmEleitor(std::string titulo)
{

    for (int i = 0; i < Eleitor::eleitoresValidos->size(); i++)
    {
        if (Eleitor::eleitoresValidos->at(i).getTitulo() == titulo)
        {
            return true; // eleitor cadastrado retorna true
        }
        else
        {
            continue;
        }
    }
    return false;
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