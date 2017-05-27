#include "..\..\DLL_Snake\DLL_Snake\snake_dll.h"
#include <Windows.h>
#include <tchar.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>

int _tmain(int argc, TCHAR *argv[]) {
	////Usar a variável da Dll
	//_tprintf(TEXT("Valor da variável da DLL: %d\n"), nDLL);
	////Chamar a funcao da Dll
	//_tprintf(TEXT("Resultado da função da UmaString DLL: %d\n"), UmaString());
	BOOL flag;
	HANDLE handle;
	LPVOID lpz;
	flag = DllMain(handle, 1, lpz);

	if (flag) {
		_tprintf(TEXT("NICE DONE "));
	}
	system("pause");
	return 0;

}