
#include "snake_dll.h"
//Para verificar ao carregar a dll que a aplicação irá ocupar mais memória
char ponteiro[40960];
//Definição da variável global
int nDLL = 1234;
//Exportar a função para ser utilizada fora da DLL
int UmaString(void) {
	TCHAR str[TAM];
	_tprintf(TEXT("Dentro da Dll\nIntroduza uma frase:"));
	_fgetts(str, TAM, stdin);
	if (_tcslen(str) > 1) //Introduzir mais caracteres do que apenas <enter>
		return 1;
	else
		return 0;
}
BOOL WINAPI DllMain(HANDLE hInstance, DWORD razao, LPVOID tipo_declaracao) {
	BOOL fInit, fIgnore;

	switch (razao)
	{
		// DLL load due to process initialization or LoadLibrary

	case DLL_PROCESS_ATTACH:

		// Create a named file mapping object

		hMapObject = CreateFileMapping(
			INVALID_HANDLE_VALUE,   // use paging file
			NULL,                   // default security attributes
			PAGE_READWRITE,         // read/write access
			0,                      // size: high 32-bits
			SHMEMSIZE,              // size: low 32-bits
			TEXT("dllmemfilemap")); // name of map object
		if (hMapObject == NULL)
			return FALSE;

		// The first process to attach initializes memory

		fInit = (GetLastError() != ERROR_ALREADY_EXISTS);

		// Get a pointer to the file-mapped shared memory

		game = (GAME*)MapViewOfFile(
			hMapObject,     // object to map view of
			FILE_MAP_ALL_ACCESS, // read/write access
			0,              // high offset:  map from
			0,              // low offset:   beginning
			30);             // default: map entire file
		if (lpvMem == NULL)
			return FALSE;

		// Initialize memory if this is the first process

		if (fInit)
			memset(lpvMem, '\0', SHMEMSIZE);

		break;

		// The attached process creates a new thread

	case DLL_THREAD_ATTACH:
		break;

		// The thread of the attached process terminates

	case DLL_THREAD_DETACH:
		break;

		// DLL unload due to process termination or FreeLibrary

	case DLL_PROCESS_DETACH:

		// Unmap shared memory from the process's address space

		fIgnore = UnmapViewOfFile(lpvMem);

		// Close the process's handle to the file-mapping object

		fIgnore = CloseHandle(hMapObject);

		break;

	default:
		break;
	}

	return TRUE;
	UNREFERENCED_PARAMETER(hInstance);
	UNREFERENCED_PARAMETER(tipo_declaracao);
}
