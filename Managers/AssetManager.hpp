/*
 * AssetManager.hpp - part of Blitroids, a 32Blit game.
 *
 * The AssetManager initialises all the assets in one place, to keep everything
 * neat and tidy. Managers are created in the main init, and passed into each
 * GameState object in turn.
 *
 * Copyright (C) 2021 Pete Favelle <pete@fsquared.co.uk>
 *
 * This file is released under the MIT License; see LICENSE for more details.
 */

#ifndef   _ASSETMANAGER_HPP_
#define   _ASSETMANAGER_HPP_

#include "blitstrings.hpp"
#include "AssetsFonts.hpp"


/* Constants & Macros. */

/* Enums. */

/* Structs. */

/* Classes. */

class AssetManager
{
private:
  blit_lang_t       c_language;

public:
                    AssetManager( void );
                   ~AssetManager();

  blit::Surface    *c_img_logo;
  blit::Surface    *c_img_spritesheet;

  const blit::Font  font_null = blit::Font( a_font_null16 );

  void              set_language( blit_lang_t );
  blit_lang_t       get_language( void );
  const char       *get_string( blit_string_t );

};


#endif /* _ASSETMANAGER_HPP_ */

/* End of file AssetManager.hpp */
