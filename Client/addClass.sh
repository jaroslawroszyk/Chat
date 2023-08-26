#!/bin/bash

echo -e "Enter class name:"
read -r class_name

# Convert class name to uppercase
uppercase_class_name=$(echo "$class_name" | tr '[:lower:]' '[:upper:]')

# Create header file
header_content="#ifndef CHAT_${uppercase_class_name}_HPP\n#define CHAT_${uppercase_class_name}_HPP\n#endif // CHAT_${uppercase_class_name}_HPP"
header_filename="${class_name}.hpp"
echo -e "$header_content" > "include/${header_filename}"

# Create source file
source_content="#include \"../include/${header_filename}\""
source_filename="${class_name}.cpp"
echo -e "$source_content" > "src/${source_filename}"

echo "Class $class_name created."

# Append add_library line to CMakeLists.txt
