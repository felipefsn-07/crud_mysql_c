#include <iostream>
#include <string>
#include "UsuarioDAO.h"
#include "Usuario.h"

using namespace std;

int main(){
    UsuarioDAO crud;
    Usuario user[2];
    user[0].setCod_usuario("1");
    user[0].setNome("Felipe Silva");
    user[0].setStatus("true");
    user[1].setCod_usuario("2");
    user[1].setNome("Maria");
    user[1].setStatus("true");

    //Inserindo as colunas que serão imprimidas na tela
    string colunas[2];
    colunas[0] = "cod_usuario";
    colunas[1] = "nome";
    //Condicao para busca
    string condicao = "ORDER BY nome ASC";

    //Inserir usuario
    for (int i = 0; i<2;i++){
            if (crud.insereUsuario(user[i])){
                cout << "Inserido com sucesso"<<endl;
            }else{
                cout << crud.getMensagem() << endl;
            }
    }

    //Buscar todos os dados da tabela usuario

    int tamanhoColuna = 2;
    int quantidadeUsuarios = crud.getQuantidadeUsuarios();
    string *resultado = new string[quantidadeUsuarios*tamanhoColuna];
    resultado = crud.buscarUsuarios(condicao, "all", colunas, quantidadeUsuarios);
    for (int i = 0; i<quantidadeUsuarios*tamanhoColuna;i+=tamanhoColuna){
        cout <<resultado[i] <<"      "<<resultado[i+1]<<endl;
    }

    //Alterar usuario
     user[0].setNome("Felipe");
    if (crud.alterarUsuario(user[0])){
        cout << "Alterado com sucesso"<<endl;
    }else{
        cout << crud.getMensagem() << endl;
    }

    //Buscar com condicao e apenas um usuario
    condicao = "cod_usuario = " + user[0].getCod_usuario();
    string *resultadoSingle = new string[tamanhoColuna];
    resultadoSingle  = crud.buscarUsuarios(condicao, "single", colunas, quantidadeUsuarios);
    cout <<resultadoSingle[0] <<"      "<<resultadoSingle[1]<<endl;

    //deletar usuario
    for (int i = 0; i<2;i++){
            if (crud.deletarUsuario(user[i])){
                cout << "Deletado com sucesso"<<endl;
            }else{
                cout << crud.getMensagem() << endl;
            }
    }




    return 0;
}
