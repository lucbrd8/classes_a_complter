//
// Created by Luc on 16/12/2024.
//

#ifndef ARRAY_H
#define ARRAY_H

namespace p24 {
    template<typename T, int sz>
        class array {

        // private:     // <- le mot-clé "private:" est optionnel car dans une classe tout est privé par défaut
        T data[sz]; // nos données, elles sont privées

    public:
        // remplis tout le tableau avec un valeur donnée
        void fill(T value) {
            for (int i = 0; i < sz; i++) {
                data[i] = value;
            }
        }

        // retourne la valeur à un index donné
        T at(int n) { return data[n]; }
        // idem mais avec "l'opérateur []"
        T& operator[](int n) { return data[n]; }

        // retourn la taille du tableau
        int size() { return sz; }

        // les pointeurs "begin()" et "end()" -> ils permettent par ex. d'utiliser la boucle "for each"
        T* begin() { return data; }
        T* end() { return data + sz; }
    };
}


#endif //ARRAY_H
