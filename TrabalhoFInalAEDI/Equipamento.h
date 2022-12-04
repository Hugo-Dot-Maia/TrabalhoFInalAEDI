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
	float preco;
	// Departamento

public:
	Equipamento();
	Equipamento(string nome, string descricao, string tipo, int codigo, float preco);

	string getNome();
	string getDescricao();
	string getTipo();
	int getCodigo();
	float getPreco();

	void setNome(string nome);
	void setDescricao(string descricao);
	void setTipo(string tipo);
	void setCodigo(int codigo);
	void setPreco(float preco);


};

