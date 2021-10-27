# file      : buildfile
# license   : BSD 2-Clause "Simplified" License; see accompanying COPYING file

# Glue buildfile that "pulls" all the packages.

import pkgs = {*/ -upstream/}
./: $pkgs
