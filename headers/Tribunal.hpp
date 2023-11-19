
#include <vector>
#include "Prefeito.hpp"
#include "Vereador.hpp"
#include "Eleitor.hpp"

class Tribunal {
private:
    std::vector<Prefeito> prefeitos;
    std::vector<Vereador> vereadores;
    std::vector<Eleitor> eleitores;

    boolean IsEleitor(std::string titulo);
    Eleitor getEleitor(std::string titulo);
    boolean IsPrefeito(std::string titulo);
    boolean IsVereador(std::string titulo);

public:
    // Métodos de CRUD para eleitores
    void criarEleitor(const std::string titulo, const std::string nome, const std::string zona, const std::string secao);
    void lerEleitor(std::string titulo);
    void atualizarEleitor(const std::string titulo, const std::string nome, const std::string zona, const std::string secao);
    void deletarEleitor(std::string titulo);

    // Métodos de CRUD para prefeitos
    void criarPrefeito(const std::string titulo, const std::string nome, const std::string zona, 
        const std::string secao, const std::string partido, const std::string cidade, const std::string numero);
    void criarPrefeito(const Eleitor& eleitor, const std::string partido, const std::string cidade, const std::string numero);
    void lerPrefeito(std::string titulo);
    void atualizarPrefeito(std::string titulo, const std::string nome, const std::string zona, const std::string secao, const std::string partido, const std::string cidade, const std::string numero);
    void deletarPrefeito(std::string titulo);

    // Métodos de CRUD para vereadores
    void criarVereador(const std::string titulo, const std::string nome, const std::string zona, 
        const std::string secao, const std::string partido, const std::string cidade, const std::string numero);
    void criarVereador(const Eleitor& eleitor, const std::string partido, const std::string cidade, const std::string numero);
    void lerVereador(std::string titulo);
    void atualizarVereador(std::string titulo, const std::string nome, const std::string zona, const std::string secao, const std::string partido, const std::string cidade, const std::string numero);
    void deletarVereador(std::string titulo);

    // Método para realizar a eleição
    void realizarEleicao();
};
