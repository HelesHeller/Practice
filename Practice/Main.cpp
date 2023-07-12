#include <iostream>

namespace DataStructures {
    class Stack {
        // ������ � ������� ������� �����
        enum { EMPTY = -1, FULL = 20 };
        // ������ ��� �������� ������
        char st[FULL + 1];
        // ��������� �� ������� �����
        int top;

    public:
        // �����������
        Stack();

        // ���������� ��������
        void Push(char c);

        // ���������� ��������
        char Pop();

        // ������� �����
        void Clear();

        // �������� ������������� ��������� � �����
        bool IsEmpty();

        // �������� �� ������������ �����
        bool IsFull();

        // ���������� ��������� � �����
        int GetCount();

        void Output();
    };

    // ���������� ������� ������ Stack

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
