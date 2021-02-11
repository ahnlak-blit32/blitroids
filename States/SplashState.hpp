/*
 * SplashState.hpp - part of Blitroids, a 32Blit game.
 *
 * The SplashState renders the splash screen, when the game is first loaded,
 * and possibly after the game is over.
 *
 * Copyright (C) 2021 Pete Favelle <pete@fsquared.co.uk>
 *
 * This file is released under the MIT License; see LICENSE for more details.
 */

#ifndef   _SPLASHSTATE_HPP_
#define   _SPLASHSTATE_HPP_

#include "32blit.hpp"
#include "StateInterface.hpp"


/* Constants & Macros. */

/* Enums. */

/* Structs. */

/* Classes. */

class SplashState : public StateInterface
{
private:
  AssetManager   *c_asset_manager;
  OutputManager  *c_output_manager;
  blit::Pen       c_font_pen;
  blit::Tween     c_font_tween;
  
public:
                  SplashState( state_t );
                 ~SplashState();

  state_t         update( uint32_t );
  void            render( uint32_t );
  void            init( StateInterface *, AssetManager *, OutputManager * );
  void            fini( StateInterface * );

};


#endif /* _SPLASHSTATE_HPP_ */

/* End of file SplashState.hpp */
