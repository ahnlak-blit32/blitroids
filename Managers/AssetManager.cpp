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

#include "blitstrings.hpp"
#include "AssetsImages.hpp"
#include "AssetManager.hpp"


/* Functions. */

/*
 * AssetManager - constructor, which basically just loads everything up
 *                if we can, setting sensible defaults as we go.
 */

AssetManager::AssetManager( void )
{
  /* Load the images into Surfaces. */
  c_img_logo = blit::Surface::load_read_only( a_img_logo );
  c_img_spritesheet = blit::Surface::load_read_only( a_img_spritesheet );

  /* All done. */
  return;
}


/*
 * ~AssetManager - destructor, and cleanup that needs doing. 
 */

AssetManager::~AssetManager()
{
  /* Throw away our image Surfaces. */
  if ( nullptr != c_img_logo )
  {
    delete c_img_logo;
    c_img_logo = nullptr;
  }
  if ( nullptr != c_img_spritesheet )
  {
    delete c_img_spritesheet;
    c_img_spritesheet = nullptr;
  }

  /* All done. */
  return;
}


/*
 * set_language - sets the language of strings to be returned.
 *
 * blit_lang_t, the language to use - this type defined in blitstrings.hpp
 */

void AssetManager::set_language( blit_lang_t p_language )
{
  c_language = p_language;
  return;
}


/*
 * get_language - fetches the language currently used for strings.
 */

blit_lang_t AssetManager::get_language( void )
{
  return c_language;
}


/*
 * get_string - returns the appropriate string for the identifier. 
 *
 * blit_string_t; the id of the string requested.
 */

const char *AssetManager::get_string( blit_string_t p_string )
{
  /* Essentially, we just look up the appropriate entry in the big array */
  /* defined at the project level by blitstrings.hpp                     */
  return g_blit_string[c_language][p_string];
}


/* End of file AssetManager.cpp */
