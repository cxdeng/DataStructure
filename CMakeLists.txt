cmake_minimum_required(VERSION 3.21)
project(DataStructure C)

set(CMAKE_C_STANDARD 11)

include_directories(LinkedList/Header SequenceList/Header Stack/Header Queue/Header)


add_executable(SinglyLinkedList LinkedList/Main/SinglyLinkedListMain.c LinkedList/Source/SinglyLinkedList.c)
add_executable(StaticSeqList SequenceList/Main/StaticSeqListMain.c SequenceList/Source/StaticSeqList.c)

add_executable(CircularSinglyLinkedList LinkedList/Main/CircularSinglyLinkedListMain.c LinkedList/Source/CircularSinglyLinkedList.c)
add_executable(DoublyLinkedList LinkedList/Main/DoublyLinkedListMain.c LinkedList/Source/DoublyLinkedList.c)

add_executable(StaticStack Stack/Main/StaticStackMain.c Stack/Source/StaticStack.c)
add_executable(LinkedStack Stack/Main/LinkedStackMain.c Stack/Source/LinkedStack.c)

add_executable(StaticSeqQueue Queue/Main/StaticSeqQueueMain.c Queue/Source/StaticSeqQueue.c)
add_executable(StaticCircularSeqQueue Queue/Main/StaticCircularSeqQueueMain.c Queue/Source/StaticCircularSeqQueue.c)
add_executable(LinkedQueue Queue/Main/LinkedQueueMain.c Queue/Source/LinkedQueue.c)
