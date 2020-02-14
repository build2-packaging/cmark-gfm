/*
 * file      : tests/basic/driver.c
 * license   : FreeBSD License; see accompanying COPYING file
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>

#include <cmark-gfm.h>
#include <cmark-gfm-extension_api.h>
#include <cmark-gfm-core-extensions.h>

int
main (int argc, const char* argv[])
{
  assert (argc == 2);

  const char* from = argv[1];

  cmark_gfm_core_extensions_ensure_registered ();

  cmark_parser* p = cmark_parser_new (CMARK_OPT_DEFAULT |
                                      CMARK_OPT_VALIDATE_UTF8);

  cmark_syntax_extension* e = cmark_find_syntax_extension ("strikethrough");
  cmark_parser_attach_syntax_extension (p, e);


  cmark_parser_feed (p, from, strlen (from));

  cmark_node* doc = cmark_parser_finish (p);

  char* to = cmark_render_html (doc,
                                CMARK_OPT_DEFAULT,
                                NULL /* extensions */);

  printf ("%s", to);

  cmark_get_default_mem_allocator ()->free (to);
  cmark_node_free (doc);
  cmark_parser_free (p);

  return 0;
}
