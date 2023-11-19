#ifndef ELEITOR_HPP
#define ELEITOR_HPP

#include <string>
#include <iostream>

class Eleitor
{
    private:
        std::string nome, titulo, zona, secao;
        bool JaVotouPrefeito;
        bool JaVotouVereador;

    public:
        Eleitor(std::string titulo, std::string nome, std::string zona, std::string secao);
        ~Eleitor();

        std::string getTitulo();
        std::string getNome();
        std::string getZona();
        std::string getSecao();
        bool IsJaVotouPrefeito();
        bool IsJaVotouVereador();

        void setTitulo(std::string titulo);
        void setNome(std::string nome);
        void setZona(std::string zona);
        void setSecao(std::string secao);
        void setJaVotouPrefeito(bool votou);
        void setJaVotouVereador(bool votou);

        virtual void display();
};

#endif
