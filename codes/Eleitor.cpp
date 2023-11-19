#include "../headers/Eleitor.hpp"
#include <iostream>

Eleitor::Eleitor(std::string titulo, std::string nome, std::string zona, std::string secao) : 
    titulo(titulo), nome(nome), zona(zona), secao(secao), JaVotouPrefeito(false), JaVotouVereador(false)
{
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

bool Eleitor::IsJaVotouPrefeito()
{
    return this->JaVotouPrefeito;
}

bool Eleitor::IsJaVotouVereador()
{
    return this->JaVotouVereador;
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

void Eleitor::setJaVotouPrefeito(bool votou)
{
    this->JaVotouPrefeito = votou;
}

void Eleitor::setJaVotouVereador(bool votou)
{
    this->JaVotouVereador = votou;
}

void Eleitor::display()
{
    std::cout << "Eleitor" << std::endl;
    std::cout << "Titulo: " << this->titulo << std::endl;
    std::cout << "Nome: " << this->nome << std::endl;
    std::cout << "Zona: " << this->zona << std::endl;
    std::cout << "Secao: " << this->secao << std::endl;
}
