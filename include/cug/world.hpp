/// \file world.hpp
/// \date 2010 Jun 18
/// \author peter@pddds.com
/// \brief
/// \note Copyright (C) 2010 - All Rights Reserved
//------------------------------------------------------------------------------

#ifdef _MSC_VER
#pragma once
#endif

#ifndef _cug_World_hpp_
#define _cug_World_hpp_

namespace cug
{

class Factory;

/// \brief
class World
{
    friend class Factory;

private:
    //---------------------------------------
    /// \details Default constructor
    World();

    //---------------------------------------
    /// \details Destructor
    ~World();

};

}

#endif
