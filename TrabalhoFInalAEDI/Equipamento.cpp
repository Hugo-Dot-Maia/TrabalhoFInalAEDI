#include "Equipamento.h"
using namespace std;

Equipamento::Equipamento()
{
	this->nome = "Sem nome";
	this->descricao = "SEM DESCRICAO";
	this->tipo = "SEM TIPO";
	this->codigo = 0;
	this->preco = 0.0;

}
Equipamento::Equipamento(string nome, string descricao, string tipo, int codigo, float preco)
{
	this->nome = nome;
	this->descricao = descricao;
	this->tipo = tipo;
	this->codigo = codigo;
	this->preco = preco;
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
float Equipamento::getPreco()
{
	return preco;
}

void Equipamento::setNome(string nome)
{
	this->nome = nome;
}
void Equipamento::setDescricao(string descricao)
{
	this->descricao = descricao;
}
void Equipamento::setTipo(string tipo)
{
	this->tipo = tipo;
}
void Equipamento::setCodigo(int codigo)
{
	this->codigo = codigo;
}
void Equipamento::setPreco(float preco)
{
	this->preco = preco;
}
