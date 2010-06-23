// File Info {{{
//------------------------------------------------------------------------------
/// \file factory.hpp
/// \date 2010 Jun 18
/// \author peter@pddds.com
/// \brief
/// \note Copyright (C) 2010 - All Rights Reserved
//}}}---------------------------------------------------------------------------

// Include catch {{{
#ifdef _MSC_VER 
#pragma once
#endif

#ifndef _cug_Factory_hpp_
#define _cug_Factory_hpp_
// }}}

#include <set>

#include "cug/globals.hpp"

namespace cug
{

class World;

typedef std::set<World*>::iterator WorldIterator;
typedef std::set<World*>::const_iterator WorldConstIterator;

/// \brief A singleton factory class for the library
/// This contains methods to build and delete
class Factory
{ // {{{
public:

    /// \brief Factory error exception
    class Error : public cug::Error
    { // {{{
        friend class Factory;

    protected:
        Error( const std::string& _message = "Error in Factory" )
            : cug::Error( _message ) {}

    }; // }}}


    //---------------------------------------
    /// \details Hidden constructor
    Factory();

    //---------------------------------------
    /// \details Destructor
    ~Factory();

    //---------------------------------------
    /// \brief New World builder
    World* NewWorld();

    //---------------------------------------
    /// \brief Delete a world
    void DeleteWorld( World* const _world );

    //---------------------------------------
    /// \brief Get an iterator for the world set
    /// \return set iterator for the factory's Worlds
    WorldIterator GetWorldItBegin() { return m_worlds.begin(); }

    //---------------------------------------
    /// \brief Get a const iterator for the world set
    /// \return set const iterator for the factory's Worlds
    WorldConstIterator GetWorldItBegin() const { return m_worlds.begin(); }

    //---------------------------------------
    /// \brief Get an end iterator for the world set
    /// \return End set iterator for the factory's Worlds
    WorldIterator GetWorldItEnd() { return m_worlds.end(); }

    //---------------------------------------
    /// \brief Get a const end iterator for the world set
    /// \return End set const iterator for the factory's Worlds
    WorldConstIterator GetWorldItEnd() const { return m_worlds.end(); }

protected:
    //---------------------------------------
    /// \brief A list of all the worlds
    std::set<World*> m_worlds;
}; // }}}


}

#endif
