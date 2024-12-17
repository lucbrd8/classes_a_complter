#include <iostream>
#include "vector.h"
#include "list.h"
#include "array.h"
#include <algorithm>


int main() {
    std::cout << "=== p24::array ===" << std::endl;

    p24::array<int, 5> a;
    a.fill(42); // 42 42 42 42 42
    a[0] = 1;        //  1 42 42 42 42
    a[4] = 22;       //  1 42 42 42 22

    std::cout << "Valeurs du tableau (version for i):" << std::endl;
    for (int i=0; i<a.size(); i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Valeurs du tableau (version for-each):" << std::endl;
    for (int x: a) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // on peut également utiliser les algorithmes tels que le tri si on a begin() et end()
    std::sort(a.begin(), a.end());

    std::cout << "Tableau trié (version for-each):" << std::endl;
    for (int x: a) {
        std::cout << x << " "; //  1 22 42 42 42
    }
    std::cout << std::endl;

    std::cout << "=== p24::vector ===" << std::endl;
    p24::vector<int> v;

    // on va utiliser push_back pour ajouter des éléments !
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(3);
    // ici v = { 1, 2, 4, 3 }

    std::cout << "Valeurs du vecteur (version for i):" << std::endl;
    for (int i=0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Valeurs du vecteur (version for-each):" << std::endl;
    for (int x: v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // on peut également utiliser les algorithmes tels que le tri si on a begin() et end()
    std::sort(v.begin(), v.end());

    std::cout << "Vecteur trié (version for-each):" << std::endl;
    for (int x: v) {
        std::cout << x << " "; //  1 22 42 42 42
    }
    std::cout << std::endl;

    std::cout << "=== p24::list ===" << std::endl;
    p24::list<int> l;

    // on va utiliser push_back pour ajouter des éléments !
    l.push_front(1);
    l.push_front(2);
    l.push_back(4);
    l.push_back(3);
    // ici v = { 2, 1, 4, 3 }

    std::cout << "Valeurs de la liste (version for i):" << std::endl;
    for (int i=0; i < l.size(); i++) {
        std::cout << l[i] << " ";
    }
    std::cout << std::endl;

    l.remove(2); // { 2, 1, 3}

    std::cout << "Valeurs de la liste après le delete:" << std::endl;
    for (int i=0; i < l.size(); i++) {
        std::cout << l[i] << " ";
    }
    std::cout << std::endl;

    l.clear();

    std::cout << "Valeurs de la liste après le clear:" << std::endl;
    for (int i=0; i < l.size(); i++) {
        std::cout << l[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
