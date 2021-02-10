/*
 * AssetManager.cpp - part of Blitroids, a 32Blit game.
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
#include "AssetManager.hpp"


/* Module variables. */


/* Functions. */

/*
 * AssetManager - constructor, which basically just loads everything up
 *                if we can, setting sensible defaults as we go.
 */

AssetManager::AssetManager( void )
{
  /* All done. */
  return;
}


/*
 * ~AssetManager - destructor, and cleanup that needs doing. 
 */

AssetManager::~AssetManager()
{
  /* All done. */
  return;
}


/* End of file AssetManager.cpp */
