/* Definition for thread-local data handling.  ARM/Linux version.
   Copyright (C) 2005-2015 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library.  If not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef _LINUX_ARM_TLS_H
#define _LINUX_ARM_TLS_H	1

/* Almost everything is OS-independent and common for all NPTL on ARM.  */
#include <sysdeps/arm/nptl/tls.h>

#ifndef __ASSEMBLER__

/* Get system call information.  */
# include <sysdep.h>

/* Code to initially initialize the thread pointer.  This might need
   special attention since 'errno' is not yet available and if the
   operation can cause a failure 'errno' must not be touched.  */
# define TLS_INIT_TP(tcbp) \
  ({ void** real_tls; __asm__("mrc p15, 0, %0, c13, c0, 3" : "=r"(real_tls)); real_tls[63] = tcbp; NULL; })

#endif /* __ASSEMBLER__ */

#endif  /* tls.h */
