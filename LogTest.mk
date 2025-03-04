# ========================================================================
# Makefile oriented to build a program to test a library.
# ========================================================================

# ==================== CONFIG ============================================
PROJECT_NAME					:= logtest
MAIN							:= LogTest.cpp
LIBS							:=
CFLAGS							:=
CXXFLAGS						:=
LDFLAGS							:=

C_DEPS							:=

CPP_DEPS						:= ANSI/ANSI.cpp
CPP_DEPS						+= StringHelpers/StringHelpers.cpp
CPP_DEPS						+= Log/Log.cpp

INCLUDE							:= .


# =================== INTERNALS ==========================================
EXEC							:= ${PROJECT_NAME}

ifneq (${WINDIR},)
	SYSTEM						:= windows
	EXEC						:= ${EXEC}.exe
else
	UNAME						:= $(shell uname)

	ifeq (${UNAME},Darwin)
		SYSTEM					:= macos
	else ifeq (${UNAME},Linux)
		SYSTEM					:= linux
	else
		SYSTEM					:= other
	endif
endif

OBJ								:= obj
OBJS_PATH						:= ${OBJ}/${SYSTEM}

C_SRCS							:= ${C_DEPS}
CPP_SRCS						:= ${CPP_DEPS}
SRCS							:= $(strip ${C_SRCS} ${CPP_SRCS})

HEADER_PATHS					:= $(sort $(foreach file,${C_DEPS},$(dir ${file})))
HEADER_PATHS					+= $(sort $(foreach file,${CPP_DEPS},$(dir ${file})))
HEADER_PATHS					+= $(sort $(foreach file,${INCLUDE},$(dir ${file})))

INCLUDE							:= $(strip $(foreach inc,${HEADER_PATHS},-I ${inc}))
LIBS							:= $(foreach lib,${LIBS},-l${lib})

C								:= clang
CXX								:= clang++

GLOBAL_FLAGS					:= -Wall -pedantic

CFLAGS							+= ${GLOBAL_FLAGS}
CXXFLAGS						+= ${GLOBAL_FLAGS}

ifdef RELEASE
	CFLAGS						+= -O3
	CXXFLAGS					+= -O3
else
	CFLAGS						+= -g
	CXXFLAGS					+= -g
endif

include Commands.mk
include Functions.mk


# ================ OBJS SEARCH ===========================================
MAIN_OBJ						:= $(call SRC2OBJ,${MAIN})
OBJS							:= $(foreach src,${SRCS},$(call SRC2OBJ,${src}))


# ================ BUILD RECIPES =========================================
.PHONY: all clean info run

all: ${OBJS_PATH} ${EXEC}


clean:
	$(shell ${RMTREE} ${OBJ})
	$(shell ${RM} ${EXEC})


# Builds the executable
${EXEC}: ${OBJS} ${MAIN_OBJ}
ifeq (${MAIN},main.c)
    ${C} ${OBJS} ${MAIN_OBJ} -o ${EXEC} ${LIBS} ${LDFLAGS}
else
	${CXX} ${OBJS} ${MAIN_OBJ} -o ${EXEC} ${LIBS} ${LDFLAGS}
endif


# Builds the main object
${MAIN_OBJ}: ${MAIN}
ifeq ($(suffix ${MAIN}),c)
	${C} -c ${MAIN} -o ${MAIN_OBJ} ${INCLUDE} ${CFLAGS}
else
	${CXX} -c ${MAIN} -o ${MAIN_OBJ} ${INCLUDE} ${CXXFLAGS}
endif


${OBJS_PATH}:
	$(shell ${MKTREE} ${OBJS_PATH})


# Builds all CPP files. Each obj file will be placed under ${OBJS_PATH}
$(foreach src,${C_SRCS},$(eval $(call BUILD_C,${src})))


# Builds all CPP files. Each obj file will be placed under ${OBJS_PATH}
$(foreach src,${CPP_SRCS},$(eval $(call BUILD_CPP,${src})))


info:
	$(info PROJECT_NAME: ${PROJECT_NAME})
	$(info EXEC: ${EXEC})
	$(info CFLAGS: ${CFLAGS})
	$(info CXXFLAGS: ${CXXFLAGS})
	$(info LDFLAGS: ${CXXFLAGS})
	$(info MAIN: ${MAIN})
	$(info MAIN_OBJ: ${MAIN_OBJ})
	$(info OBJS: ${OBJS})
	$(info C_SRCS: ${C_SRCS})
	$(info CPP_SRCS: ${CPP_SRCS})
	$(info INCLUDE: ${INCLUDE})
	$(info LIBS: ${LIBS})


run:
ifeq (${SYSTEM},windows)
	${EXEC}
else
	./${EXEC}
endif
