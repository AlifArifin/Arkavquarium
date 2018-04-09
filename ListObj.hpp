#ifndef LISTOBJ_HPP
#define LISTOBJ_HPP

#include <iostream>

using namespace std;

template <class T>
class ListObj{
    public:
        template <class T1>
        class Obj{ //class dari elemen listobj
            public:
                /*Sekawan*/
                Obj(T1 o) {
                    info = o;
                    next = nullptr;
                }

                /*Getter*/
                T1 getInfo() const {
                    return info;
                }
                Obj* getNext() const {
                    return next;
                }

                /*Setter*/
                void setInfo(T1 o) {
                    info = o;
                }
                void setNext(Obj* n) {
                    next = n;
                }
                
                /*Method*/
            
                /*Atribut*/
                T1 info; //mencatat informasi dari obj
                Obj *next; //mencatat alamat next dari obj
        };
    private:
        Obj<T>* first; //mencatat alamat dari first listobj
        Obj<T>* last; //mencatat alamat dari last5 listobj
        
    public:
        /*Sekawan*/
        ListObj() {
            first = nullptr;
            last = nullptr;
        }

        ~ListObj() {
            Obj<T>* current = first;
            while (current != nullptr) {
                Obj<T>* nextPtr = current->next;
                delete current;
                current = nextPtr;
            }
            first = nullptr;
            last = nullptr;
        }

        ListObj(const ListObj& L) {
            if (L.first == nullptr) {
                first = nullptr;
                last = nullptr;
            } else {
                first = new Obj<T>(L.first->info);
                Obj<T> *current = first;
                Obj<T> *firstElmt = L.first;
                Obj<T> *currentList = firstElmt;
                while (currentList->next != nullptr) {
                    current->next = new Obj<T>(currentList->next->info);
                    currentList = currentList -> next;
                    current = current -> next;
                }
                last = new Obj<T>(L.last->info);
            }
        }

        ListObj& operator=(const ListObj& L) {
            ListObj& copyL (*this);
            //delete this list
            Obj<T>* current = first;
            while (current != nullptr) {
                Obj<T>* nextPtr = current-> next;
                delete current;
                current = nextPtr;
            }
            first = nullptr;
            last = nullptr;

            //create new list
            if (L.first == nullptr) {
                first = nullptr;
                last = nullptr;
            } else {
                first = new Obj<T>(L.first->info);
                Obj<T> *current = first;
                Obj<T> *firstElmt = L.first;
                Obj<T> *currentList = firstElmt;
                while (currentList->next != nullptr) {
                    current->next = new Obj<T>(currentList->next->info);
                    currentList = currentList -> next;
                    current = current -> next;
                }
            }
        }

        /*Getter*/
        Obj<T>* getFirst() const {
            return first;
        }
        Obj<T>* getLast() const {
            return last;
        }

        /*Setter*/
        void setFirst(Obj<T>* _first) {
            first = _first;
        }
        void setLast(Obj<T>* _last) {
            last = _last;
        }
        
        /*Method*/
        //mengembalikan indeks di mana T berada pada linked list, dan -1 jika tidak ada
        int find(T _obj) const {
            int idx = 0;
            bool found = false;

            Obj<T> *current = new Obj<T>;
            current = first;
            while (current != nullptr && !found) {
                if (current->info == _obj) {
                    found = true;
                } else {
                    current = current->next;
                    idx++;
                }
            }
            //current = Last Element of not found
            if (current == nullptr) {
                return -1;
            } else {
                return idx;
            }
        }

        //mengembalikan nilai True jika linked list kosong
        bool isEmpty() const {
            return first == nullptr;
        } 
        
        // menambahkan elemen sebagai T paling belakang pada linked list
        void add(T _obj) {
            Obj<T> *temp = new Obj<T>(_obj);
            temp -> next = nullptr;
            if (first == nullptr) {
                first = temp;
                last = temp;
                temp = nullptr;
            } else {
                last -> next = temp;
                last = temp;
            }
        }

        //membuang elemen dengan identitas sesuai parameter
        //asumsi elemen ada di dalam list
        void remove(T _obj) {
            if (_obj == first->info) {
                deleteFirst();
            } else if (_obj == last->info) {
                deleteLast();
            } else {
                deleteMid(_obj);
            }
        }
        
        void deleteMid(T _obj) {
            bool found = false;
            Obj<T> *current = first;
            Obj<T> *previous = nullptr;
            while (current != nullptr && !found) {
                if (current->info == _obj) {
                    found = true;
                } else {
                    previous = current;
                    current = current -> next;
                }
            } 
            previous -> next = current -> next;
            delete current;
        } 

        void deleteFirst() {
            Obj<T> *temp = first;
            first = first -> next;
            delete temp;
        }

        void deleteLast() {
            Obj<T> *current = first;
            Obj<T> *previous = nullptr;
            current = first;
            while (current->next != nullptr) {
                previous = current;
                current = current->next;
            }
            //current adalah last element
            last = previous;
            previous -> next = nullptr;
            delete current;
        }

        
        //mengembalikan elemen dengan tipe T pada indeks sesuai parameter
        //asumsi indeks posisi selalu valid
        T get(int pos) const {
            int idx = 0;
            Obj<T> *current = first;
            while (current != nullptr && idx < pos) {
                current = current->next;
                idx++;
            }
            //idx = pos
            return current->info;
        }

        //mengembalikan jumlah elemen dalam list
        int size() const {
            int count = 0;
            Obj<T> *current =  first;
            while (current != nullptr) {
                current = current->next;
                count++;
            }
            //current == nullptr
            return count;
        }

        void print() const {
            Obj<T> *current = first;
            for (int i = 0; i < size(); i++) {
                cout << current->info << endl;
                current = current -> next;
            }
        }
};

#endif