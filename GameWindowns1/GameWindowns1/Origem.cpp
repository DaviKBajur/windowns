#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <windowsx.h>
#include "Resources.h"   

// prot�tipo do procedimento da janela
LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);

//--------------------------------------------------------------------------------

// programa principal
int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    HWND hwnd;            // identificador da janela
    MSG msg;              // mensagem
    WNDCLASS wndclass;    // classe da janela

    // Definindo uma classe de janela chamada "BasicWindow" 
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = WinProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON));
    wndclass.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_CURSOR));
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = "BasicWindow";

    // Registrando a classe "BasicWindow"
    if (!RegisterClass(&wndclass))
    {
        MessageBox(NULL, "Erro na cria��o da janela!", "Aplica��o", MB_ICONERROR);
        return 0;
    }

    // tamanho da janela fixo 
    int windowWidth = 960;
    int windowHeight = 540;

    int windowPosX = GetSystemMetrics(SM_CXSCREEN) / 2 - windowWidth / 2;
    int windowPosY = GetSystemMetrics(SM_CYSCREEN) / 2 - windowHeight / 2;

    // Criando uma janela baseada na classe "BasicWindow" 
    hwnd = CreateWindowEx(
        NULL,           // estilos extras 
        "BasicWindow",        // classe da janela 
        "Aplica��o",           // t�tulo da janela 
        WS_OVERLAPPED | WS_SYSMENU,  // estilo da janela 
        CW_USEDEFAULT,               // posi��o x inicial 
        CW_USEDEFAULT,               // posi��o y inicial 
        windowWidth,                   // largura da janela 
        windowHeight,                  // altura da janela 
        NULL,                        // identificador do objeto pai 
        NULL,                        // identificador do menu 
        hInstance,                   // identificador da aplica��o 
        NULL);                          // par�metros de cria��o



    // Mostra e atualiza a janela
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Tratamento de mensagens destinadas a janela da aplica��o
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // fim do programa
    return int(msg.wParam);
}

//-------------------------------------------------------------------------------

// procedimento da janela
LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, message, wParam, lParam);
}