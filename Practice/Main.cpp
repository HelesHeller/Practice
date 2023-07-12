#include <iostream>

namespace DataStructures {
    class Stack {
        // Нижняя и верхняя границы стека
        enum { EMPTY = -1, FULL = 20 };
        // Массив для хранения данных
        char st[FULL + 1];
        // Указатель на вершину стека
        int top;

    public:
        // Конструктор
        Stack();

        // Добавление элемента
        void Push(char c);

        // Извлечение элемента
        char Pop();

        // Очистка стека
        void Clear();

        // Проверка существования элементов в стеке
        bool IsEmpty();

        // Проверка на переполнение стека
        bool IsFull();

        // Количество элементов в стеке
        int GetCount();

        void Output();
    };

    // Реализация методов класса Stack

    Stack::Stack() : top(EMPTY) {}

    void Stack::Push(char c) {
        if (IsFull()) {
            std::cout << "Stack is full!" << std::endl;
            return;
        }

        st[++top] = c;
    }

    char Stack::Pop() {
        if (IsEmpty()) {
            std::cout << "Stack is empty!" << std::endl;
            return '\0';
        }

        return st[top--];
    }

    void Stack::Clear() {
        top = EMPTY;
    }

    bool Stack::IsEmpty() {
        return top == EMPTY;
    }

    bool Stack::IsFull() {
        return top == FULL;
    }

    int Stack::GetCount() {
        return top + 1;
    }

    void Stack::Output() {
        for (int i = 0; i < top + 1; i++) {
            std::cout << st[i] << " ";
        }
        std::cout << std::endl;
    }
}  // namespace DataStructures

int main() {
    DataStructures::Stack stack;
    stack.Push('A');
    stack.Push('B');
    stack.Push('C');

    stack.Output();

    std::cout << "Count: " << stack.GetCount() << std::endl;

    stack.Pop();
    stack.Pop();

    stack.Output();

    stack.Clear();
    std::cout << "Is empty: " << (stack.IsEmpty() ? "true" : "false") << std::endl;

    return 0;
}
