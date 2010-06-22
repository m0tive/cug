/// \file factory.cpp
/// \date 2010 Jun 18
/// \author peter@pddds.com
/// \brief
/// \note Copyright (C) 2010 - All Rights Reserved
//------------------------------------------------------------------------------

#include "cug/factory.hpp"

#include "cug/world.hpp"

namespace cug
{
    //------------------------------------------------ Factory::Factory
    Factory::Factory()
    {
    }

    //------------------------------------------------ Factory::~Factory
    Factory::~Factory()
    {
        WorldIterator endit = GetWorldItEnd();
        for ( WorldIterator it = GetWorldItBegin() ; it != endit ; ++it )
        {
            delete *it;
        }
        m_worlds.clear();
    }

    //------------------------------------------------ Factory::NewWorld
    World* Factory::NewWorld()
    {
        World* nWorld = new World();

        m_worlds.insert( nWorld );

        return nWorld;
    }

    //------------------------------------------------ Factory::DeleteWorld
    void Factory::DeleteWorld( World* const _world )
    {
        WorldIterator it = m_worlds.find(_world);
        if ( it != GetWorldItEnd() )
        {
            delete *it;
            m_worlds.erase(it);
        }
        else
        {
            throw FactoryError("Attempting to delete a World not contained within this Factory");
        }
    }

}
