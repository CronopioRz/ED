/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 */

/*
 * MUY IMPORTANTE: Para realizar este ejercicio solo podéis
 * modificar el código contenido entre las etiquetas <answer>
 * y </answer>. Toda modificación fuera de esas etiquetas está
 * prohibida, pues no será corregida.
 *
 * Tampoco esta permitido modificar las líneas que contienen
 * las etiquetas <answer> y </answer>, obviamente :-)
 */

//@ <answer>
/*
 * Introduce el nombre y apellidos de los/as componentes del grupo:
 *
 * Estudiante 1: Pablo Rabadán Arza
 * Estudiante 2: David Elías Piñeiro
 *
 */
//@ </answer>

//El coste es lineal debido a que La función intersect consiste en un bucle while que recorre uno a uno 
//los elementos de la lista 2 y cuando esta termina busca eliminar aquellos valores que sobren, mirando siempre
//uno a uno los elementos de la lista 1.
//Con lo cual el coste es lineal ya que en el caso peor el coste sería O(n) + O(n), siendo n el tamaño de la lista 1.

#include <iostream>
#include <cassert>
#include <fstream>


class ListLinkedSingle {
private:
  struct Node {
    int value;
    Node *next;
  };

public:
  ListLinkedSingle(): head(nullptr) { }
  ~ListLinkedSingle() {
    delete_list(head);
  }

  ListLinkedSingle(const ListLinkedSingle &other)
    : head(copy_nodes(other.head)) { }

  void push_front(const int &elem) {
    Node *new_node = new Node { elem, head };
    head = new_node;
  }

  void push_back(const int &elem);

  void pop_front() {
    assert (head != nullptr);
    Node *old_head = head;
    head = head->next;
    delete old_head;
  }

  void pop_back();

  int size() const;

  bool empty() const {
    return head == nullptr;
  };

  const int & front() const {
    assert (head != nullptr);
    return head->value;
  }

  int & front() {
    assert (head != nullptr);
    return head->value;
  }

  const int & back() const {
    return last_node()->value;
  }

  int & back() {
    return last_node()->value;
  }

  const int & at(int index) const {
    Node *result_node = nth_node(index);
    assert (result_node != nullptr);
    return result_node->value;
  }

  int & at(int index) {
    Node *result_node = nth_node(index);
    assert (result_node != nullptr);
    return result_node->value;
  }

  void display(std::ostream &out) const;
  void display() const {
    display(std::cout);
  }

  // Nuevo método. Debe implementarse abajo
  void intersect(const ListLinkedSingle &l2);

private:
  Node *head;

  void delete_list(Node *start_node);
  Node *last_node() const;
  Node *nth_node(int n) const;
  Node *copy_nodes(Node *start_node) const;

};

ListLinkedSingle::Node * ListLinkedSingle::copy_nodes(Node *start_node) const {
  if (start_node != nullptr) {
    Node *result = new Node { start_node->value, copy_nodes(start_node->next) };
    return result;
  } else {
    return nullptr;
  }
}

void ListLinkedSingle::delete_list(Node *start_node) {
  if (start_node != nullptr) {
    delete_list(start_node->next);
    delete start_node;
  }
}

void ListLinkedSingle::push_back(const int &elem) {
  Node *new_node = new Node { elem, nullptr };
  if (head == nullptr) {
    head = new_node;
  } else {
    last_node()->next = new_node;
  }
}

void ListLinkedSingle::pop_back() {
  assert (head != nullptr);
  if (head->next == nullptr) {
    delete head;
    head = nullptr;
  } else {
    Node *previous = head;
    Node *current = head->next;

    while (current->next != nullptr) {
      previous = current;
      current = current->next;
    }

    delete current;
    previous->next = nullptr;
  }
}

int ListLinkedSingle::size() const {
  int num_nodes = 0;

  Node *current = head;
  while (current != nullptr) {
    num_nodes++;
    current = current->next;
  }

  return num_nodes;
}


ListLinkedSingle::Node * ListLinkedSingle::last_node() const {
  assert (head != nullptr);
  Node *current = head;
  while (current->next != nullptr) {
    current = current->next;
  }
  return current;
}

ListLinkedSingle::Node * ListLinkedSingle::nth_node(int n) const {
  assert (0 <= n);
  int current_index = 0;
  Node *current = head;

  while (current_index < n && current != nullptr) {
    current_index++;
    current = current->next;
  }

  return current;
}

void ListLinkedSingle::display(std::ostream &out) const {
  out << "[";
  if (head != nullptr) {
    out << head->value;
    Node *current = head->next;
    while (current != nullptr) {
      out << ", " << current->value;
      current = current->next;
    }
  }
  out << "]";
}

// ----------------------------------------------------------------
//@ <answer>

// Implementa a continuación el método pedido.

void ListLinkedSingle::intersect(const ListLinkedSingle &other) {
  // Completar aquí
  //Guardamos el puntero a la posicion inicial de cada lista
  Node* punt1 = head;
  Node* prev = nullptr;
  Node* punt2 = other.head;
  Node* aux = nullptr;
 
  while (punt1 != nullptr && punt2 != nullptr){
      if (punt1->value < punt2->value) {
          if (punt1 == this->head) {
              this->pop_front();
              punt1 = this->head;
          }

          else {
              prev->next = punt1->next;
              delete punt1;
              punt1 = prev->next;
          }
      }
      else {
          if (punt1->value == punt2->value) {
              prev = punt1;
              if (punt2->next != nullptr){
                punt1 = punt1->next;
              }
                  
          }
          aux = punt2;
          punt2 = punt2->next;
      }
     
  }

  if (punt2 == nullptr ) {
      
      while (punt1->next != nullptr ) {
          this->pop_back();
      }

      if(aux->value < this->head->value){
        while(this->head != nullptr)
         this->pop_back();
      }

  }

}

using namespace std;


void tratar_caso() {
  // Implementar. Aquí se procesa cada caso de prueba
  int tam1, tam2,aux;
  ListLinkedSingle  list1 = ListLinkedSingle();
  std::cin >> tam1;
  for(int i =0; i < tam1; i++){
      std::cin >>aux;
      list1.push_back(aux);
  }
  ListLinkedSingle  list2 = ListLinkedSingle();
  std::cin >> tam2;
  for(int i =0; i < tam2; i++){
      std::cin >>aux;
      list2.push_back(aux);
  }
    if(tam2 == 0){
        while(!list1.empty()){
            list1.pop_back();
        }
    }
    else
        list1.intersect(list2);
  list1.display();
}


//@ </answer>

// ¡No modificar nada debajo de esta línea!
// ----------------------------------------------------------------

int main() {
#ifndef DOMJUDGE
  std::ifstream in("sample.in");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

  // Leemos el número de casos de prueba que vendrán a continuación
  int num_casos;
  cin >> num_casos;

  for (int i = 0; i < num_casos; i++) {
    tratar_caso();
  }

#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
#endif
  return 0;
}
