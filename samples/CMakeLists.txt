add_executable(gtestbadge_samples
  ${GTESTBADGE_EXPORT_HEADER}
  ${GTESTBADGE_VERSION_HEADER}
  ${GTESTBADGE_CONFIG_HEADER}
  samples.cpp
)

# Define output directory for samples.
add_definitions(-DSAMPLES_DIRECTORY="${CMAKE_CURRENT_SOURCE_DIR}")

# gtestbadge requires to link with pthread if also linking with gtest
if(NOT WIN32)
  set(PTHREAD_LIBRARIES -pthread)
endif()

# Force CMAKE_DEBUG_POSTFIX for executables
set_target_properties(gtestbadge_samples PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

target_include_directories(gtestbadge_samples PRIVATE rapidassist)
target_include_directories(gtestbadge_samples PRIVATE ${GTEST_INCLUDE_DIR})
add_dependencies(gtestbadge_samples gtestbadge)
target_link_libraries(gtestbadge_samples PUBLIC rapidassist gtestbadge ${PTHREAD_LIBRARIES} ${GTEST_LIBRARIES} )
