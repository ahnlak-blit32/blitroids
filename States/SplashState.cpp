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
 * state_t, the state identifier that we represent.
 */

SplashState::SplashState( state_t p_state )
{
  /* Remember the state identifier we're given. */
  c_state = p_state;

  /* Set up the font colour stuff. */
  c_font_pen = blit::Pen( 200, 200, 200 );
  c_font_tween.init( blit::tween_ease_in_out_quad, 200.0f, 50.0f, 750 );

  /* Create the background we'll be using. */
  c_background = new StarburstBackground();

  /* All done. */
  return;
}


/*
 * ~SplashState - destructor, cleans up anything we allocated.
 */

SplashState::~SplashState()
{
  /* Get rid of the background object. */
  if ( nullptr != c_background )
  {
    delete c_background;
    c_background = nullptr;
  }

  /* All done. */
  return;
}


/*
 * update - called every tick (10ms) to update our internal state.
 *
 * uint32_t - the time in milliseconds since the epoch.
 *
 * Returns state_t, the game state we should move to, defaulting to ourselves.
 */

state_t SplashState::update( uint32_t p_time )
{
  /* Update the background. */
  c_background->update( p_time );

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
  /* Draw the background. */
  c_background->render( p_time );

  /* Plonk the logo somewhere central. */
  blit::screen.blit( 
    c_asset_manager->c_img_logo, 
    c_asset_manager->c_img_logo->clip,
    blit::Point( 
      ( blit::screen.bounds.w - c_asset_manager->c_img_logo->bounds.w ) / 2,
      ( blit::screen.bounds.h - c_asset_manager->c_img_logo->bounds.h ) / 2 - 20
    )
  );

  /* Prompt the user to press start. */
  blit::screen.pen = c_font_pen;
  blit::screen.text(
    c_asset_manager->get_string( STR_BTN_A_TO_START ),
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
 * StateInterface *, the game state that we are coming from
 * AssetManager *  , the asset manager object
 * OutputManager * , the output manager
 */

void SplashState::init( StateInterface *p_previous_state, 
                        AssetManager *p_asset_manager, 
                        OutputManager *p_output_manager )
{
  /* Keep hold of the pointers to our managers. */
  c_asset_manager = p_asset_manager;
  c_output_manager = p_output_manager;

  /* Start the tweens running. */
  c_font_tween.start();

  /* And initialise the background. */
  c_background->init();

  /* All done. */
  return;
}


/*
 * fini - called any time the state is being de-activated
 *
 * StateInterface *, the game state we are moving to
 */

void SplashState::fini( StateInterface *p_next_state )
{
  /* Stop the tweens running. */
  c_font_tween.stop();

  /* And shut down the background. */
  c_background->fini();

  /* All done. */
  return;
}


/* End of file SplashState.cpp */
