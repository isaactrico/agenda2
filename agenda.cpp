#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>


using namespace std;

class Nodo{
  public:
    int id;
    string mail, phone, address, name;


  public:
    Nodo* next;

    Nodo(){
    };

    Nodo(int id, string mail, string phone, string address, string name){
      this->id = id;
      this->mail = mail;
      this->phone = phone;
      this->address = address;
      this->name = name;
      this->next = NULL;
    };

    string toString(){
      stringstream ss;
      ss<<"ID: "<<id<<endl;
      ss<<"Mail: "<<mail<<endl;
      ss<<"Phone: "<<phone<<endl;
      ss<<"Address: "<<address<<endl;
      ss<<"Name: "<<name<<endl;
      std::cout << "\n\n" << '\n';

      return ss.str();

    }

    void setId(int id){
      this->id = id;
    }

    void setMail(string mail){
      this->mail = mail;
    }

    void setPhone(string phone){
      this->phone = phone;
    }

    void setAddress(string address){
      this->address = address;
    }

    void setName(string name){
      this->name = name;
    }

    int getId(){
      return this->id;
    }
    string getMail(){
      return this->mail;
    }
    string getPhone(){
      return this->phone;
    }
    string getAddress(){
      return this->address;
    }
    string getName(){
      return this->name;
    }

};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Agenda{
  private:
    Nodo *frente = NULL;
  	Nodo *fin = NULL;


  public:

    bool cola_vacia(Nodo *frente){
    	return (frente == NULL)? true : false;
    };

    void add(int id, string mail, string phone, string address, string name){

      Nodo *nuevo_nodo = new Nodo( id,  mail,  phone,  address,  name);

    	nuevo_nodo->next = NULL;

    	if(cola_vacia(frente)){
    		frente = nuevo_nodo;
    	}
    	else{
    		fin->next = nuevo_nodo;
    	}

    	fin = nuevo_nodo;
    };

    void addFirst(int id, string mail, string phone, string address, string name){

      Nodo *nuevo_nodo = new Nodo( id,  mail,  phone,  address,  name);


      if(cola_vacia(frente)){
        nuevo_nodo->next = NULL;
        frente = nuevo_nodo;
      }
      else{
        nuevo_nodo->next = frente;
        frente = nuevo_nodo;
      }

    };

    void insertarPos(int pos, int id, string mail, string phone, string address, string name){
        int cont = 0;
        if(pos == 0){
          Nodo* nuevo_nodo = new Nodo(id,  mail,  phone,  address,  name);
          nuevo_nodo->next = frente;
          frente = nuevo_nodo;
          return;
        }
        Nodo* temp = frente;
        while(temp!=NULL){
          if(cont == pos){
            Nodo* nuevo_nodo = new Nodo(id,  mail,  phone,  address,  name);
            nuevo_nodo->next = temp;
            anterior(temp)->next = nuevo_nodo;
            break;
          }
          cont++;
          temp=temp->next;
        }

    }

    void searchId(int id){
      Nodo* aux = new Nodo();
      aux->next = frente;

      if(aux->id == id){
        cout<<aux->toString();
      }else{
        while(aux!=NULL){
          if(aux->id == id)
            cout<<aux->toString();
          aux = aux->next;
        }
      }

    }

    Nodo* localizaId(int id){
      Nodo* aux = frente;
      while(aux != NULL){
        if(aux->id == id)
          return aux;
        aux = aux->next;
      }
      return NULL;
    }

    Nodo* localizaName(string name){
      Nodo* aux = frente;
      while(aux != NULL){
        if(aux->name == name)
          return aux;
        aux = aux->next;
      }
      return NULL;
    }

    Nodo* localizaPos(int pos){
      int index = 0;
      Nodo* aux = frente;
      while(aux != NULL){
        if(index == pos)
          return aux;
        index++;
        aux = aux->next;
      }
      return NULL;
    }

    Nodo* anterior(Nodo* n){
      Nodo* aux = frente;
      while(aux->next != NULL){
        if(aux->next == n){
          return aux;
        }
        aux = aux->next;
      }
      return NULL;
    }

    void eliminar(Nodo* e){
      if(e == frente){
        frente = frente->next;
        delete(e);
      }else{
        Nodo* ant = frente;
        while(ant->next != NULL){
          if(ant->next == e){
            anterior(e)->next = e->next;
            delete(e);
          }
        }
      }
    }

    void deleteAll(){
      frente = NULL;
      fin = NULL;
    }



    void ordenarId(){


      Nodo* temp = frente;
      while(temp!=NULL){
        Nodo* sig = temp->next;
        while(sig!= NULL){
          if(temp->id > sig->id){
                                    //id,  mail,  phone,  address,  name
            int auxId = sig->id;
            sig->id = temp->id;
            temp->id = auxId;

            string auxMail = sig->mail;
            sig->mail = temp->mail;
            temp->mail = auxMail;

            string auxPhone = sig->phone;
            sig->phone = temp->phone;
            temp->phone = auxPhone;

            string auxAddress = sig->address;
            sig->address = temp->address;
            temp->address = auxAddress;

            string auxName = sig->name;
            sig->name = temp->name;
            temp->name = auxName;

          }
          sig = sig->next;
        }
        temp = temp->next;
      }


    }

    void ordenarName(){


      Nodo* temp = frente;
      while(temp!=NULL){
        Nodo* sig = temp->next;
        while(sig!= NULL){
          if(temp->name > sig->name){
                                    //id,  mail,  phone,  address,  name
            int auxId = sig->id;
            sig->id = temp->id;
            temp->id = auxId;

            string auxMail = sig->mail;
            sig->mail = temp->mail;
            temp->mail = auxMail;

            string auxPhone = sig->phone;
            sig->phone = temp->phone;
            temp->phone = auxPhone;

            string auxAddress = sig->address;
            sig->address = temp->address;
            temp->address = auxAddress;

            string auxName = sig->name;
            sig->name = temp->name;
            temp->name = auxName;

          }
          sig = sig->next;
        }
        temp = temp->next;
      }


    }

    void invertir(){
      if(frente){
        Nodo* temp = frente;
        Nodo* ant = anterior(temp);
        Nodo* sig = temp->next;
        fin = frente;

        while(temp->next
          !=NULL){
            temp->next = ant;

            ant = temp;
            temp = sig;
            sig = temp->next;
            std::cout <<"\n"<<temp->id<< '\n';
          }
          temp->next = ant;
          frente = temp;
      }
    }

    void mostrarTodo(){
        Nodo* temp = frente;
        while(temp!=NULL){
          cout<<temp->toString()<<endl;
          temp=temp->next;
        }
    }

    void edit(Nodo* nodo){
      int id, op;
      string mail, phone, address, name;

      do {
        fflush(stdin);
        cout<<"\n ------MENU DE EDICION-------"
        "\n -Elige el campo a modificar-"
        "\n 1.- Mail"
        "\n 2.- Telefono"
        "\n 3.- Direccion"
        "\n 4.- Nombre"
        "\n 0.- Salir"<<endl;
        cout<<"\nIngrese el campo que desea modificar: "<<endl;
        cin>>op;

        switch (op) {
          case 0:
          cout<<"\nEdicion finalizada"<<endl;
          break;

          case 1:{
            fflush(stdin);
            string mail;
            cout<<"\n Ingrese el nuevo valor"<<endl;
            getline(cin, mail);
            nodo->setMail(mail);
          }
          break;

          case 2:{
            fflush(stdin);
            string phone;
            cout<<"\n Ingrese el nuevo valor"<<endl;
            getline(cin, phone);
            nodo->setPhone(phone);
          }
          break;

          case 3:{
            fflush(stdin);
            string address;
            cout<<"\n Ingrese el nuevo valor"<<endl;
            getline(cin, address);
            nodo->setAddress(address);
          }
          break;

          case 4:{
            fflush(stdin);
            string name;
            cout<<"\n Ingrese el nuevo valor"<<endl;
            getline(cin, name);
            nodo->setName(name);
          }
          break;

          default: cout<<"\n Opcion no disponible"<<endl;
        }
      } while(op!=0);
    }


};

