/*
 * StarburstBackground.cpp - part of Blitroids, a 32Blit game.
 *
 * The SplashState renders the splash screen, when the game is first loaded,
 * and possibly after the game is over.
 *
 * Copyright (C) 2021 Pete Favelle <pete@fsquared.co.uk>
 *
 * This file is released under the MIT License; see LICENSE for more details.
 */

/* System headers. */


/* Local headers. */

#include "32blit.hpp"
#include "StarburstBackground.hpp"


/* Module variables. */


/* Functions. */

/*
 * StarburstBackground - constructor for the background, setting defaults.
 */

StarburstBackground::StarburstBackground( void )
{
  /* Default to the origin being the center of the screen. */
  set_origin( blit::screen.clip.center() );

  /* And a sensible density and velocity for the star field. */
  set_density( 200 );
  c_velocity = 5;

  /* All done. */
  return;
}


/*
 * ~StarburstBackground - destructor, cleans up anything we allocated.
 */

StarburstBackground::~StarburstBackground()
{
  /* All done. */
  return;
}


/*
 * set_origin - (re) sets the origin from which all the stars burst.
 *
 * blit::Point - the point on the screen to use
 */

void StarburstBackground::set_origin( blit::Point p_origin )
{
  /* Save the new origin, clamped to the screen. */
  c_origin = blit::screen.clip.clamp( p_origin );

  /* And calculate the distances to the corners, for vector factoring. */
  c_tl_distance = c_origin;
  c_br_distance.x = blit::screen.bounds.w - c_origin.x;
  c_br_distance.y = blit::screen.bounds.h - c_origin.y;

  /* All done. */
  return;
}


/*
 * set_density - (re)sets the target number of stars to be rendered.
 *
 * uint16_t - the new star density
 */

void StarburstBackground::set_density( uint16_t p_density )
{
  uint16_t  l_index;
  _star_t  *l_new_array;

  /* We'll just (re) allocate the star array for this to start. */
  l_new_array = (_star_t *)reallocarray( c_stars, p_density, sizeof( _star_t ) );
  if ( nullptr == l_new_array )
  {
    /* Memory allocation has failed, we can't proceed. */
    return;
  }

  /* Any new stars, need zeroing. */
  for( l_index = c_density; l_index < p_density; l_index++ )
  {
    l_new_array[l_index].visible = false;
  }

  /* Lastly, save the new array and density. */
  c_stars = l_new_array;
  c_density = p_density;
}


/*
 * update - called every tick (10ms) to update our internal state.
 *
 * uint32_t - the time in milliseconds since the epoch.
 */

void StarburstBackground::update( uint32_t p_time )
{
  uint16_t  l_index;
  uint16_t  l_new_stars = ( c_density / ( 100 * c_density ) ) + 1;
  float     l_dx, l_dy;

  /* Scan through all the stars. */
  for ( l_index = 0; l_index < c_density; l_index++ )
  {
    /* If the star isn't visible, and we haven't hit our threshold of new */
    /* ones, then set it to the origin and randomise vector / colour.     */
    if ( ( !c_stars[l_index].visible ) && ( l_new_stars > 0 ) )
    {
      /* Make it visible and start at our location. */
      c_stars[l_index].visible = true;
      c_stars[l_index].location.x = c_origin.x;
      c_stars[l_index].location.y = c_origin.y;

      /* Randomize our colour; we need to be bright, probably. */
      c_stars[l_index].colour.r = 200 ; //+ ( blit::random() % 50 );
      c_stars[l_index].colour.g = 200 ; //+ ( blit::random() % 50 );
      c_stars[l_index].colour.b = 200 ; //+ ( blit::random() % 50 );

      /* Set the vector to straight up at our main velocity. */
      c_stars[l_index].vector = blit::Vec2( 0, c_velocity / 10.0f );

      /* And rotate it a random amount. */
      c_stars[l_index].vector.rotate( ( blit::random() % 360 ) * M_PI / 180.0f );

      /* Lastly, keep track of new stars we've made. */
      l_new_stars--;
    }

    /* For each visible star, update it's location. */
    if ( c_stars[l_index].visible )
    {
      /* Work out how far we are from the origin. */
      if ( c_stars[l_index].vector.x < 0 )
      {
        l_dx = ( c_tl_distance.x + c_stars[l_index].location.x ) / c_tl_distance.x;
      }
      else
      {
        l_dx = ( c_br_distance.x * 2 + c_origin.x - c_stars[l_index].location.x ) / c_br_distance.x;
      }
      if ( c_stars[l_index].vector.y < 0 )
      {
        l_dy = ( c_tl_distance.y + c_stars[l_index].location.y ) / c_tl_distance.y;
      }
      else
      {
        l_dy = ( c_br_distance.y * 2 + c_origin.y - c_stars[l_index].location.y ) / c_br_distance.y;
      }

      /* Move it. */
      c_stars[l_index].location.x += c_stars[l_index].vector.x * l_dx;
      c_stars[l_index].location.y += c_stars[l_index].vector.y * l_dy;

      /* The alpha is tempered by the proximity to the origin. */
      if ( l_dx > 1.7f && l_dy > 1.7f )
      {
        if ( l_dx > l_dy )
        {
          c_stars[l_index].colour.a = 50 + ( 2.0f - l_dx ) * 1000.0f;
        }
        else
        {
          c_stars[l_index].colour.a = 50 + ( 2.0f - l_dy ) * 1000.0f;
        }
      }
      else
      {
        c_stars[l_index].colour.a = 255;
      }

      /* And see if we've dropped off the screen. If so, we become invisible. */
      if ( !blit::screen.clip.contains( c_stars[l_index].location ) )
      {
        c_stars[l_index].visible = false;
      }
    }
  }

  /* All done. */
  return;
}


/*
 * render - called every frame (20ms) to draw our internal state to the screen!
 *
 * uint32_t - the time in milliseconds since the epoch.
 */

void StarburstBackground::render( uint32_t p_time )
{
  uint16_t  l_index;

  /* Clear the screen. */
  blit::screen.pen = blit::Pen( 10, 10, 40 );
  blit::screen.clear();

  /* Work though all our stars, rendering all the visible ones. */
  for ( l_index = 0; l_index < c_density; l_index++ )
  {
    /* Only worry about visible ones. */
    if ( !c_stars[l_index].visible )
    {
      continue;
    }

    /* So, switch to the pen. */
    blit::screen.pen = c_stars[l_index].colour;

    /* And draw a pixel! */
    blit::screen.pixel( c_stars[l_index].location );
  }

  /* All done. */
  return;
}


/*
 * init - called any time the background is activated, or woken up.
 */

void StarburstBackground::init( void )
{
  /* All done. */
  return;
}


/*
 * fini - called any time the background is being de-activated
 */

void StarburstBackground::fini( void )
{
  /* All done. */
  return;
}


/* End of file StarburstBackground.cpp */
