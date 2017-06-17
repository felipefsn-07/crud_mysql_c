# crud_mysql_c
Esse repositório possui uma Classe DAO(data acces object) responsável por realizar as operações básicas de consulta, alteração, inserção e remoção do banco de dados.  Além disso, o mesmo possui informações de como instalar o mysql no ubuntu e inserir a biblioteca do MySql no codBlock.

1- Para instalar o mysql no ubuntu: 
  http://cursosdeprogramacao.com.br/blog/instalando-o-mysql-server-e-mysql-workbench-ubuntu/
  
2- Depois digote no terminal "sudo apt-get install libmysqlclient-dev" para o funcionamento do mysql no codeblocks

3- No codeblocks vá em settings->compiler->Linker settings em "Other linker options" digite "-lmysqlclient"
