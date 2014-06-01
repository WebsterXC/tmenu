/*
Copyright 2014 Dario Hamidi

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "util.h"

#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void* must_malloc(size_t n) {
   void* buffer = calloc(1, n);
   if (buffer == 0) {
      int error = errno;
      fprintf(stderr, "%s: failed to allocate buffer of size %ld: %s\n",
              PROGRAM_NAME, (long int)n, strerror(error));
      abort();
   }

   return buffer;
}
