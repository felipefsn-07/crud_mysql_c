#ifndef USUARIODAO_H
#define USUARIODAO_H
#include "Usuario.h"

class UsuarioDAO
{

private:
    Usuario usuario;
    string mensagem;
    int quantidadeUsuarios;
    string *colunas;
    string table;
public:
    UsuarioDAO();
    ~UsuarioDAO();
    int getQuantidadeUsuarios();
    string getMensagem();
    string *buscarUsuarios(string condicao, string tipo, string *colunas, int tamanhoColuna);
    bool insereUsuario(Usuario usuario);
    bool alterarUsuario(Usuario usuario);
    bool desativarUsuario(Usuario usuario);
    bool deletarUsuario(Usuario usuario);

};

#endif // USUARIOCRUD_H
