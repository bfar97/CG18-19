cmake_minimum_required(VERSION 2.8)

# Project Name
PROJECT(Engine)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)



if (NOT APPLE)
	if (WIN32)
		set(TOOLKITS_FOLDER "" CACHE PATH "Path to toolkits folder")
		include_directories(
				${TOOLKITS_FOLDER}/glew
				${TOOLKITS_FOLDER}/glut
				${TOOLKITS_FOLDER}/devil)
		link_directories(
				${TOOLKITS_FOLDER}/glew
				${TOOLKITS_FOLDER}/glut
				${TOOLKITS_FOLDER}/devil)
	else(WIN32)
		find_package(GLEW REQUIRED)
		include_directories(${GLEW_INCLUDE_DIRS})
		link_libraries(${GLEW_LIBRARIES})
	endif(WIN32)
endif(NOT APPLE)

if (NOT WIN32)
	find_package(GLUT REQUIRED)
	include_directories(${GLUT_INCLUDE_DIR})
	link_directories(${GLUT_LIBRARY_DIRS})
	add_definitions(${GLUT_DEFINITIONS})

	find_package(DevIL REQUIRED)
	link_libraries(${IL_LIBRARIES} )
	include_directories(ยง{IL_INCLUDE_DIR})
endif(NOT WIN32)

find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})

add_executable(${PROJECT_NAME} main.cpp ./Deps/tinyxml2.cpp ./Deps/engine.cpp ./Deps/sg.cpp
		./Deps/catmullmath.cpp ./Deps/cronometro.cpp ./Deps/escala.cpp ./Deps/parseBezier.cpp ./Deps/rotacaoT.cpp
		./Deps/rotacaoV.cpp ./Deps/timedsg.cpp ./Deps/translacaoC.cpp ./Deps/translacaoV.cpp
		./Deps/directionLight.cpp ./Deps/pointLight.cpp ./Deps/spotLight.cpp ./Deps/modtex.cpp
		)

file(COPY ${CMAKE_SOURCE_DIR}/Imagens DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/conf.xml DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/esfera.3d DESTINATION ${CMAKE_BINARY_DIR})

if (WIN32)
	target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} glut32 glew32 DevIL)
	file(COPY ${TOOLKITS_FOLDER}/glew/glew32.dll DESTINATION ${CMAKE_BINARY_DIR})
	file(COPY ${TOOLKITS_FOLDER}/glut/glut32.dll DESTINATION ${CMAKE_BINARY_DIR})
	file(COPY ${TOOLKITS_FOLDER}/devil/DevIL.dll DESTINATION ${CMAKE_BINARY_DIR})

else(WIN32)
	target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
endif (WIN32)







