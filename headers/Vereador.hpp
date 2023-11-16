﻿#ifndef VEREADOR_HPP
#define VEREADOR_HPP
#include "../headers/Eleitor.hpp"
#include <bits/stdc++.h>

class Vereador : public Eleitor
{
    private:
        std::string partido, numero, cidade;

    public:
        Vereador(Eleitor eleitor, std::string partido, std::string cidade , std::string numero);
        ~Vereador();
        std::string getCidade();
        std::string getPartido();
        std::string getNumero();
        void setPartido(std::string partido);
        void setCidade(std::string cidade);
        void setNumero(std::string numero);
        static bool validarVereadorEmEleitor(std::string titulo);
        static void lerVereador(std::vector<Vereador> *vereadores);
        void display();
};
#endif