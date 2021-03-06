/*
  Copyright (C) 2019 SUSE LLC
  Author: Pascal Arlt <parlt@suse.com>

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include "libeconf.h"

static const char *messages[] = {
  "Success", /* ECONF_SUCCESS */
  "Unknown error", /* ECONF_ERROR */
  "Out of memory", /* ECONF_NOMEM */
  "Configuration file not found", /*ECONF_NOFILE */
  "Group not found", /* ECONF_NOGROUP */
  "Key not found", /* ECONF_NOKEY */
  "Key has empty value", /* ECONF_EMPTYKEY */
  "Error creating or writing to a file", /* ECONF_WRITEERROR */
  "Parse error" /* ECONF_PARSE_ERROR */
};

const char *
econf_errString (const econf_err error)
{
  if (error >= sizeof(messages)/sizeof(messages[0]))
    {
      static char buffer[1024]; /* should always be big enough, else truncate */
      const char *unknown = "Unknown libeconf error %i";

      snprintf (buffer, sizeof (buffer) - 1, unknown, error);
      buffer[sizeof(buffer)-1] = '\0';

      return buffer;
    }
  else
    return messages[error];
}
