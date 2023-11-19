#ifndef PREFEITO_HPP
#define PREFEITO_HPP
#include <bits/stdc++.h>
#include "../headers/Eleitor.hpp"

class Prefeito : public Eleitor
{
    private:
        std::string partido, numero, cidade;

    public:
        Prefeito(Eleitor eleitor, std::string partido, std::string cidade, std::string numero);
        ~Prefeito();
        std::string getCidade();
        std::string getPartido();
        std::string getNumero();
        void setPartido(std::string partido);
        void setCidade(std::string cidade);
        void display();
};

#endif