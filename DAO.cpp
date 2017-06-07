#include "DAO.h"
#include <string>
#include <mysql/mysql.h>
#include <sstream>
#include <iostream>
using namespace std;


DAO::DAO()
{
   this->server = "127.0.0.1";
   this->usuario = "root";
   this->senha = "";
   this->db = "dbSlash";
   mysql_init(&DBCon);
}

DAO::~DAO()
{
    //dtor
}

string DAO::getMensagem(){

    return this->menssagem;
}


bool DAO::conectar(){

 //Conecta com o banco de dados
 if ( mysql_real_connect(&DBCon, this->server, this->usuario, this->senha, this->db, 0, NULL, 0) )
 {
       return true;
  }
  else
  {
    int Number = mysql_errno(&DBCon);
    string Result;
    stringstream convert;

    convert << Number;
    Result = convert.str();
    string erro = Result;
    string msgErro = mysql_error(&DBCon);
    string retornar = ("Erro nº "+ erro +" :"+msgErro +"\n");
    this->menssagem = retornar;
    return false;
  }


}

int DAO::totalDados(string condicao, string table){
 string query = "";
    string colQuery = "";
    MYSQL_ROW dados; //variável que recebe os dados
    int tamanhoDados = 0;
    int i;
    if (this->conectar()){


        query = "SELECT * FROM "+table + condicao;

       // cout << query.c_str() << endl;


        if(mysql_query(&DBCon,query.c_str()))
        {
            int Number = mysql_errno(&DBCon);
            string Result;
            stringstream convert;

            convert << Number;

            Result = convert.str();
            string numErro = Result;
            string msgErro = mysql_error(&DBCon);
            string error;
            error= ("Erro nº "+ numErro +" :"+msgErro);
            this->menssagem = error;
            return 0;
        }

        // Recebe os dados da cunsulta
        result = mysql_store_result(&DBCon);
        tamanhoDados =  mysql_num_rows(result);

        // Fecha a conexão ...
        mysql_close(&DBCon);
        return tamanhoDados;


    }else{
         return 0;


    }

}



string *DAO::lerDados(string *colunas, string condicao, int tamanhoColuna, string table, string tipo, int quantidadeDados){
    string* resultado = new string[quantidadeDados*tamanhoColuna];
    int i;
    int k = 0;

    for (i = 0; i <quantidadeDados*tamanhoColuna; i++)
        resultado[i] = "NULL";
    string query = "";
    string colQuery = "";

    MYSQL_ROW dados; //variável que recebe os dados

    if (this->conectar()){
        for (i = 0; i<tamanhoColuna-1;i++){
          colQuery += colunas[i] + ",";
        }
        colQuery += colunas[i];

        if (tipo == "single"){

            query = "SELECT " + colQuery +" FROM "+table +" WHERE "+condicao;

        }else if(tipo == "all"){
            if (condicao == "")
                query = "SELECT " + colQuery+" FROM "+table;
            else
                query = "SELECT " + colQuery +" FROM "+table +" WHERE "+condicao;
        }
       // cout << query.c_str() << endl;


        if(mysql_query(&DBCon,query.c_str()))
        {
            int Number = mysql_errno(&DBCon);
            string Result;
            stringstream convert;

            convert << Number;

            Result = convert.str();
            string numErro = Result;
            string msgErro = mysql_error(&DBCon);
            string error;
            error= ("Erro nº "+ numErro +" :"+msgErro);
            this->menssagem = error;
            return resultado;
        }

        // Recebe os dados da cunsulta
        result = mysql_store_result(&DBCon);

        if (result){
            menssagem = "ok";
             while ((dados=mysql_fetch_row(result)) != NULL)
            {
                for (i = 0; i<tamanhoColuna;i++){
                    resultado[k] = dados[i];
                    k++;
                }
            }


            // Limpa da memória
            mysql_free_result(result);
        }else{
              int Number = mysql_errno(&DBCon);
            string Result;
            stringstream convert;

            convert << Number;

            Result = convert.str();
            string numErro = Result;
            string msgErro = mysql_error(&DBCon);
            string error;
            error= ("Erro nº "+ numErro +" :"+msgErro);
            this->menssagem = error;

        }
        // Fecha a conexão ...
        mysql_close(&DBCon);
        return resultado;
    }else{
         return resultado;


    }
}


bool DAO::inserirDados(string *colunas, string table, string *values, int tamanhoColuna){

    string query = "";
    string colQuery = "";
    string valQuery = "";
    MYSQL_ROW dados; //variável que recebe os dados
    int i;
    if (this->conectar()){
        for (i = 0; i<tamanhoColuna-1;i++){
          colQuery += colunas[i] + ", ";
          valQuery += values[i] + ", ";

        }
        colQuery += colunas[i];
        valQuery += values[i];
        query = "INSERT INTO "+ table + "(" + colQuery +") VALUES ("+ valQuery +")";
        if(mysql_query(&DBCon,query.c_str()))
        {
            int Number = mysql_errno(&DBCon);
            string Result;
            stringstream convert;
            convert << Number;
            Result = convert.str();
            string numErro = Result;
            string msgErro = mysql_error(&DBCon);
            string error;
            error= ("Erro nº "+ numErro +" :"+msgErro);
            this->menssagem = error;
            return false;
        }else{
            mysql_close(&DBCon);
            return true;

        }
    }else{
        return false;
    }
}

bool DAO::atualizarDados(string *colunas, string table, string condicao, string *values, int tamanhoColuna){
    string query = "";
    string colValQuery = "";
    MYSQL_ROW dados; //variável que recebe os dados

    int i;
    if (this->conectar()){
        for (i = 0; i<tamanhoColuna-1;i++){
          colValQuery += colunas[i] + " =  " + values[i] + ", ";

        }
        colValQuery += colunas[i] + " = "+ values[i];
        query = "UPDATE "+ table + " SET " + colValQuery +" WHERE "+ condicao;

        if(mysql_query(&DBCon,query.c_str()))
        {
            int Number = mysql_errno(&DBCon);
            string Result;
            stringstream convert;

            convert << Number;

            Result = convert.str();
            string numErro = Result;
            string msgErro = mysql_error(&DBCon);
            string error;
            error= ("Erro nº "+ numErro +" :"+msgErro);
            this->menssagem = error;
            return false;
        }else{

            return true;
        }
        // Fecha a conexão ...
        mysql_close(&DBCon);
    }else{

         return false;


    }
}

bool DAO::deletar (string condicao, string table){
    string query = "";
    MYSQL_ROW dados; //variável que recebe os dados

    int i;
    if (this->conectar()){

        query = "DELETE FROM "+table + " WHERE "+ condicao;


        if(mysql_query(&DBCon,query.c_str()))
        {
            int Number = mysql_errno(&DBCon);
            string Result;
            stringstream convert;

            convert << Number;

            Result = convert.str();
            string numErro = Result;
            string msgErro = mysql_error(&DBCon);
            string error;
            error= ("Erro nº "+ numErro +" :"+msgErro);
            this->menssagem = error;
            return false;
        } else{
            // Fecha a conexão ...
            mysql_close(&DBCon);
            return true;
        }
    }else{

        return false;

    }
}
