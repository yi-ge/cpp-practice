# 获取当前时间
string(TIMESTAMP CURRENT_TIME "%Y-%m-%d %H:%M:%S")

# 获取当前源文件路径
set(CURRENT_SOURCE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

# 定义相对路径
set(RELATIVE_PATH "../test/lib/lib_test.cpp")

# 将相对路径转换为绝对路径
get_filename_component(ABSOLUTE_PATH "${CURRENT_SOURCE_PATH}/${RELATIVE_PATH}" REALPATH)

message("Absolute path: ${ABSOLUTE_PATH}")

# 读取整个文件内容
file(READ ${ABSOLUTE_PATH} FILE_CONTENT)

# 找到第一行的结束位置
string(FIND "${FILE_CONTENT}" "\n" END_OF_FIRST_LINE)

# 截取第一行之后的所有内容
string(SUBSTRING "${FILE_CONTENT}" ${END_OF_FIRST_LINE} -1 REMAINING_LINES)

# 创建新的第一行
set(NEW_FIRST_LINE "// 执行编译时间：${CURRENT_TIME}")

# 将新的第一行和剩余部分重新写入文件
file(WRITE ${ABSOLUTE_PATH} "${NEW_FIRST_LINE}${REMAINING_LINES}")
