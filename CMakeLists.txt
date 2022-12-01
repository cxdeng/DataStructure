cmake_minimum_required(VERSION 3.21)
project(DataStructure C)

set(CMAKE_C_STANDARD 11)

include_directories(LinkedList/Header)


add_executable(SinglyLinkedList  LinkedList/Main/SinglyLinkedListMain.c LinkedList/Source/SinglyLinkedList.c)
