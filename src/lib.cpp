#ifdef _WIN32
#include <windows.h>

BOOL WINAPI
DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
    switch ( fdwReason )
    {
    case DLL_PROCESS_ATTACH:
    case DLL_PROCESS_DETACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    }

    return TRUE;
}

#else
static __attribute__((constructor)) void
on_attach_routine(void)
{
}

static void __attribute__((destructor))
on_detach_routine()
{
}
#endif //_WIN32
