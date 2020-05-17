#include <stdio.h>
#include <stdlib.h>
#include <cstddef>
#include "../exceptions/IndexError.hpp"

template <typename T>
class Stack {
    private:
        int pos;
        T* elems;
        int size;
        int cur_index;

    public:
        Stack(){
            pos = 0;
            cur_index = 0;
            size = 1;
            elems = (T*)malloc(sizeof(T));
        }

        void append(T elem){
            elems = (T*)realloc(elems, sizeof(T) * size * 2);
            elems[pos] = elem;
            pos++;
            size++;
        }

        void insert(size_t pos, T elem){
            if(pos + 1 >= size){
                throw IndexError;
            }
            elems[pos] = elem;
        }

        T get(int index){
            if(index >= size){
                throw IndexError;
            }
            return elems[index];
        }

        int length(){
            return size - 1;
        }

        T operator [](int index){
            if(index >= size){
                throw IndexError;
            }
            cur_index = index;
            return elems[index];
        }

       

        ~Stack(){
            delete elems;
        }
};