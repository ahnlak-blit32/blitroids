/*
 * StateInterface.hpp - part of Blitroids, a 32Blit game.
 *
 * This defines a standard Interface for all State classes; this way they can
 * all be treated the same by the game core.
 *
 * Copyright (C) 2021 Pete Favelle <pete@fsquared.co.uk>
 *
 * This file is released under the MIT License; see LICENSE for more details.
 */

#ifndef   _STATEINTERFACE_HPP_
#define   _STATEINTERFACE_HPP_

#include "AssetManager.hpp"
#include "OutputManager.hpp"


/* Enums. */

typedef enum
{
  STATE_NONE,
  STATE_SPLASH,
  STATE_GAME,
  STATE_DEATH,
  STATE_HISORE,
  STATE_MENU,
  STATE_MAX
} state_t;


/* Interfaces. */

class StateInterface
{
protected: 
  state_t         c_state;

public:
  virtual state_t update( uint32_t ) = 0;
  virtual void    render( uint32_t ) = 0;
  virtual void    init( StateInterface *, AssetManager *, OutputManager * ) = 0;
  virtual void    fini( StateInterface * ) = 0;
  state_t         get_state( void ) { return c_state; };
};


#endif /* _STATEINTERFACE_HPP_ */

/* End of file StateInterface.hpp */
