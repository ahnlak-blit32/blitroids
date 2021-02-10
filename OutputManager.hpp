/*
 * OutputManager.hpp - part of Blitroids, a 32Blit game.
 *
 * The OutputManager initialises handles all the output channels, both audio
 * and haptic. Done in one place to make it easy to configure them globally,
 * as well as dealing with any scheduling shuffling.
 *
 * Copyright (C) 2021 Pete Favelle <pete@fsquared.co.uk>
 *
 * This file is released under the MIT License; see LICENSE for more details.
 */

#ifndef   _OUTPUTMANAGER_HPP_
#define   _OUTPUTMANAGER_HPP_

/* Constants & Macros. */

/* Enums. */

/* Structs. */

typedef struct
{
  bool  sound_enabled;
  bool  music_enabled;
  bool  haptic_enabled;
} output_flags_t;

/* Classes. */

class OutputManager
{
private:
  output_flags_t  c_flags;

public:
                  OutputManager( void );
                 ~OutputManager();
};


#endif /* _OUTPUTMANAGER_HPP_ */

/* End of file OutputManager.hpp */
