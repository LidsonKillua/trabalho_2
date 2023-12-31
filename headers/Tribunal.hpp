#ifndef TRIBUNAL_HPP
#define TRIBUNAL_HPP 

#include <vector>
#include "Prefeito.hpp"
#include "Vereador.hpp"
#include "Eleitor.hpp"

class Tribunal {
private:
    std::vector<Prefeito*> prefeitos;
    std::vector<Vereador*> vereadores;
    std::vector<Eleitor*> eleitores;

    // Métodos auxiliares
    bool IsEleitor(std::string titulo);
    Eleitor* getEleitor(std::string titulo);
    bool IsPrefeito(std::string titulo);
    bool IsVereador(std::string titulo);

    // Métodos para realizar a eleição
    void votarPrefeito();
    void votarVereador();
    void relatorioEleicao();
    void finalizarEleicao();

    // Métodos de CRUD para eleitores
    void criarEleitor(const std::string titulo, const std::string nome, const std::string zona, const std::string secao);
    void lerEleitor(std::string titulo);
    void atualizarEleitor(const std::string titulo, const std::string nome, const std::string zona, const std::string secao);
    void deletarEleitor(std::string titulo);
    void listarEleitores();
    void listarEleitoresNaoCandidatos();

    // Métodos de CRUD para prefeitos
    void criarPrefeito(const std::string titulo, const std::string nome, const std::string zona, 
        const std::string secao, const std::string partido, const std::string cidade, const std::string numero);
    void criarPrefeito(Eleitor* eleitor, const std::string partido, const std::string cidade, const std::string numero);
    void lerPrefeito(std::string titulo);
    void atualizarPrefeito(std::string titulo, const std::string nome, const std::string zona, const std::string secao, const std::string partido, const std::string cidade, const std::string numero);
    void deletarPrefeito(std::string titulo);
    void listarPrefeitos();

    // Métodos de CRUD para vereadores
    void criarVereador(const std::string titulo, const std::string nome, const std::string zona, 
        const std::string secao, const std::string partido, const std::string cidade, const std::string numero);
    void criarVereador(Eleitor* eleitor, const std::string partido, const std::string cidade, const std::string numero);
    void lerVereador(std::string titulo);
    void atualizarVereador(std::string titulo, const std::string nome, const std::string zona, const std::string secao, const std::string partido, const std::string cidade, const std::string numero);
    void deletarVereador(std::string titulo);
    void listarVereadores();
    void EleicaoAutomatica();

public:
    Tribunal();
    ~Tribunal();

    // Métodos para o menu
    void CadastroEleitor();
    void CadastroPrefeito();
    void CadastroVereador();

    // Métodos para testes
    void LerVarios();
    void listarTodos();

    // Método para realizar a eleição
    void realizarEleicao();
};

#endif
