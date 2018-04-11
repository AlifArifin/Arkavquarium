#ifndef LISTOBJ_HPP
#define LISTOBJ_HPP

#include <iostream>

using namespace std;

template <class T>
class Obj{ //class dari elemen listobj
    public:
        /*Sekawan*/
        Obj(const T &o) : info(o) {
            next = NULL;
        }

        /*Getter*/
        T getInfo() const {
            return info;
        }

        Obj* getNext() const {
            return next;
        }

        /*Setter*/
        void setInfo(const T &o) {
            info = o;
        }

        void setNext(Obj<T>* n) {
            next = n;
        }

        T* getRef() {
            return &info;
        }
        
        /*Method*/
    
        /*Atribut*/
        T info; //mencatat informasi dari obj
        Obj<T> *next; //mencatat alamat next dari obj
};

template <class T>
class ListObj {
    private:
        Obj<T>* first; //mencatat alamat dari first listobj
        Obj<T>* last; //mencatat alamat dari last5 listobj
        
    public:
        /*Sekawan*/
        ListObj() {
            first = NULL;
            last = NULL;
        }

        ~ListObj() {
            Obj<T>* current = first;
            while (current != NULL) {
                Obj<T>* nextPtr = current->next;
                delete current;
                current = nextPtr;
            }
            first = NULL;
            last = NULL;
        }

        ListObj(const ListObj& L) {
            if (L.first == NULL) {
                first = NULL;
                last = NULL;
            } else {
                first = new Obj<T>(L.first->info);
                Obj<T> *current = first;
                Obj<T> *firstElmt = L.first;
                Obj<T> *currentList = firstElmt;
                while (currentList->next != NULL) {
                    current->next = new Obj<T>(currentList->next->info);
                    currentList = currentList -> next;
                    current = current -> next;
                }
                last = new Obj<T>(L.last->info);
            }
        }

        ListObj& operator=(const ListObj& L) {
            //delete this list
            Obj<T>* current = first;
            while (current != NULL) {
                Obj<T>* nextPtr = current-> next;
                delete current;
                current = nextPtr;
            }
            first = NULL;
            last = NULL;

            //create new list
            if (L.first == NULL) {
                first = NULL;
                last = NULL;
            } else {
                first = new Obj<T>(L.first->info);
                Obj<T> *current = first;
                Obj<T> *firstElmt = L.first;
                Obj<T> *currentList = firstElmt;
                while (currentList->next != NULL) {
                    current->next = new Obj<T>(currentList->next->info);
                    currentList = currentList -> next;
                    current = current -> next;
                }
            }
            return *this;
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
        int find(const T& _obj) const {
            int idx = 0;
            bool found = false;

            Obj<T> *current = first;
            while (current != NULL && !found) {
                if (current->info == _obj) {
                    found = true;
                } else {
                    current = current->next;
                    idx++;
                }
            }
            //current = Last Element or not found
            if (current == NULL) {
                return -1;
            } else {
                return idx;
            }
        }

        //mengembalikan nilai True jika linked list kosong
        bool isEmpty() const {
            return first == NULL;
        } 
        
        // menambahkan elemen sebagai T paling belakang pada linked list
        void add(const T& _obj) {
            Obj<T> *temp = new Obj<T>(_obj);
            temp -> next = NULL;
            if (first == NULL) {
                first = temp;
                last = temp;
                temp = NULL;
            } else {
                last -> next = temp;
                last = temp;
            }
        }

        //membuang elemen dengan identitas sesuai parameter
        //asumsi elemen ada di dalam list
        void remove(const T& _obj) {
            if (_obj == first->getInfo()) {
                deleteFirst();
            } else if (_obj == last->getInfo()) {
                deleteLast();
            } else {
                deleteMid(_obj);
            }
        }

        void removeIdx(int id) {
            Obj<T> *temp = first;

            if (id == 0) {
                deleteFirst();
            } else {
                while (temp->getNext() != NULL && id > 1) {
                    temp = temp->getNext();
                    id--;
                }

                if (temp -> getNext() != NULL) {
                    Obj<T> *rem = temp->getNext();
                    temp->setNext(rem->getNext());
                    T o = rem->getInfo();
                    delete rem;
                }
            }
        }
        
        void deleteMid(const T& _obj) {
            bool found = false;
            Obj<T> *current = first;
            Obj<T> *previous = NULL;
            while (current != NULL && !found) {
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
            Obj<T> *previous = NULL;
            current = first;
            while (current->next != NULL) {
                previous = current;
                current = current->next;
            }
            //current adalah last element
            last = previous;
            previous -> next = NULL;
            delete current;
        }

        //mengembalikan elemen dengan tipe T pada indeks sesuai parameter
        //asumsi indeks posisi selalu valid
        T& get(int pos) const {
            int idx = 0;
            Obj<T> *current = first;
            while (current != NULL && idx < pos) {
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
            while (current != NULL) {
                current = current->next;
                count++;
            }
            //current == NULL
            return count;
        }

        void print() const {
            Obj<T> *current = first;
        }
};

#endif