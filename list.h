//
// Created by Luc on 16/12/2024.
//

#ifndef LIST_H
#define LIST_H

namespace p24 {
    template<typename T>
    class list {
        struct node { // la classe p24::list<T>::node

            // NOUS UTULISONS UNE "struct" et non une "class"
            // ainsi:
            // - les champs sont "publiques" par défaut
            // - on aura un constructeur équivalent à "node(T val, node* next)" généré pour nous

            T val; // la valeur
            node* next; // le pointeur vers le noeud suivant
        };

        // les attributs de la classe "list" (privés)
        node* head; // un pointeur vers le premier noeud
        node* tail; // un pointeur vers le dernier noeud
        int sz;     // la taille de la liste

    public:
        list()
            : head(nullptr), tail(nullptr), sz(0)
        {}
        void push_front(T val) {
            // on crée un nouveau noeud
            node* new_node = new node(val, head); // le nouveau "premier noeud" inséré entre head et l'ancien premier noeud
            // on édite l'état de notre liste
            if (sz == 0) {
                // la liste était vide
                // 💡 on fera attention à ne pas oublier le "tail" (comme je l'ai fait en cours !) car si on n'a qu'un
                //    noeud il est à la fois le premier et le dernier noeud
                head = tail = new_node;
            } else {
                head = new_node;
            }
            sz++;
        }

        void push_back(T val) {
            // TODO
            node* new_node = new node(val, nullptr);
            if (sz==0) {
                head = tail = new_node;
            } else {
                tail->next = new_node;
                tail = tail->next;
            }
            sz++;
        }

        T at(int pos) {
            node* current_node = head; // on part du premier noeud
            for (int i = 0; i < pos; i++) {
                current_node = current_node->next; // ici j'utilise la syntaxe "head->next" qui est équivalent à "(*head).next"
            }
            return current_node->val;
        }
        T operator[](int pos) { return at(pos); }

        void remove(int pos) {
            // TODO
            if (sz==1) {
                node*temp=head;
                head = tail = nullptr;
                delete temp;
            }else {
                if (pos==0) {
                    node* temp = head;
                    head = head->next;
                    delete temp;
                } else if (pos==sz-1) {
                    node* temp = tail;
                    node*current_node=head;
                    while (current_node->next!=tail) {
                        current_node = current_node->next;
                    }
                    tail = current_node;
                    tail->next = nullptr;
                    delete temp;
                } else {
                    node* current_node = head;
                    for (int i = 0; i<pos-1;i++) {
                        current_node = current_node->next;
                    }
                    node* temp = current_node->next;
                    (*current_node).next=(*current_node).next->next;
                    delete temp;
                }
            }
            sz--;

        }

        // efface toutes les valeurs de la liste, la ramenant à une taille de 0
        void clear() {
            // TODO
            node*current_node=head;
            while (current_node!=nullptr) {
                node* next_node = current_node->next;
                delete current_node;
                current_node=next_node;
            }
            sz=0;
        }

        // on peut copier size() depuis les autres classes 😊
        int size() { return sz; }
    };
}


#endif //LIST_H
