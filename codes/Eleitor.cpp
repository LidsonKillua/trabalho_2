#include "../headers/Eleitor.hpp"

std::vector<Eleitor> *eleitoresValidos = new std::vector<Eleitor>;

Eleitor::Eleitor(std::string titulo, std::string nome, std::string zona, std::string secao)
{
    this->titulo = titulo;
    this->nome = nome;
    this->zona = zona;
    this->secao = secao;

}

Eleitor::~Eleitor()
{
}

std::string Eleitor::getTitulo()
{
    return this->titulo;
}

std::string Eleitor::getNome()
{
    return this->nome;
}

std::string Eleitor::getZona()
{
    return this->zona;
}

std::string Eleitor::getSecao()
{
    return this->secao;
}

void Eleitor::setTitulo(std::string titulo)
{
    this->titulo = titulo;
}

void Eleitor::setNome(std::string nome)
{
    this->nome = nome;
}

void Eleitor::setZona(std::string zona)
{
    this->zona = zona;
}

void Eleitor::setSecao(std::string secao)
{
    this->secao = secao;
}

void Eleitor::lerEleitor(std::vector<Eleitor> *eleitores)
{
    std::string titulo, nome, zona, secao;

    for (int i = 0; i < 2000; i++)
    {
        std::cout << "Digite o titulo, nome, zona e secao do eleitor separados por virgula: " << std::endl;
        std::getline(std::cin, titulo, ',');
        std::getline(std::cin, nome, ',');
        std::getline(std::cin, zona, ',');
        std::getline(std::cin, secao, '\n');

        if (eleitores->size() == 0)
        {
            eleitores->push_back(Eleitor(titulo, nome, zona, secao));
            eleitoresValidos->push_back(Eleitor(titulo, nome, zona, secao));
        }
        else
        {            
            if (validarEleitor(titulo))
            {
                std::cout << "Eleitor já cadastrado!" << std::endl;
            }
            else
            {
                eleitores->push_back(Eleitor(titulo, nome, zona, secao));
                eleitoresValidos->push_back(Eleitor(titulo, nome, zona, secao));
            }
        }
    }
}

bool validarEleitor(std::string titulo)
{

    for (int i = 0; i < eleitoresValidos->size(); i++)    
        if (eleitoresValidos->at(i).getTitulo() == titulo)
            return true; // eleitor cadastrado retorna true

    return false;
}

void Eleitor::display()
{
    std::cout << "Titulo: " << this->titulo << std::endl;
    std::cout << "Nome: " << this->nome << std::endl;
    std::cout << "Zona: " << this->zona << std::endl;
    std::cout << "Secao: " << this->secao << std::endl;
}

/*void Eleitor::votar(std::vector<Eleitor> *eleitoresValidos, std::vector<Prefeito> *prefeitos,
                     std::vector<Vereador> *vereadores, std::map<std::string,
                      int> *votosPrefeitos, std::map<std::string, int> *votosVereadores)
{
    std::string titulo;
    std::cout << "Digite o titulo do eleitor: ";
    std::cin >> titulo;

    if (validarEleitor(eleitores, titulo))
    {
        std::cout << "Eleitor cadastrado!" << std::endl;
        std::cout << "Digite o numero do candidato a prefeito: ";
        std::string numeroPrefeito;
        std::cin >> numeroPrefeito;

        for (int i = 0; i < prefeitos->size(); i++)
        {
            if (prefeitos->at(i).getNumero() == numeroPrefeito)
            {
                std::cout << "Candidato a prefeito cadastrado!" << std::endl;
                std::cout << "Digite o numero do candidato a vereador: ";
                std::string numeroVereador;
                std::cin >> numeroVereador;

                for (int i = 0; i < vereadores->size(); i++)
                {
                    if (vereadores->at(i).getNumero() == numeroVereador && vereadores->at(i).getZona() == prefeitos->at(i).getZona())
                    {
                        std::cout << "Candidato a vereador cadastrado!" << std::endl;
                        std::cout << "Voto computado!" << std::endl;
                        votosPrefeitos->insert(std::pair<std::string, int>(numeroPrefeito, 1));
                        votosVereadores->insert(std::pair<std::string, int>(numeroVereador, 1));
                        break;
                    }
                    else
                    {
                        std::cout << "Candidato a vereador não cadastrado!" << std::endl;
                        break;
                    }
                }
                break;
            }
            else
            {
                std::cout << "Candidato a prefeito não cadastrado!" << std::endl;
                break;
            }
        }
    }
    else
    {
        std::cout << "Eleitor não cadastrado!" << std::endl;
    }
}*/

