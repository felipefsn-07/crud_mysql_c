#include "Usuario.h"
#include <string>

using namespace std;

Usuario::Usuario() {
	//TODO Generated function
}

Usuario::~Usuario() {

}

//construtor overload
Usuario::Usuario(string cod_usuario, string nome, string status) {
	this->cod_usuario = cod_usuario;
	this->nome = nome;
	this->status = status;

	//TODO Generated function
}

void Usuario::setCod_usuario(string cod_usuario){
	this->cod_usuario = cod_usuario;

}

string Usuario::getCod_usuario(){
	return this->cod_usuario;
}


void Usuario::setNome(string nome){

	this->nome = nome;
}
string Usuario::getNome(){
	return this->nome;
}

void Usuario::setStatus(string status){
	this->status = status;
}
string Usuario::getStatus(){
	return this->status;

}
