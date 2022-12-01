#pragma once

#include <string>
#include <iostream>

using namespace std;
class Equipamento
{
private:
	string nome;
	string descricao;
	string tipo;
	int codigo;
	// Departamento

public:
	Equipamento();
	Equipamento(string nome, string descricao, string tipo, int codigo);

	string getNome();
	string getDescricao();
	string getTipo();
	int getCodigo();

	string setNome(string nome);
	string setDescricao(string descricao);
	string setTipo(string tipo);
	int setCodigo(int codigo);


};

