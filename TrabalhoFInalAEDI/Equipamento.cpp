#include "Equipamento.h"
using namespace std;

Equipamento::Equipamento()
{
	this->nome = "Sem nome";
	this->descricao = "SEM DESCRICAO";
	this->tipo = "SEM TIPO";
	this->codigo = 0;

}
Equipamento::Equipamento(string nome, string descricao, string tipo, int codigo)
{
	this->nome = nome;
	this->descricao = descricao;
	this->tipo = tipo;
	this->codigo = codigo;
}

string Equipamento::getNome()
{
	return nome;
}
string Equipamento::getDescricao()
{
	return descricao;
}
string Equipamento::getTipo() 
{
	return tipo;
}
int Equipamento::getCodigo()
{
	return codigo;
}