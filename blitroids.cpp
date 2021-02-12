/*
 * blitroids.cpp - part of Blitroids, a 32Blit game.
 *
 * This file contains the core, high level logic and is the main entry point.
 *
 * Copyright (C) 2021 Pete Favelle <pete@fsquared.co.uk>
 *
 * This file is released under the MIT License; see LICENSE for more details.
 */

/* System headers. */

#include <string.h>


/* Local headers. */

#include "32blit.hpp"
#include "blitroids.hpp"

#include "AssetManager.hpp"
#include "OutputManager.hpp"

#include "StateInterface.hpp"
#include "SplashState.hpp"


/* Module variables. */

static state_t              m_state;
static StateInterface      *m_states[STATE_MAX];
static AssetManager        *m_asset_manager;
static OutputManager       *m_output_manager;


/* Functions. */

/*
 * state_init - calls the init function of the current state, if we can.
 *
 * state_t - the previous state we were in.
 *
 * Returns true if the init function was called, false on error.
 */

bool blitroids_state_init( state_t p_last_state )
{
  /* Debug trace of state switching. */
  debug_printf( "Switching states from %d to %d\n", p_last_state, m_state );

  /* Check to see if the current state if defined. */
  if ( nullptr == m_states[m_state] )
  {
    return false;
  }

  /* Then we can just call the init function! */
  m_states[m_state]->init( m_states[p_last_state], m_asset_manager, m_output_manager );

  /* Return true to say we were able to do it. */
  return true;
}


/*
 * state_fini - calls the fini function of the current state, if we can.
 *
 * state_t - the next state we will be in.
 *
 * Returns true if the fini function was called, false on error.
 */

bool blitroids_state_fini( state_t p_next_state )
{
  /* Check to see if the current state if defined. */
  if ( nullptr == m_states[m_state] )
  {
    return false;
  }

  /* Then we can just call the init function! */
  m_states[m_state]->fini( m_states[p_next_state] );

  /* Return true to say we were able to do it. */
  return true;
}


/* Blit API Entry Functions. */

/*
 * init - called once on startup, to initialise the game.
 */

void init( void )
{
  /* We want to run in hi res mode. */
  blit::set_screen_mode( blit::ScreenMode::hires );

  /* Blank the screen to our traditional dark blue. */
  blit::screen.pen = blit::Pen( 0, 0, 50 );
  blit::screen.clear();

  /* Initialise the state array to nulls. */
  for ( uint8_t l_state_idx = STATE_NONE; l_state_idx < STATE_MAX; l_state_idx++ )
  {
    m_states[l_state_idx] = nullptr;
  }

  /* Create our Managers, which will interface with assets and outputs. */
  m_asset_manager = new AssetManager();
  m_output_manager = new OutputManager();

  /* And create all the individual state handlers. */
  m_states[STATE_SPLASH] = new SplashState( STATE_SPLASH );

  /* Lastly, set our opening state to the splash. */
  m_state = STATE_SPLASH;
  blitroids_state_init( STATE_NONE );

  /* All done. */
  return;
}


/*
 * update - called every tick to update the internal state of the game. This
 *          is driven by the engine, and is called approximately every 10ms.
 *
 * uint32_t - the elapsed time (in ms) since the game launched.
 */

void update( uint32_t p_time )
{
  state_t l_previous_state, l_next_state;

  /*
   * We'll check the main menu key outside of the normal state engine; if we're
   * not in the menu switch to that state, regardless of what else is going on.
   */
  if ( ( STATE_MENU != m_state ) && ( blit::buttons.pressed & blit::Button::MENU ) )
  {
    /* So, tell the current state we're going into the menu. */
    blitroids_state_fini( STATE_MENU );

    /* Switch into the menu state. */
    l_previous_state = m_state;
    m_state = STATE_MENU;

    /* And initialise the menu. */
    blitroids_state_init( l_previous_state );
  }

  /*
   * Now we just pass the update handling through to our current state,
   * to keep the processing out of here as much as possible.
   */
  if ( nullptr != m_states[m_state] )
  {
    /* The handler tells us what state we should end up in. */
    l_next_state = m_states[m_state]->update( p_time );

    /* If it's changed (and it's valid), then switch. */
    if ( ( l_next_state != m_state ) && ( nullptr != m_states[l_next_state] ) )
    {
      /* Finish the current state, telling it what will be the new one. */
      blitroids_state_fini( l_next_state );

      /* Switch to the new one. */
      l_previous_state = m_state;
      m_state = l_next_state;

      /* And then initialise it. */
      blitroids_state_init( l_previous_state );
    }
  }

  /* All done. */
  return;
}


/*
 * render - called every frame to render the screen. This is driven by the 
 *          engine, and is called approximately every 20ms, although frames
 *          can be skipped if there isn't enough time.
 *
 * uint32_t - the elapsed time (in ms) since the game launched.
 */

void render( uint32_t p_time )
{
  /* As with update(), we basically just hand this off to the states. */
  if ( nullptr != m_states[m_state] )
  {
    m_states[m_state]->render( p_time );
  }

  /* All done. */
  return;
}


/* End of file blitroids.cpp */
