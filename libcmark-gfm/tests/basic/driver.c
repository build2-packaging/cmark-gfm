/* file      : tests/basic/driver.c
 * license   : FreeBSD License; see accompanying COPYING file
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>

#include <cmark-gfm.h>
#include <cmark-gfm-extension_api.h>

int
main (int argc, const char* argv[])
{
  assert (argc == 2);

  const char* from = argv[1];

  char* to = cmark_markdown_to_html (from,
                                     strlen (from),
                                     CMARK_OPT_DEFAULT |
                                     CMARK_OPT_VALIDATE_UTF8);
  printf ("%s", to);
  cmark_get_default_mem_allocator ()->free (to);
  return 0;
}
