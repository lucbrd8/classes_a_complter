//
// Created by Luc on 16/12/2024.
//

#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

namespace p24 {
    template <typename T>
    class vector {
        T* data; // nos données via un pointeur (vers le premier élément)
        int sz;  // la taille du vecteur

        // une fonction privée pour "agrandir" le tableau sous-jacent
        void resizeDataVector(int new_size) {
            // on commence par allouer un nouveau vecteur sur le tas
            T* new_data = new T[new_size];
            // puis on copie les valeurs de l'ancien tableau
            for (int i=0; i < std::min(sz, new_size); i++) { // <- j'utiliser std::min au cas où l'on "réduise" la taille du tableau...
                new_data[i] = data[i];
            }
            // on a tout copié, on peut effacer l'ancien tableau
            delete[] data;
            // et modifier les propriétés de notre instance de vector
            data = new_data;
            sz = new_size;
        }

    public:
        vector()
            : data(nullptr), sz(0) // l'initialisation des valeurs (un autre façon de l'écrire, cf. les slides)
            {}

        void push_back(T val) {
            // on va agrandir le tableau
            int new_size = sz+1;
            resizeDataVector(new_size);
            // puis on assigne le "dernier" élément
            data[new_size-1] = val;
        }

        // remplis tout le tableau avec un valeur donnée
        void fill(T value) {
            for (int i = 0; i < sz; i++) {
                data[i] = value;
            }
        }

        void clear() {
            delete[] data;
            vector();
        }

        ///
        // 👇👇👇 PUIS ON COPIE TOUTES LES AUTRES MÉTHODES DEPUIS ARRAY 👇👇👇
        ///

        T at(int n) { return data[n]; }
        T& operator[](int n) { return data[n]; }
        int size() { return sz; }
        T* begin() { return data; }
        T* end() { return data + sz; }
    };
}


#endif //VECTOR_H
