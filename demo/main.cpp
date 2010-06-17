#ifdef WIN32
    #define WIN32_LEAN_AND_MEAN
    #include <Windows.h>
    #ifdef _DEBUG
        // visual leak detector - catch memory leaks
        #include <vld.h>
    #endif
#endif

#include <cstdlib>
#include <cug/cug.hpp>

int main(int argc, char** argv)
{
#if 0
    cug::World demoWorld = cug::Factory::NewWorld("demo.world.cfg")
    cug::Map demoLand = demoWorld.NewMap("demo.cfg");

    demoLand.AddTransportLayer("layer.shp");

    demoLand.Print("map.jpg");

    demoLand.RunFor("1000 years");

    demoLand.Print("map.jpg");
#endif

    return EXIT_SUCCESS;
}

