#ifndef PREFEITO_HPP
#define PREFEITO_HPP

#include "Eleitor.hpp"

class Prefeito : public Eleitor
{
    private:
        std::string partido, numero, cidade;
        int votos = 0;

        void setVotos(int votos);

    public:
        Prefeito(Eleitor eleitor, std::string partido, std::string cidade, std::string numero);
        ~Prefeito();
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