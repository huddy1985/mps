/* impl.c.protsw: SCRIPTWORKS MEMORY PROTECTION
 *
 * $HopeName: MMsrc!protsw.c(trunk.5) $
 * Copyright (C) 1997 Harlequin Limited.  All rights reserved.
 *
 * DESIGN
 *
 * Implements no protection.
 */

#include "mpm.h"

#ifndef PROTECTION_NONE
#error "protsw.c implements no protection, but PROTECTION_NONE is not set"
#endif

SRCID(protsw, "$HopeName: MMsrc!protsw.c(trunk.5) $");


/* ProtSetup -- global protection setup */

void ProtSetup(void)
{
  NOOP;
}


/* ProtSet -- set the protection for a page */

void ProtSet(Addr base, Addr limit, AccessSet pm)
{
  UNUSED(base); UNUSED(limit); UNUSED(pm);
  NOTREACHED;
}


/* ProtSync -- synchronize protection settings with hardware */

void ProtSync(Arena arena)
{
  UNUSED(arena);
  NOOP;
}


/* ProtTramp -- protection trampoline */

void ProtTramp(void **rReturn, void *(*f)(void *p, size_t s),
               void *p, size_t s)
{
  AVER(rReturn != NULL);
  AVER(FUNCHECK(f));
  /* Can't check p and s as they are interpreted by the client */

  *(rReturn) = (*(f))(p, s);
}