int menu(){
  int opc;
  cout<<"\n 1.- Agregar al Final"


  "\n 2.- Buscar un Contacto por Nombre"

  "\n 3.- Buscar un Contacto por ID"

  "\n 4.- Editar un Contacto"

  "\n 5.- Eliminar un Contacto por ID"

  "\n 6.- Mostrar Toda la Agenda"

  "\n 7.- Eliminar por Posicion"

  "\n 8.- Agregar al Inicio"

  "\n 9.- Ordenar Lista Alfabeticamente"

  "\n 10.- Ordenar Lista por ID"

  "\n 11.- Eliminar toda la lista"

  "\n 12.- Invertir Lista"

  "\n 13.- Insertar en posicion"

  "\n 0.- Salir"<<endl;
  cin>>opc;

  return opc;

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
  Agenda A;
  int opc, cont=0;

  do {

    opc = menu();

    switch (opc) {
      case 0:
        std::cout << "\nCerrando Agenda" << '\n';
      break;

      case 1:{
        int id;
        string mail, phone, address, name;

        fflush(stdin);

        std::cout << "\n Se ha asignado el ID: " <<cont<< '\n';
        id = cont;
        cont++;

        cout<<"\nIngrese el E-mail de su nuevo contacto: "<<endl;
        getline(cin, mail);

        cout<<"\nIngrese el Telefono de su nuevo contacto"<<endl;
        getline(cin, phone);

        cout<<"\nIngrese la Direccion de su nuevo contacto"<<endl;
        getline(cin, address);

        cout<<"\nIngrese el Nombre de su nuevo contacto"<<endl;
        getline(cin, name);

        A.add(id, mail, phone, address, name);

      }

      break;

      case 2:{
        string name;

        fflush(stdin);
        cout<<"\nIngrese el Nombre del contacto"<<endl;
        getline(cin, name);

        if(A.localizaName(name)){
          cout<<A.localizaName(name)->toString()<<endl;
        }else{
          std::cout << "\nNo encontramos resultados satisfactorios" << '\n';
        }

      }

      break;

      case 3:{
        int id;

        fflush(stdin);
        cout<<"\nIngrese el ID del contacto"<<endl;
        cin>>id;

        if(A.localizaId(id)){
          cout<<A.localizaId(id)->toString()<<endl;
        }else{
          std::cout << "\nNo encontramos resultados satisfactorios" << '\n';
        }
      }
      break;

      case 4:{
        int id;

        fflush(stdin);
        std::cout << "\n Ingrese el ID del elemento a eliminar" << '\n';
        while(!(cin>>id)){
          std::cout << "\nEntrada no valida, defina el stock inicial con un numero entero: " << '\n';
          cin.clear();
          cin.ignore(22, '\n');
        }

        if(A.localizaId(id)){
          A.edit(A.localizaId(id));
        }else{
          std::cout << "\nNo encontramos resultados satisfactorios" << '\n';
        }

      }
      break;

      case 5:{
        int id;
        cout<<"\nIngrese el ID del usuario a eliminar: "<<endl;
        cin>>id;

        if(A.localizaId(id)){
            cout<<"\nEliminando: \n"<<A.localizaId(id)->toString();
            A.eliminar(A.localizaId(id));
            std::cout << "\nContacto eliminado" << '\n';
        }else{
          std::cout << "\nNo encontramos coincidencia alguna para el ID proporcionado" << '\n';
        }

      }
      break;

      case 6:
      A.mostrarTodo();
      break;


      case 7:{
        int ind;
        cout<<"\nIngresa la posicion a eliminar"<<endl;
        cin>>ind;

        if(A.localizaPos(ind)){
          cout<<"\nEliminando: \n"<<A.localizaPos(ind)->toString();
          A.eliminar(A.localizaPos(ind));
          std::cout << "\nContacto Eliminado" << '\n';
        }else{
          std::cout << "\nNo encontramos coincidencia alguna para el ID proporcionado" << '\n';
        }

      }
      break;

      case 8:{
        int id;
        string mail, phone, address, name;

        fflush(stdin);

        std::cout << "\n Se ha asignado el ID: " <<cont<< '\n';
        id = cont;
        cont++;

        cout<<"\nIngrese el E-mail de su nuevo contacto: "<<endl;
        getline(cin, mail);

        cout<<"\nIngrese el Telefono de su nuevo contacto"<<endl;
        getline(cin, phone);

        cout<<"\nIngrese la Direccion de su nuevo contacto"<<endl;
        getline(cin, address);

        cout<<"\nIngrese el Nombre de su nuevo contacto"<<endl;
        getline(cin, name);

        A.addFirst(id, mail, phone, address, name);

      }
      break;

      case 9:{
        A.ordenarName();
      }
      break;

      case 10:{
        A.ordenarId();
      }
      break;

      case 11:{
        A.deleteAll();
        cont=0;
      }
      break;

      case 12:{
        A.invertir();
      }
      break;

      case 13:{
        int id, pos;
        string mail, phone, address, name;

        fflush(stdin);

        std::cout << "\n Se ha asignado el ID: " <<cont<< '\n';
        id = cont;
        cont++;

        cout<<"\nIngrese el E-mail de su nuevo contacto: "<<endl;
        getline(cin, mail);

        cout<<"\nIngrese el Telefono de su nuevo contacto"<<endl;
        getline(cin, phone);

        cout<<"\nIngrese la Direccion de su nuevo contacto"<<endl;
        getline(cin, address);

        cout<<"\nIngrese el Nombre de su nuevo contacto"<<endl;
        getline(cin, name);

        cout<<"\nIngrese la posicion en la que desea insertar su nuevo Contacto"<<endl;
        cin>>pos;

        A.insertarPos(pos, id, mail, phone, address, name);

      }
      break;

      default: std::cout << "\nOpcion no disponible" << '\n';
    }

  } while(opc!=0);

};
