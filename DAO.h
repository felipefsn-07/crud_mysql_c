#ifndef DAO_H
#define DAO_H
#include <sstream>
#include <string>
#include <mysql/mysql.h>
using namespace std;



class DAO
{
    private:
        const char *server;
        const char *usuario;
        const char *senha;
        const char *db;
        MYSQL_RES *result; //variável que recebe o resultado
        string menssagem;
        MYSQL DBCon;

    public:
        DAO();
        virtual ~DAO();
        string getMensagem();
        bool conectar();
        int  totalDados(string condicao, string table);
        string *lerDados(string *colunas, string condicao, int tamanhoColuna, string table, string tipo, int quantidadeDados);
        bool inserirDados(string *colunas, string table, string *values, int tamanhoColuna);
        bool atualizarDados(string *colunas, string table, string condicao, string *values, int tamanhoColuna);
        bool deletar (string condicao, string table);

};

#endif // CRUD_H
