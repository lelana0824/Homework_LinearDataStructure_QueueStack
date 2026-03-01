#include <iostream>
#include "UndoRedoSystem.h"
#include "Container/Vector.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    Vector<int>* list = new Vector<int>();

    std::cout << list->IsEmpty() << "\n";
    list->Pushback(3);
    list->Pushback(1);
    list->Pushback(2);
    list->Pushback(5);
    list->Pushback(6);
    list->Pushback(8);
    list->Set(0, 121);
    list->Erase(4);
    list->Insert(1);

    std::cout << list->at(0) << "\n";
    std::cout << list->Size() << "\n";
    std::cout << list->IsEmpty() << "\n";

    delete list;
    list = nullptr;

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}