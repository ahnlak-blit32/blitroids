/*
 * BackgroundInterface.hpp - part of Blitroids, a 32Blit game.
 *
 * This defines a standard Interface for Backgrounds; these are classes that
 * know how to draw specialised backdrops. Done generically for re-use.
 *
 * Copyright (C) 2021 Pete Favelle <pete@fsquared.co.uk>
 *
 * This file is released under the MIT License; see LICENSE for more details.
 */

#ifndef   _BACKGROUNDINTERFACE_HPP_
#define   _BACKGROUNDINTERFACE_HPP_


/* Interfaces. */

class BackgroundInterface
{
public:
  virtual        ~BackgroundInterface() {};
  virtual void    update( uint32_t ) = 0;
  virtual void    render( uint32_t ) = 0;
  virtual void    init( void ) = 0;
  virtual void    fini( void ) = 0;
};


#endif /* _STATEINTERFACE_HPP_ */

/* End of file BackgroundInterface.hpp */
