/*
 * blitroids.hpp - part of Blitroids, a 32Blit game.
 *
 * This is the main header for the project, and defines all our structures
 * and constants.
 *
 * Copyright (C) 2021 Pete Favelle <pete@fsquared.co.uk>
 *
 * This file is released under the MIT License; see LICENSE for more details.
 */

#ifndef   _BLITROIDS_HPP_
#define   _BLITROIDS_HPP_

/* Constants & Macros. */

#define DEBUG 1
#define debug_printf(fmt, ...) \
        do { if (DEBUG) fprintf(stderr, "%s(%d): " fmt, \
                                __func__, __LINE__, __VA_ARGS__); } while (0)


/* Enums. */

typedef enum
{
  STATE_NONE,
  STATE_SPLASH,
  STATE_GAME,
  STATE_DEATH,
  STATE_HISORE,
  STATE_MENU,
  STATE_MAX
} gamestate_t;


/* Structs. */

/* Interfaces. */

class GameStateInterface
{
  public:
    virtual gamestate_t update( uint32_t ) = 0;
    virtual void        render( uint32_t ) = 0;
    virtual void        init( GameStateInterface * ) = 0;
    virtual void        fini( GameStateInterface * ) = 0;
};


#endif /* _BLITROIDS_HPP_ */

/* End of file blitroids.hpp. */
