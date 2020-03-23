cmake_minimum_required(VERSION 3.5)

project(barcode LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/ssl/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/ssl/libssl.so)
#    endif()
#endif()

#message( "------------------------------------------------" )
#message( ${ANDROID_EXTRA_LIBS} )
#message (${ANDROID_ABI})
#message( "------------------------------------------------" )
##message( ${CMAKE_CURRENT_SOURCE_DIR} )

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "/home/android/my/output/lib/android-arm/")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            libcrypto.so
#            libssl.so)
#    endif()
#endif()


find_package(Qt5 COMPONENTS Core Quick REQUIRED)

if(ANDROID)
    add_library(barcode SHARED
      main.cpp
      Groups/Groups.cc
      Groups/Groups_init.cc
      Groups/Groups.h
      Groups/Article.cc
      Groups/Articles.cc
      Groups/Articles.h
      Groups/ArticlesLFF.cc
#      Groups/Articles-load_from_file.cc
      Groups/Item.cc
      Groups/Item.h
      Info.cc
      Info.h
      qml.qrc
    )
else()
    add_executable(barcode
      main.cpp
      Groups/Groups.cc
      Groups/Groups_init.cc
      Groups/Groups.h
      Groups/Article.cc
      Groups/Articles.cc
      Groups/Articles.h
      Groups/ArticlesLFF.cc
      Groups/Item.cc
      Groups/Item.h
      Info.cc
      Info.h
      qml.qrc
    )
endif()

target_compile_definitions(barcode
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(barcode
  PRIVATE Qt5::Core Qt5::Quick ${ANDROID_EXTRA_LIBS} )
