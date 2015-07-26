//Реализация стека с помощью указателей, классов, шаблонов и исключений
//by TimeEscasper
//timeesc.url.ph
//github.com/TimeEscaper/asds_cpp

#include <stdexcept>
//#include <iostream>
using namespace std;

//Динамическое звено через указатель
template <typename F>
struct dsPointer{
    F data; //Содержимое
    dsPointer *next; //Следующее звено
};


template <typename T>
class dsStack //Сам стек (ds - Data Structure)
{
    private:
        dsPointer<T> *stackTop; //Указатель на вершину стека
        bool stackEmpty; //Пуст ли стек
        int stackSize; //Текущий размер стека
    public:
        dsStack(){ //Конструктор
            stackTop = new dsPointer<T>;
            stackTop->next = NULL;
            stackEmpty = true;
            stackSize = 0;
        }

        T Top() //Достать верхний элемент (не удаляя его)
        {
            if(stackEmpty)
                throw range_error("dsStack: Stack is empty!"); //Генерация исключения, если стек пуст
            else
                return stackTop->data;
        }
        void Push(T value) //Добавить элемент в стек
        {
            if(stackEmpty)
            {
                stackTop->data = value;
                stackEmpty = false;
            }
            else
            {
                dsPointer<T> *tmpPointer = new dsPointer<T>;
                tmpPointer->data = value;
                tmpPointer->next = stackTop;
                stackTop = tmpPointer;
            }

            stackSize++;
        }

        void Pop() //Удалить верхний элемент стека
        {
            if(!stackEmpty)
            {
                if(stackSize == 1)
                {
                    stackTop->data = NULL;
                    stackEmpty = true;
                }
                else
                {
                    dsPointer<T> *tmpPointer = new dsPointer<T>;
                    tmpPointer = stackTop;
                    stackTop = stackTop->next;
                    delete tmpPointer;
                }

                stackSize--;
            }
        }

        void Clear() //Очистить стек
        {
            while(!stackEmpty)
                Pop();
        }

        bool IsEmpty() //Пуст ли стек
        {
            return stackEmpty;
        }

        int Size() //Узнать размер стека
        {
            return stackSize;
        }

       /* void Print() //Распечатать содержимое стека
        {
            if(!stackEmpty)
            {
                cout<<"\n";
                dsPointer<T> *stackIterator = new dsPointer<T>;
                stackIterator = stackTop;
                while (stackIterator != NULL)
                {
                    cout << stackIterator->data <<" ";
                    stackIterator = stackIterator->next;
                }
                cout<<"\n";
            }
        }*/

};
