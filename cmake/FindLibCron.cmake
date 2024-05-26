find_path(LIBCRON_INCLUDE_DIR
    NAMES "Cron.h"
    PATHS "${CMAKE_SOURCE_DIR}/deps/include/libcron/")
find_path(
    DATE_INCLUDE_DIR 
    NAMES "date.h"
    PATHS "${CMAKE_SOURCE_DIR}/deps/include/date/")


find_library(
    LIBCRON_LIBRARY 
    NAMES liblibcron.a
    PATHS "${CMAKE_SOURCE_DIR}/deps/lib/"
)

set(LIBCRON_LIBRARIES "${LIBCRON_LIBRARY}")
set(LIBCRON_INCLUDE_DIRS "${LIBCRON_INCLUDE_DIR} ${DATE_INCLUDE_DIR}")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(LibCron DEFAULT_MSG
    LIBCRON_INCLUDE_DIRS LIBCRON_LIBRARY)

mark_as_advanced(LIBCRON_INCLUDE_DIRS)
