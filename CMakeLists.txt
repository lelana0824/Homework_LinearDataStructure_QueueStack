cmake_minimum_required(VERSION 4.0)
project(LinearDataStructure_QueueStack)

set(CMAKE_CXX_STANDARD 20)

add_executable(LinearDataStructure_QueueStack main.cpp
        Container/Queue.h
        Container/Stack.h
        UndoRedoSystem.cpp
        UndoRedoSystem.h
        Container/Vector.h
        CardInfo.cpp
        CardInfo.h
        FlipThroughCardSystem.cpp
        FlipThroughCardSystem.h
)
