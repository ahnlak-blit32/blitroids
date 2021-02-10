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

/* Constants & Macros. */

/* Enums. */

/* Structs. */

/* Classes. */

class SplashState : public GameStateInterface
{
private:
public:
                  SplashState( gamestate_t );
                 ~SplashState();

  gamestate_t     update( uint32_t );
  void            render( uint32_t );
  void            init( GameStateInterface *, AssetManager *, OutputManager * );
  void            fini( GameStateInterface * );

};


#endif /* _SPLASHSTATE_HPP_ */

/* End of file SplashState.hpp */
