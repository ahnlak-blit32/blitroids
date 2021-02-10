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

#include "AssetsFonts.hpp"


/* Constants & Macros. */

/* Enums. */

/* Structs. */

/* Classes. */

class AssetManager
{
private:

public:
                    AssetManager( void );
                   ~AssetManager();

  const blit::Font  font_null = blit::Font( a_font_null16 );

};


#endif /* _ASSETMANAGER_HPP_ */

/* End of file AssetManager.hpp */
