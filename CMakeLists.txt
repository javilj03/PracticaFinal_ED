cmake_minimum_required(VERSION 3.16)
project(practicafinal)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

set(BASE_FOLDER rutas_aereas)

include_directories(${BASE_FOLDER}/include)


add_library(image ${BASE_FOLDER}/src/Imagen.cpp  ${BASE_FOLDER}/src/imagenES.cpp ${BASE_FOLDER}/src/Punto.cpp ${BASE_FOLDER}/src/Pixel.cpp ${BASE_FOLDER}/src/Pais.cpp ${BASE_FOLDER}/src/Ruta.cpp ${BASE_FOLDER}/src/AlmacenRuta.cpp ${BASE_FOLDER}/src/Paises.cpp)

if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/Tests/paises_test.cpp)
    add_executable(paises_test ${BASE_FOLDER}/Tests/paises_test.cpp)
    target_link_libraries(paises_test LINK_PUBLIC image)
endif()

if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/Tests/imagenES_test.cpp)
    add_executable(imagenES_test ${BASE_FOLDER}/Tests/imagenES_test.cpp)
    target_link_libraries(imagenES_test LINK_PUBLIC image)
endif()

if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/Tests/pais_test.cpp)
    add_executable(pais_test ${BASE_FOLDER}/Tests/pais_test.cpp)
    target_link_libraries(pais_test LINK_PUBLIC image)
endif()

if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/pruebarotacion.cpp)
add_executable(pruebarotacion ${BASE_FOLDER}/src/pruebarotacion.cpp)
target_link_libraries(pruebarotacion LINK_PUBLIC image)
endif()
if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/pruebaAlmacenRuta.cpp)
    add_executable(pruebaAlmacenRuta ${BASE_FOLDER}/src/pruebaAlmacenRuta.cpp)
    target_link_libraries(pruebaAlmacenRuta LINK_PUBLIC image)
endif()
if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/pruebapegado.cpp)
add_executable(pruebapegado ${BASE_FOLDER}/src/pruebapegado.cpp)
target_link_libraries(pruebapegado LINK_PUBLIC image)
endif()

if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/ruta_aerea.cpp)
add_executable(ruta_aerea ${BASE_FOLDER}/src/ruta_aerea.cpp)
target_link_libraries(ruta_aerea LINK_PUBLIC image)
endif()

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM )
else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)
