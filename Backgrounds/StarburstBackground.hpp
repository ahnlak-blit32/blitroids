/*
 * StarburstBackground.hpp - part of Blitroids, a 32Blit game.
 *
 * The StarburstBackground renders a background of pixel stars on a dark
 * backdrop, bursting out from a single point and accelerating to the edges.
 * By default the origin is the center of the screen, but this can be
 * configured along with the star density and speed.
 *
 * Copyright (C) 2021 Pete Favelle <pete@fsquared.co.uk>
 *
 * This file is released under the MIT License; see LICENSE for more details.
 */

#ifndef   _STARBURSTBACKGROUND_HPP_
#define   _STARBURSTBACKGROUND_HPP_

#include "32blit.hpp"
#include "BackgroundInterface.hpp"


/* Constants & Macros. */

/* Enums. */

/* Structs. */

typedef struct 
{
  bool        visible;
  blit::Vec2  location;
  blit::Vec2  vector;
  blit::Pen   colour;
} _star_t;


/* Classes. */

class StarburstBackground : public BackgroundInterface
{
private:
  blit::Point     c_origin;
  uint16_t        c_density = 0;
  uint8_t         c_velocity;
  _star_t        *c_stars = nullptr;
  blit::Point     c_tl_distance;
  blit::Point     c_br_distance;
  
public:
                  StarburstBackground( void );
                 ~StarburstBackground();

  void            set_origin( blit::Point );
  void            set_density( uint16_t );

  void            update( uint32_t );
  void            render( uint32_t );
  void            init( void );
  void            fini( void );

};


#endif /* _STARBURSTBACKGROUND_HPP_ */

/* End of file StarburstBackground.hpp */
