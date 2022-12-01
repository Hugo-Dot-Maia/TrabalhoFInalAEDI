// TrabalhoFInalAEDI.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <fstream>
#include <string>
#include <speechapi_cxx.h>
#include "Equipamento.h"


using namespace std;
using namespace Microsoft::CognitiveServices::Speech;
using namespace Microsoft::CognitiveServices::Speech::Audio;

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

int main()
{
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
        }
        else {
            texto_em_fala(requisicao_textofala, "SISTEMA SEM COMANDO DE VOZ");
        }
    }
    catch (exception e)
    {
        cout << e.what();
    }
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
