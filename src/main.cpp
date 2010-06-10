#ifdef WIN32
    #define WIN32_LEAN_AND_MEAN
    #include <Windows.h>
    #ifdef _DEBUG
        // visual leak detector - catch memory leaks
        #include <vld.h>
    #endif
#endif

#include <cstdlib>

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}

