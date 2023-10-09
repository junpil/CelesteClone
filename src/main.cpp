// ##########################################################
//                     Platform Globals
// ##########################################################
static bool running = true;

// ##########################################################
//                     Platform Functions
// ##########################################################
bool platform_create_window(int width, int height, char* title);

// ##########################################################
//                     Windows Platform
// ##########################################################
#ifdef _WIN32
#define WIN32_LEAN_ANDMEAN
#define NOMINMAX
#include <Windows.h>

// ##########################################################
//                     Windows Globals
// ##########################################################

// ##########################################################
//                     Platform Implementation
// ##########################################################

#endif
bool platform_create_window(int width, int height, char* title)
{
    HINSTANCE instance = GetModuleHandleA(0);

    WNDCLASSA wc = {};
    wc.hInstance = instance;
    wc.hIcon = LoadIcon(instance, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = title; // uid, not a real title
    wc.lpfnWndProc = DefWindowProcA; // Callback for Input 

    if (!RegisterClassA(&wc))
    {
        return false;
    } 

    // WS_CAPTION | WS_SYSMENUI | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZE
    int dwStyle = WS_OVERLAPPEDWINDOW;

    HWND window = CreateWindowExA(0, title,
    title,
    dwStyle,
    100,
    100,
    width,
    height,
    NULL, // parent
    NULL, // menu
    instance,
    NULL // lpParam
    );

    if (window == NULL)
    {
        return false;
    }

    ShowWindow(window, SW_SHOW);

    return true;
}

int main()
{
    platform_create_window(1200, 720, "TKK");
    while(running)
    {
        // Update
    }

    return 0;
}