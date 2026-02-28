#include <iostream>
#include "Container/Stack.h"
#include "Container/Queue.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    /*
    - 레이저 블랙위도우 TE 크로마 V2동작
        - ‘A’, ‘B’, ‘C’, ‘D’, ‘E’ 키를 입력 받기
        - 들어온 입력을 입력 Queue에 넣기
        - 입력 Queue에 들어온 순서대로 Undo 스택에 기록
        - “undo” 명령어를 입력하면 undo 실행
        - “redo” 명령어를 입력하면 redo 실행
        - “show” 명령어를 입력하면 undo 스택과 redo 스택에 저장된 명령 내용 출력
     */

    // 키 및 명령어 입력 정의 -> 문자열 입력 후 '엔터'로 정의한다.
    // 명령어가 아닌 키는 모두 queue에 넣는다.
    // queue에 들어가는 키는 모두 undo 스택에도 넣는다.

    // 명령어 입력 시
    // undo:
    // 1. undo 스택에서 pop 한 내용을 출력한 후, redo 스택에 넣는다.
    // redo
    // 1. redo 스택에서 pop한 내용을 출력한 후, undo 스택에 넣는다.
    // * 중요 - 키 입력 (명령어가 아닌 모든 입력)시 redo 스택은 초기화된다.

    // todo: 스택 초기화 메서드, Show 메서드.




    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}