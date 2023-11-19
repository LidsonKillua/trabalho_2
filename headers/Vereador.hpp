#ifndef VEREADOR_HPP
#define VEREADOR_HPP

#include "Eleitor.hpp"

class Vereador : public Eleitor
{
    private:
        std::string partido, numero, cidade;
        int votos;
        void setVotos(int votos);

    public:
        Vereador(Eleitor eleitor, std::string partido, std::string cidade , std::string numero);
        ~Vereador();
        std::string getCidade();
        std::string getPartido();
        std::string getNumero();
        int getVotos();

        void setPartido(std::string partido);
        void setCidade(std::string cidade);
        void setNumero(std::string numero);

        void ReceberVoto();
        void display();
};

#endif