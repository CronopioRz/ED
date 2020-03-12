#ifndef bintree_eda_ext
#define bintree_eda_ext

#include "bintree_eda.h"

template <class T> 
class bintree_ext: public bintree<T>{
    using Link = typename bintree<T>::Link;
    public:
        bintree_ext(): bintree<T>() {};
        bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r): bintree<T>(l, e, r) {};

        size_t altura() const {
            return altura(this->raiz);
        }
        size_t nleafs() const {
            return nleafs(this->raiz);
        }

        size_t nNodes() const {
            return nNodes(this->raiz);
        }

        
        
    
        
    private:

    static size_t altura(Link r) {
        if (r == nullptr) {
            return 0;
        } 
        else {
            return 1 + std::max(altura(r->left), altura(r->right));       
        }
    }

    //de forma recursiva contamos los hijos
    static size_t nleafs(Link r){
        if(r == nullptr){
            return 0;
        }
        else {
            auto iz = nleafs(r->left);
            auto dr = nleafs(r->right);
        
                return (iz == 0 && dr == 0) ? 1 :  iz + dr;
        }
    }

    static size_t nNodes(Link r){
        if(r == nullptr){
            return 0;
        }
        else {
            auto iz = nNodes(r->left);
            auto dr = nNodes(r->right);
            return 1 + iz + dr;
        }
    }

};
        template <typename T>  
        inline bintree_ext<T> leerArbol_ext(T vacio) {
            T raiz;
            std::cin >> raiz;
            if (raiz == vacio) { // es un árbol vacío
                return {};
            }   
            else { // leer recursivamente los hijos
                auto iz = leerArbol_ext(vacio);
                auto dr = leerArbol_ext(vacio);
                return {iz, raiz, dr};
            }
        }

#endif
