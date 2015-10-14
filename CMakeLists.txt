cmake_minimum_required(VERSION 3.0)
project(useby)

set( UB_AUTHENTIFICATION_KEY "0" CACHE STRING "key return to caller") 
set( UB_DEADLINE "0000-00-00" CACHE STRING "Day after which the authorization fails. in ISO-8601 format")

configure_file(usebyConfig.h.in usebyConfig.h)

add_library( useby SHARED useby.cxx )


