#pragma once

#include <string>

using namespace std;
class TipoEquipamento
{
private:
	int codigo;
	string descricao;
public:
	TipoEquipamento();
	TipoEquipamento(string descricao, int codigo);

	int getCodigo();
	string getDescricao();

	void setCodigo(int codigo);
	void setDescricao(string descricao);
};