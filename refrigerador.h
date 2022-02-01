//  Perez Benitez Damian    
//  Carbajal Urquisa Luis Fhernando

//Estruturas
typedef struct Producto{
    char tipoAlimento[12];
    char nombreAlimento[25];
    float precio;
    int anioCompra;
    int mesCompra;
    int diaCompra;
    int anioCaducidad;
    int mesCaducidad;
    int diaCaducicad;
    int disponibilidad;
}Producto;

typedef struct Nodo{
    Producto *datos;
    struct Nodo *sig;
}Nodo;

typedef struct ListaSimple{
    Nodo *cabeza;
}ListaSimple;

//Funciones para generar las listas
Producto *agregar_Producto (int TIPO);
Nodo *crear_Nodo (Producto *producto);
ListaSimple *crear_ListaSimple ();

//Funciones para editar las listas
int lista_vacia (ListaSimple lista);
void insertar_cabeza (ListaSimple *lista, Nodo *aux);
void insertar_cola (ListaSimple *lista, Nodo *aux);
void insertar_en_medio (ListaSimple *lista, Nodo *anterior, Nodo *elemento);
void quitar_cabeza (ListaSimple *lista);
void quitar_cola (ListaSimple *lista);
void quitar_enmedio (ListaSimple *lista, Nodo *elemento);
Nodo *buscar_Elemento (ListaSimple *lista, Nodo *elemento);
void vaciar_Lista (ListaSimple *lista);
void imprimir_Lista (ListaSimple *lista);

//Funciones de ordenamiento
#define M 20 


//void pedir_numeros();
void pedir_numeros(int a[]);
void print_array(int a[], int n);
void copiar_arreglo(int a[],int b[],int n);

/*Ordenamientos iterativos básicos*/
void ordenamiento_seleccion(int a[], int n);
void ordenamiento_insercion(int a[],int n);
void ordenamiento_burbuja(int a[], int n);
void ordenamiento_burbuja2(int a[], int n);

/*busqueda iterativa*/
int busqueda_binaria(int a[], int n, int elemento);
int busqueda_iterativa(int a[], int n, int elemento);

/*Ordenamientos recursivos*/
void MergeSort(int a[], int primero, int ultimo);
void mezcla(int a[], int izquierda, int central, int derecha);
void Ordenamiento_quick(int a[], int primero, int ultimo);
void QuickSort(int a[], int ini, int fin);
//int busqueda_binaria_recursiva(int a[], int inferior, int superior, int elemento);
int busqueda_binaria_recursiva2(ListaSimple *original, int inferior, int superior, Nodo *elemento,ListaSimple *impresion);
int busqueda_binaria2(ListaSimple *a, Nodo *elemento);
ListaSimple *ordenamiento_Refrigerador (ListaSimple *original,int max);