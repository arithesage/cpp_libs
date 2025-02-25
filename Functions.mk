
# ${1}: Source file
define SRC2OBJ
${OBJS_PATH}/$(subst .c,.o,$(subst .cpp,.o,${1}))
endef
