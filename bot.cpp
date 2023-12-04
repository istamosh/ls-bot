//#include "pch.h" // using Code Runner
#include <iostream>
#include <Windows.h> // sleep, getAsyncKeyState, etc.
#include <string> // std::string, std::wstring

int main(){
    while (true){

        // Detects game start
        LPCWSTR window_title = L"Lost Saga in Timegate - Client";
        HWND hwnd = FindWindow(NULL, window_title);
        // cannot convert 'LPCWSTR {aka const wchar_t*}' to 'LPCSTR {aka const char*}' for argument '2' to 'HWND__* FindWindowA(LPCSTR, LPCSTR)'
        while (hwnd == NULL){
            hwnd = FindWindow(NULL, window_title);
            std::cout << "Detected!" << std::endl;
            Sleep(1000);
        }
            
        Sleep(10);

        // Get mouse coords. in-game
        if (GetAsyncKeyState(VK_NUMPAD1)){
            //HDC hdc = GetDC(hwnd);
            POINT pointing;
            GetCursorPos(&pointing);
            ScreenToClient(hwnd, &pointing);
            //ReleaseDC(hwnd, hdc);

            std::cout << "X: " << pointing.x << " | Y: " << pointing.y << std::endl;
            Sleep(1000);
        }

        // Exit
        if (GetAsyncKeyState(VK_NUMPAD0)){ // get pixel color
            std::cout << "Stopping..." << std::endl;
            return 0;
        }
    }
    return 0;
}