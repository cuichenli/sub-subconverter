find_path(QuickJS_INCLUDE_DIR
    NAMES "quickjs.h"
    PATHS "${CMAKE_SOURCE_DIR}/deps/include/quickjs/")

find_library(
    QuickJS_LIBRARY 
    NAMES libquickjs.a
    PATHS  "${CMAKE_SOURCE_DIR}/deps/lib/quickjs/"
)

set(QuickJS_LIBRARIES "${QuickJS_LIBRARY}")
set(QuickJS_INCLUDE_DIRS "${QuickJS_INCLUDE_DIR} ${DATE_INCLUDE_DIR}")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(QuickJS DEFAULT_MSG
    QuickJS_INCLUDE_DIRS QuickJS_LIBRARY)

mark_as_advanced(QuickJS_INCLUDE_DIRS)
