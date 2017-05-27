#pragma once
#include <windows.h>
#include <tchar.h>
#include "..\..\Servidor\Servidor\Game.h"
#include "..\..\Servidor\Servidor\Item.h"
#include "..\..\Servidor\Servidor\Map.h"
#include "..\..\Servidor\Servidor\Player.h"
#include "..\..\Servidor\Servidor\Snake.h"
//Definir uma constante para facilitar a leitura do prot�tipo da fun��o
//Este .h deve ser inclu�do no projeto que o vai usar (modo impl�cito)
#define TAM 256
#define SHMEMSIZE 4096 
//Esta macro � definida pelo sistema caso estejamos na DLL (<DLL_IMP>_EXPORTS definida)
//ou na app (<DLL_IMP>_EXPORTS n�o definida) onde DLL_IMP � o nome deste projeto
#ifdef DLL_EXPORTS
#define DLL_IMP_API __declspec(dllexport)
#else
#define DLL_IMP_API __declspec(dllimport)
#endif
extern "C"
{
	//Vari�vel global da DLL
	//extern DLL_IMP_API int nDLL;
	static LPVOID lpvMem = NULL;      // pointer to shared memory
	static HANDLE hMapObject = NULL;  // handle to file mapping
	static GAME *game = (GAME*)malloc(sizeof(GAME));
	//Fun��es a serem exportadas/importadas
	DLL_IMP_API int UmaString(void);
	DLL_IMP_API BOOL WINAPI DllMain(HANDLE hInstance, DWORD razao, LPVOID tipo_declaracao);
}