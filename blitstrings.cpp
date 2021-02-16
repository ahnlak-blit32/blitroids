/*
 * blitstrings.cpp - part of Blitroids, a 32Blit game.
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

#include "blitstrings.hpp"

/* The global string lookup array. */

const char *g_blit_string[LANG_MAX][STR_MAX] = {

#ifdef    TARGET_32BLIT_HW

  /* LANG_EN */
  {
    "Blitroids",
    "Press <A> To Start"
  },

#else  /* TARGET_32BLIT_HW */

  /* LANG_EN */
  {
    "Blitroids",
    "Press <Z> To Start"
  },

#endif /* TARGET_32BLIT_HW */
};


/* End of file blitstrings.cpp */
