set(GTESTBADGE_HEADER_FILES ""
  ${GTESTBADGE_INCLUDE_DIR}/gtestbadge/Badge.h
  ${GTESTBADGE_INCLUDE_DIR}/gtestbadge/BadgeEventListener.h
)

add_library(gtestbadge STATIC
  ${GTESTBADGE_HEADER_FILES}
  ${GTESTBADGE_EXPORT_HEADER}
  ${GTESTBADGE_VERSION_HEADER}
  ${GTESTBADGE_CONFIG_HEADER}
  Badge.cpp
  BadgeEventListener.cpp
  BadgeTemplate.cpp
  BadgeTemplate.h
  main.cpp
  verdana.h
)

# Force CMAKE_DEBUG_POSTFIX for executables
set_target_properties(gtestbadge PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

# Define include directories for exported code.
target_include_directories(gtestbadge
  PUBLIC
    $<INSTALL_INTERFACE:${GTESTBADGE_INSTALL_INCLUDE_DIR}>  # for clients using the installed library.
  PRIVATE
    ${GTEST_INCLUDE_DIR}
)
target_link_libraries(gtestbadge PUBLIC rapidassist PRIVATE ${PTHREAD_LIBRARIES} ${GTEST_LIBRARIES} )

install(TARGETS gtestbadge
        EXPORT gtestbadge-targets
        ARCHIVE DESTINATION ${GTESTBADGE_INSTALL_LIB_DIR}
        LIBRARY DESTINATION ${GTESTBADGE_INSTALL_LIB_DIR}
        RUNTIME DESTINATION ${GTESTBADGE_INSTALL_BIN_DIR}
)
