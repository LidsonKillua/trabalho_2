#ifndef ELEITOR_HPP
#define ELEITOR_HPP

#include <bits/stdc++.h>

class Eleitor
{
    private:
        std::string nome, titulo, zona, secao;

    public:
        Eleitor(std::string titulo, std::string nome, std::string zona, std::string secao);
        ~Eleitor();
        static std::vector<Eleitor> *eleitoresValidos;
        std::string getTitulo();
        std::string getNome();
        std::string getZona();
        std::string getSecao();
        void setTitulo(std::string titulo);
        void setNome(std::string nome);
        void setZona(std::string zona);
        void setSecao(std::string secao);
        static bool validarEleitor(std::string titulo);
        static void lerEleitor(std::vector<Eleitor> *eleitores);
        virtual void display();
};

#endif
