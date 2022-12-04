// TrabalhoFInalAEDI.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <fstream>
#include <string>
#include <speechapi_cxx.h>
#include <stdbool.h>
#include "Equipamento.h"
#include "TipoEquipamento.h"


using namespace std;
using namespace Microsoft::CognitiveServices::Speech;
using namespace Microsoft::CognitiveServices::Speech::Audio;

bool comandoPorVoz;

// PROCEDIMENTO QUE REQUISITA DA API A TRANSFORMAÇÃO DE UM TEXTO EM FALA
void texto_em_fala(std::shared_ptr<Microsoft::CognitiveServices::Speech::SpeechSynthesizer> requisicao_textofala, string Texto)
{
    cout << Texto + "\n";
    requisicao_textofala->SpeakTextAsync(Texto).get(); // REQUISIÇÃO DA SINTETIZAÇÃO DE TEXTO EM FALA
}

// FUNÇÃO QUE REQUISITA DA API O RECONHECIMENTO DE UMA FALA E A TRANSFORMAÇÃO DESSA FALA EM UM TEXTO
string fala_em_texto(std::shared_ptr<Microsoft::CognitiveServices::Speech::SpeechRecognizer> requisicao_falatexto) {
    auto resultado = requisicao_falatexto->RecognizeOnceAsync().get();// REQUISIÇÃO DO RECONHEIMENTO DE FALA EM TEXTO
    cout << resultado->Text + "\n";
    return resultado->Text; //CONVERSÃO DO RESULTADO DO RECONHECIMENTO EM TEXTO
}

void audioConfig() {

    auto autenticacao = SpeechConfig::FromSubscription("", ""); // DECLARAÇÃO DA AUTENTICAÇÃO DO RECURSO
    autenticacao->SetSpeechRecognitionLanguage("pt-BR");                //  CONFIGURAÇÃO DA AUTENTICAÇÃO PARA O RECONHECIMENTO DE FALA EM PORTUGUÊS 
    autenticacao->SetSpeechSynthesisLanguage("pt-BR");                  //  CONFIGURAÇÃO DA AUTENTICAÇÃO PARA A SINTETIZAÇÃO DE FALA EM PORTUGUÊS 
    autenticacao->SetSpeechSynthesisVoiceName("pt-BR-FranciscaNeural"); // CONFIGURAÇÃO DE UMA VOZ ESPECÍFICA: pt-BR-AntonioNeural, pt-BR-FranciscaNeural

    //  OBS: A PERSONALIZAÇÃO DA VOZ NÃO É OBRIGATÓRIA. SE A LINHA ACIMA FOR COMENTADA, O SERVIÇO ASSUMIRÁ UMA VOZ POR DEFAULT.
    //  O NOME DAS VOZES PODEM SER ALTERADOS COM O TEMPO. CASO SEU PROGRAMA NÃO ESTEJA SINTETIZANDO A VOZ ESCOLHIDA, TENTE COMENTAR A CONFIGURAÇÃO
    //  OU PESQUISE NA DOCUMENTAÇÃO DA MICROSOFT POR VOZES DISPONÍVEIS: https://docs.microsoft.com/pt-br/azure/cognitive-services/speech-service/language-support
    auto audio_config = AudioConfig::FromDefaultMicrophoneInput(); // DECLARAÇÃO DA ENTRADA DO MICROFONE
    auto requisicao_textofala = SpeechSynthesizer::FromConfig(autenticacao); //  DEFINIÇÃO DO OBJETO REQUISICAO_TEXTOFALA
    auto requisicao_falatexto = SpeechRecognizer::FromConfig(autenticacao, audio_config); //  REDEFINIÇÃO DO OBJETO REQUISICAO_FALATEXTO COM AS NOVAS CONFIGURAÇÕES


    try
    {
        texto_em_fala(requisicao_textofala, "SISTEMA LIGADO");
        texto_em_fala(requisicao_textofala, "Qual e o seu nome?");
        string nome = fala_em_texto(requisicao_falatexto);
        texto_em_fala(requisicao_textofala, "Ola " + nome + "! Informe se deseja utilizar o sistema por meio de comandos de voz (Sim/Nao): ");
        string senha = fala_em_texto(requisicao_falatexto);
        texto_em_fala(requisicao_textofala, "Verificando. . .");

        if (senha == ("Sim.")) {
            texto_em_fala(requisicao_textofala, "SISTEMA POR COMANDO DE VOZ ATIVO");
            comandoPorVoz = true;
        }
        else {
            texto_em_fala(requisicao_textofala, "SISTEMA SEM COMANDO DE VOZ");
            comandoPorVoz = false;
        }
    }
    catch (exception e)
    {
        cout << e.what();
    }

}

void audioMenu()
{

}


/*-------------------------------------------------------------------------------------------------------------------------
Essa seção se destina a CRUD de Tipo Equipamento
-------------------------------------------------------------------------------------------------------------------------*/
void createTipoEquipamento()
{
    int codigo;
    string descricao;
    printf("\nInsira a descricao: ");
    scanf_s("%s", descricao, sizeof(descricao));
    printf("\nInsira o codigo: ");
    scanf_s("%d", &codigo);
    TipoEquipamento tipoEquipamento(descricao, codigo);

    FILE* fp;
    fopen_s(&fp, "TipoEquipamento.txt", "w");
    if (fp == NULL)
    {
        printf("ERRO AQUIVO\n");
        return;
    }
    cout << "fwrite returned " << fwrite(&codigo, sizeof(codigo), 1, fp);
    cout << "fwrite returned " << fwrite(&descricao, sizeof(descricao), 1, fp);

    fclose(fp);
}
void crudTipoEquipamento() 
{
    bool repete = false;
    int indice = 0;
    do
    {
        printf("\nDigite a operacao do CRUD que fazer ver\n");
        scanf_s("%d", &indice);

        switch (indice)
        {
        case 1:
            createTipoEquipamento();
            break;
        case 2:
            //Read
            break;
        case 3:
            //Update
            break;
        case 4:
            //Delete
            break;

        default:
            printf("Voce nao insiriu uma operacao valida");
            break;
        }

        printf("\nCaso deseje realizar outra operacao do CRUD digite 1, caso nao digite 0\n");
        scanf_s("%d", &repete);
    } while (repete);

}
//------------------------------------------ FIM DA SEÇÃO: CRUD  de Tipo Equipamento ------------------------------------------------------

void normalMenu()
{
    bool repete = false;
    int indice = 0;
    do 
    {
        printf("\nDigite a operacao que fazer ver\n");
        printf("A) CRUD Tipo equipamento.\n");
        scanf_s("%d", &indice);

        switch (indice)
        {
        case 1:
            crudTipoEquipamento();
            break;
        case 2:
            //Read
            break;
         case 3:
             //Update
             break;
         case 4:
             //Delete
             break;

        default:
            printf("Voce nao insiriu uma operacao valida");
            break;
        }

        printf("\nCaso deseje realizar outra operacao do digite 1, caso nao digite 0\n");
        scanf_s("%d", &repete);
    } while (repete);

}
int main()
{
    audioConfig();
    printf("%d", comandoPorVoz);

    if (comandoPorVoz)
        audioMenu();
    else
        normalMenu();

    return 0;
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
