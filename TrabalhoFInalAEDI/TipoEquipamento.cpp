#include "TipoEquipamento.h"
using namespace std;

TipoEquipamento::TipoEquipamento()
{
	this->codigo = 0;
	this->descricao = "SEM DESCRICAO";
}

TipoEquipamento::TipoEquipamento(string descricao, int codigo)
{
	this->codigo = codigo;
	this->descricao = descricao;
}

string TipoEquipamento::getDescricao()
{
	return descricao;
}

int TipoEquipamento::getCodigo()
{
	return codigo;
}

void TipoEquipamento::setCodigo(int codigo)
{
	this->codigo = codigo;
}

void TipoEquipamento::setDescricao(string descricao)
{
	this->descricao = descricao;
}