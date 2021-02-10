/*
 * OutputManager.cpp - part of Blitroids, a 32Blit game.
 *
 * The OutputManager initialises handles all the output channels, both audio
 * and haptic. Done in one place to make it easy to configure them globally,
 * as well as dealing with any scheduling shuffling.
 *
 * Copyright (C) 2021 Pete Favelle <pete@fsquared.co.uk>
 *
 * This file is released under the MIT License; see LICENSE for more details.
 */

/* System headers. */


/* Local headers. */

#include "32blit.hpp"
#include "blitroids.hpp"
#include "OutputManager.hpp"


/* Module variables. */


/* Functions. */

/*
 * OutputManager - constructor, which basically just loads everything up
 *                 if we can, setting sensible defaults as we go.
 */

OutputManager::OutputManager( void )
{
  /* Try and load any flag settings we may have. */
  if ( !blit::read_save( c_flags, SAVE_SLOT_OUTPUTS ) )
  {
    /* Then set the flags to some reasonable-sounding defaults. */
    c_flags.sound_enabled = true;
    c_flags.music_enabled = true;
    c_flags.haptic_enabled = true;
  }

  /* Set any channel defaults we have. */

  /* All done. */
  return;
}


/*
 * ~OutputManager - destructor, and cleanup that needs doing. 
 */

OutputManager::~OutputManager()
{
  /* All done. */
  return;
}


/* End of file OutputManager.cpp */
