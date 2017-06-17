#ifndef _USUARIO_H_
#define _USUARIO_H_

#include <string>

using namespace std;

class Usuario{
	public:
		Usuario();
		~Usuario();

		//construtor overload
		Usuario (string, string, string);
		void setCod_usuario(string cod_usuario);
		string getCod_usuario();
		void setNome(string nome);
		string getNome();
		void setStatus(string status);
		string getStatus ();
	private:
		string cod_usuario;
		string nome;
		string status;
};

#endif /* _USUARIO_H_ */
