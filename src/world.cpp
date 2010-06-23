// File Info {{{
//------------------------------------------------------------------------------
/// \file world.cpp
/// \date 2010 Jun 18
/// \author peter@pddds.com
/// \brief
/// \note Copyright (C) 2010 - All Rights Reserved
//}}}---------------------------------------------------------------------------

#include "cug/world.hpp"

namespace cug
{
    //------------------------------------------------ World::Load
    void World::Load( const std::string& _configFile )
    {
        m_configFile = _configFile;
    }

    //------------------------------------------------ World::Reload
    void World::Reload()
    {
        if( m_configFile.empty() )
            throw World::Error("Reload called before initial Load");

        Load( m_configFile );
    }

    //------------------------------------------------ World::World
    World::World()
    {
    }

    //------------------------------------------------ World::~World
    World::~World()
    {
    }
}
