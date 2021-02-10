/*
 * SplashState.cpp - part of Blitroids, a 32Blit game.
 *
 * The SplashState renders the splash screen, when the game is first loaded,
 * and possibly after the game is over.
 *
 * Copyright (C) 2021 Pete Favelle <pete@fsquared.co.uk>
 *
 * This file is released under the MIT License; see LICENSE for more details.
 */

/* System headers. */


/* Local headers. */

#include "32blit.hpp"
#include "blitroids.hpp"
#include "AssetManager.hpp"
#include "OutputManager.hpp"
#include "SplashState.hpp"


/* Module variables. */


/* Functions. */

/*
 * SplashState - constructor for the state, which just sets up basic defaults. 
 *
 * gamestate_t, the state identifier that we represent.
 */

SplashState::SplashState( gamestate_t p_state )
{
  /* Remember the state identifier we're given. */
  c_state = p_state;

  /* Set up the font colour stuff. */
  c_font_pen = blit::Pen( 200, 200, 200 );
  c_font_tween.init( blit::tween_ease_in_out_quad, 200.0f, 50.0f, 750 );

  /* All done. */
  return;
}


/*
 * ~SplashState - destructor, cleans up anything we allocated.
 */

SplashState::~SplashState()
{
  /* All done. */
  return;
}


/*
 * update - called every tick (10ms) to update our internal state.
 *
 * uint32_t - the time in milliseconds since the epoch.
 *
 * Returns gamestate_t, the game state we should move to, defaulting to ourselves.
 */

gamestate_t SplashState::update( uint32_t p_time )
{
  /* Update the font pen from its tween. */
  c_font_pen.r = c_font_pen.g = c_font_tween.value;

  /* All done, keep with what we're doing. */
  return c_state;
}


/*
 * render - called every frame (20ms) to draw our internal state to the screen!
 *
 * uint32_t - the time in milliseconds since the epoch.
 */

void SplashState::render( uint32_t p_time )
{
  /* Clear the screen. */
  blit::screen.pen = blit::Pen( 60, 20, 20 );
  blit::screen.clear();

  blit::screen.pen = c_font_pen;
  blit::screen.text(
    "Press <A> To Start",
    c_asset_manager->font_null,
    blit::Point( blit::screen.bounds.w / 2, blit::screen.bounds.h - 25 ),
    true,
    blit::TextAlign::center_center
  );  

  /* All done. */
  return;
}


/*
 * init - called any time the state is activated, or woken up.
 *
 * GameStateInterface *, the game state that we are coming from
 * AssetManager *      , the asset manager object
 * OutputManager *     , the output manager
 */

void SplashState::init( GameStateInterface *p_previous_state, 
                        AssetManager *p_asset_manager, 
                        OutputManager *p_output_manager )
{
  /* Keep hold of the pointers to our managers. */
  c_asset_manager = p_asset_manager;
  c_output_manager = p_output_manager;

  /* Start the tweens running. */
  c_font_tween.start();

  /* All done. */
  return;
}


/*
 * fini - called any time the state is being de-activated
 *
 * GameStateInterface *, the game state we are moving to
 */

void SplashState::fini( GameStateInterface *p_next_state )
{
  /* Stop the tweens running. */
  c_font_tween.stop();

  /* All done. */
  return;
}


/* End of file SplashState.cpp */
