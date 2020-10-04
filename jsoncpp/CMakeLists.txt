set(JSONCPP
   json/json.h json/json-forwards.h jsoncpp.cpp
)

set(LIB_TYPE STATIC)

add_library(jsoncpp ${LIB_TYPE} ${JSONCPP})