// File Info {{{
//------------------------------------------------------------------------------
/// \file world.hpp
/// \date 2010 Jun 18
/// \author peter@pddds.com
/// \brief
/// \note Copyright (C) 2010 - All Rights Reserved
//}}}---------------------------------------------------------------------------

// Include catch {{{
#ifdef _MSC_VER
#pragma once
#endif

#ifndef _cug_World_hpp_
#define _cug_World_hpp_
// }}}

//#include <string>
#include "cug/globals.hpp"

namespace cug
{

class Factory;

/// \brief
class World
{
    friend class Factory;

public:
    /// \brief World error exception
    class Error : public cug::Error
    { // {{{
        friend class World;

    protected:
        Error( const std::string& _message = "Error in World" )
            : cug::Error( _message ) {}

    }; // }}}

    //---------------------------------------
    /// \brief Load a map stored in a xml configuration file.
    /// If the file cannot be loaded a cug::World::Error is thrown.
    /// \param _configFile - The config file to load.
    void Load( const std::string& _configFile );

    //---------------------------------------
    /// \brief Reload the last loaded map.
    /// This calls cug::World::Load using the last given config file,
    /// if Load hasn't been called yet, a cug::World::Error is thrown.
    /// \param _configFile - The config file to load.
    void Reload();

protected:
    //---------------------------------------
    /// \brief Get the name of the Loaded config file
    /// \return The name of the config file loaded
    const std::string& getConfig () const { return m_configFile; }

private:
    // ---------------------------------------
    /// \brief The config file loaded in Load
    std::string m_configFile;

    //---------------------------------------
    /// \details Default constructor
    World();

    //---------------------------------------
    /// \details Destructor
    virtual ~World();

};

}

#endif
