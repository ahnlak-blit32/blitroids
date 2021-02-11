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

#define SAVE_SLOT_HISCORE 0
#define SAVE_SLOT_OUTPUTS 1

#define DEBUG 1
#define debug_printf(fmt, ...) \
        do { if (DEBUG) fprintf(stderr, "%s(%d): " fmt, \
                                __func__, __LINE__, __VA_ARGS__); } while (0)


/* Enums. */

/* Structs. */


#endif /* _BLITROIDS_HPP_ */

/* End of file blitroids.hpp */
