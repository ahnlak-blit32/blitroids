/*
 * blitstrings.hpp - part of Blitroids, a 32Blit game.
 *
 * This defines all the strings displayed to the user; these are split out
 * to make it easy(er) for both translations, and to have platform-specific
 * messages (for example, translating button presses).
 *
 * Longer term, there will be a tool to dynamically create this from translation
 * files, but that will have to wait for me to understand CMake better!
 *
 * Copyright (C) 2021 Pete Favelle <pete@fsquared.co.uk>
 *
 * This file is released under the MIT License; see LICENSE for more details.
 */

#ifndef   _BLITSTRINGS_HPP_
#define   _BLITSTRINGS_HPP_


/* Enums. */

typedef enum 
{
  STR_TITLE,
  STR_BTN_A_TO_START,
  STR_MAX
} blit_string_t;

typedef enum 
{
  LANG_EN,
  LANG_MAX
} blit_lang_t;


/* The global string lookup array. */

extern const char *g_blit_string[LANG_MAX][STR_MAX];


#endif /* _BLITSTRINGS_HPP_ */

/* End of file blitstrings.hpp */
