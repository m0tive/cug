/// \file demo.cpp
/// \date 2010 Jun 18
/// \author peter@pddds.com
/// \brief
/// \note Copyright (C) 2010 - All Rights Reserved
//------------------------------------------------------------------------------

#if defined( WIN32 ) || defined( CYGWIN )
    #define WIN32_LEAN_AND_MEAN
    #include <Windows.h>
#endif

#ifdef USEVLD // visual leak detector - catch memory leaks
    #include <vld.h>
#endif

#include <cstdlib>
#include <iostream>

#include <cug/factory.hpp>
#include <cug/world.hpp>

int main(int argc, char** argv)
{
    cug::Factory factory;
    cug::Factory factB;

    cug::World* demoWorld = factory.NewWorld();
    cug::World* worldB = factB.NewWorld();

//    cug::WorldIterator begin = factory.GetWorldItBegin();
//    cug::WorldIterator end = factory.GetWorldItEnd();

    factory.DeleteWorld( worldB );

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

