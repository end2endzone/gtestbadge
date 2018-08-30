add_executable(gtestbadge_unittest
  ${GTESTBADGE_EXPORT_HEADER}
  ${GTESTBADGE_VERSION_HEADER}
  ${GTESTBADGE_CONFIG_HEADER}
  main.cpp
  ImageListBuilder.cpp
  ImageListBuilder.h
  TestBadge.cpp
  TestBadge.h
  TestBadgeEventListener.cpp
  TestBadgeEventListener.h
  TestBar.cpp
  TestBar.h
  TestFoo.cpp
  TestFoo.h
)

# Unit test projects requires to link with pthread if also linking with gtest
if(NOT WIN32)
  set(PTHREAD_LIBRARIES -pthread)
endif()

# Force CMAKE_DEBUG_POSTFIX for executables
set_target_properties(gtestbadge_unittest PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

target_include_directories(gtestbadge_unittest PRIVATE rapidassist)
target_include_directories(gtestbadge_unittest PRIVATE ${GTEST_INCLUDE_DIR})
add_dependencies(gtestbadge_unittest gtestbadge)
target_link_libraries(gtestbadge_unittest PUBLIC rapidassist gtestbadge ${PTHREAD_LIBRARIES} ${GTEST_LIBRARIES} )

install(TARGETS gtestbadge_unittest
        EXPORT gtestbadge-targets
        ARCHIVE DESTINATION ${GTESTBADGE_INSTALL_LIB_DIR}
        LIBRARY DESTINATION ${GTESTBADGE_INSTALL_LIB_DIR}
        RUNTIME DESTINATION ${GTESTBADGE_INSTALL_BIN_DIR}
)
