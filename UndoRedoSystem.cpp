//
// Created by Lelana on 2026. 2. 28..
//

#include "UndoRedoSystem.h"

UndoRedoSystem::UndoRedoSystem(){}

UndoRedoSystem::~UndoRedoSystem(){}

// 키 및 명령어 입력 정의 -> 문자열 입력 후 '엔터'로 정의한다.
void UndoRedoSystem::Run() {
    const char* q = "q";

    std::cout << "입력하세요\n";

    while (true) {
        char text[1024] = {};
        std::cin >> text;

        if (strcmp(text, q) == 0) {
            break;
        }

        // undo
        // undo 스택에서 pop 한 내용을 출력한 후, redo 스택에 넣는다.
        if (strcmp(text, commands[0]) == 0) {
            char* t = undoStack.Pop();
            std::cout << "undo: " << t << "\n";
            redoStack.Push(t);
        }
        // redo
        // redo 스택에서 pop한 내용을 출력한 후, undo 스택에 넣는다.
        else if (strcmp(text, commands[1]) == 0) {
            char* t = redoStack.Pop();
            std::cout << "redo: " << t << "\n";
            undoStack.Push(t);
        }
        // show
        else if (strcmp(text, commands[2]) == 0) {
            std::cout << "\n";
            std::cout << "\n";
            std::cout << "undoStack: " << "\n";
            undoStack.Print();

            std::cout << "\n";
            std::cout << "redoStack: " << "\n";
            redoStack.Print();
            std::cout << "\n";
            std::cout << "\n";
        }

        // 명령어가 아닌 키는 모두 queue에 넣는다.
        // queue에 들어가는 키는 모두 undo 스택에도 넣는다.
        // 키 입력 (명령어가 아닌 모든 입력)시 redo 스택은 초기화된다.
        else {
            int len = 0;
            while (text[len] != '\0') {
                len++;
            }

            char* inText = new char[len + 1];
            strcpy(inText, text);

            queue.Enqueue(inText);
            undoStack.Push(inText);
            redoStack.Clear();
        }

    }
}