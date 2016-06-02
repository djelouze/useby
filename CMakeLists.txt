cmake_minimum_required(VERSION 3.0)
project(useby)

set( UB_AUTHENTIFICATION_KEY "UB_FORCE_KEY-NOTFOUND" CACHE STRING "Hard-coded key")
set( UB_DEADLINE "0000-00-00" CACHE STRING "Day after which the authorization fails. in ISO-8601 format")
set( UB_KEY_GENERATOR "UB_KEY_GENERATOR-NOTFOUND" CACHE FILEPATH "Path to executable that outputs a key")
set( UB_KEY_GENERATOR_PATH "UB_KEY_GENERATOR_PATH-NOTFOUND" CACHE PATH "Path to executable that outputs a key")
set( UB_KEY_GENERATOR_ARGS "" CACHE STRING "optional arguments for the key generator")
set( UB_OUTPUT_DIR "UB_OUTPUT_DIR-NOTFOUND" CACHE PATH "Where to put the dll")

if( NOT UB_AUTHENTIFICATION_KEY )
  execute_process(COMMAND "${UB_KEY_GENERATOR}" "${UB_KEY_GENERATOR_ARGS}"
	  WORKING_DIRECTORY  ${UB_KEY_GENERATOR_PATH}
	  OUTPUT_VARIABLE UB_AUTHENTIFICATION_KEY
	  )
endif()

configure_file(usebyConfig.h.in usebyConfig.h)

IF( UB_OUTPUT_DIR )
  SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${UB_OUTPUT_DIR})
  SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${UB_OUTPUT_DIR})
ENDIF()

include_directories(${CMAKE_BINARY_DIR})
add_library( useby SHARED useby.cxx )
install( TARGETS useby DESTINATION bin)

ADD_CUSTOM_COMMAND(TARGET useby 
	PRE_BUILD
	COMMAND ${CMAKE_COMMAND} ARGS -E touch ${CMAKE_CURRENT_LIST_FILE}
	) 
