#include "UsuarioDAO.h"
#include "Usuario.h"
#include "DAO.h"
#include <iostream>

using namespace std;

UsuarioDAO::UsuarioDAO()
{
    DAO crud;
    colunas = new string[3];
    colunas[0] = "cod_usuario";
    colunas[1] = "nome";
    colunas[2] = "status";
    table = "usuarios";
    quantidadeUsuarios = crud.totalDados("", table);
    //ctor
}

UsuarioDAO::~UsuarioDAO()
{
    //dtor
}

string UsuarioDAO::getMensagem(){
    return this->mensagem;
}

int UsuarioDAO::getQuantidadeUsuarios(){
    DAO crud;
    quantidadeUsuarios = crud.totalDados("", table);
    return quantidadeUsuarios;
}

string *UsuarioDAO::buscarUsuarios(string condicao, string tipo, string *colunas, int tamanhoColuna){
    DAO crud;
    int i;
    string* resultado = new string[quantidadeUsuarios*tamanhoColuna];
    for (i = 0; i <quantidadeUsuarios*tamanhoColuna; i++)
       resultado[i] = "NULL";
    if (quantidadeUsuarios>0){
        if (tipo == "all"){

            resultado = crud.lerDados(colunas, condicao, tamanhoColuna, table, "all", quantidadeUsuarios);
            if (resultado[0]!="NULL"){
                    return resultado;
            }

        }else if (tipo == "single"){
            resultado = crud.lerDados(colunas, condicao, tamanhoColuna, table, "single", quantidadeUsuarios);
            if (resultado[0]!="NULL"){
                    return resultado;
            }

        }
    }

    mensagem = crud.getMensagem();
  return resultado;


}


bool UsuarioDAO::alterarUsuario(Usuario usuario){
    DAO crud;
     string values[3];
    values[0] = usuario.getCod_usuario();
    values[1] ="'"+usuario.getNome()+"'";
    values[2] = usuario.getStatus();
    string condicao  = "cod_usuario = "+values[0];
    if (crud.atualizarDados(colunas, table, condicao, values, 3)){
            mensagem = crud.getMensagem();
            return true;
    }
    mensagem = crud.getMensagem();
    return false;


}

bool UsuarioDAO::insereUsuario(Usuario usuario){
    DAO crud;
    string values[3];
    values[0] = usuario.getCod_usuario();
    values[1] ="'"+usuario.getNome()+"'";
    values[2] = usuario.getStatus();

    if (crud.inserirDados(colunas, table, values, 3)){
            mensagem = crud.getMensagem();
            return true;
    }
  mensagem = crud.getMensagem();
  return false;

}

bool UsuarioDAO::deletarUsuario(Usuario usuario){
    DAO crud;

    string condicao  = "cod_usuario = "+usuario.getCod_usuario();
    if (crud.deletar(condicao, table)){
            mensagem = crud.getMensagem();
            return true;
    }
    mensagem = crud.getMensagem();
    return false;
}

