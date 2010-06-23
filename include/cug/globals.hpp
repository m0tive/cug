// File Info {{{
//------------------------------------------------------------------------------
/// \file globals.cpp
/// \date 2010 Jun 18
/// \author peter@pddds.com
/// \brief
/// \note Copyright (C) 2010 - All Rights Reserved
//}}}---------------------------------------------------------------------------

// Include catch {{{
#ifdef _MSC_VER
#pragma once
#endif

#ifndef _cug_globals_hpp_
#define _cug_globals_hpp_
// }}}

#include <stdexcept>
#include <string>

namespace cug
{

class Error : public std::runtime_error
{
public:
    Error( const std::string& _message )
        : std::runtime_error( _message )
    {}
};

}

#endif

