//  Perez Benitez Damian    
//  Carbajal Urquisa Luis Fhernando

#include "refrigerador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Producto *agregar_Producto (int TIPO){
    Producto *aux = (Producto*)malloc(sizeof(Producto));
    int option = 0, bandera = 1;
    switch (TIPO){
        case 1:
            strcpy(aux->tipoAlimento,"Bebida");
            break;
        case 2:
            strcpy(aux->tipoAlimento,"Embutido");
            break;
        case 3:
            strcpy(aux->tipoAlimento,"Fruta");
            break;
        case 4:
            strcpy(aux->tipoAlimento,"Lacteo");
            break;
        case 5:
            strcpy(aux->tipoAlimento,"Carne");
            break;
        default:
            strcpy(aux->tipoAlimento,"Verdura");
            break;
    }
    printf("\n Ingresa el nombre del producto (usa guiones bajos en vez de espacios): ");
    scanf("%s",&aux->nombreAlimento);
    printf("\n Ingresa su precio: $");
    scanf("%f",&aux->precio);
    printf("\n Dia de compra (en numero): ");
    scanf("%d",&aux->diaCompra);
    printf("\n Mes de compra (en numero): ");
    scanf("%d",&aux->mesCompra);
    printf("\n Anio de compra (en numero): ");
    scanf("%d",&aux->anioCompra);
    do{
        printf("\n Tu protucto tiene una fecha de caducidad especifica?");
        printf("\n Ingresa el numero");
        printf("\n 1) Si\t2) No\nOpcion: ");
        scanf("%d",&option);
        switch (option){
        case 1:
            printf("\n Dia de caducidad (en numero): ");
            scanf("%d",&aux->diaCaducicad);
            printf("\n Mes de caducidad (en numero): ");
            scanf("%d",&aux->mesCaducidad);
            printf("\n Anio de caducidad (en numero): ");
            scanf("%d",&aux->anioCaducidad);
            bandera = 0;
            break;
        case 2:
            aux->diaCaducicad = 0;
            aux->mesCaducidad = 0;
            aux->anioCaducidad = 0;
            bandera = 0;
            break;
        default:
            printf("\nIngresa un numero valido\n");
            break;
        }
    }while(bandera != 0);
    printf("\n Tiene disponibilidad?");
    printf("\n Ingresa el numero");
    printf("\n 1) Si\t2) No\nOpcion: ");
    scanf("%d",&option);
    if(option == 1)
        aux->disponibilidad = 1;
    else    
        aux->disponibilidad = 0;
    return (aux);
}

Nodo *crear_Nodo (Producto *producto){
    Nodo *aux = (Nodo*)malloc(sizeof(Producto));
    aux->datos = producto;
    aux->sig = NULL;
}

ListaSimple *crear_ListaSimple (){
    ListaSimple *aux = (ListaSimple*)malloc(sizeof(ListaSimple));
    aux->cabeza = NULL;
    return (aux);
}


//Funciones para editar las listas
int lista_vacia (ListaSimple lista){
    if (lista.cabeza == NULL){
        return (1);             //Lista vacia
    }
    else{
        return (0);             //Lista NO vacia
    }
}

void insertar_cabeza (ListaSimple *lista, Nodo *aux){
    if (lista_vacia(*lista) == 1){
        lista->cabeza = aux;    
    }
    else{
        aux->sig = lista->cabeza;
        lista->cabeza = aux;
    }
}

void insertar_cola (ListaSimple *lista, Nodo *aux);
void insertar_en_medio (ListaSimple *lista, Nodo *anterior, Nodo *elemento);

void quitar_cabeza (ListaSimple *lista){
    Nodo *aux = NULL;   
    if(!lista_vacia(*lista)){
        aux = lista->cabeza;
        lista->cabeza = lista->cabeza->sig;
        free(aux);
    } 
}

void quitar_cola (ListaSimple *lista);
void quitar_enmedio(ListaSimple *lista, Nodo *a){
    Nodo *anterior;
    Nodo *borrar;
    if(lista_vacia(*lista)==1){
        printf("\n La pila esta vacia estoy dentro del procedimiento quitar enmedio \n");    
    }
    else{
        borrar=buscar_Elemento(lista,a);//pendiente
        if(borrar==NULL){
            printf("\n No esta el elemento \n");  
        }
        else{
            if(lista->cabeza == borrar){
                quitar_cabeza(lista);
            }
            else{
                anterior=lista->cabeza;
                while(anterior->sig != borrar){
                    anterior=anterior->sig;
                }
                anterior->sig=borrar->sig;
                free(borrar);
                printf("\nNombre= %s",anterior->datos->nombreAlimento);
            }
        }
    }
}

Nodo* buscar_Elemento(ListaSimple *lista, Nodo *a){
    Nodo* aux = lista->cabeza;
    Producto *alu;
    if(!lista_vacia(*lista)){
        while(aux->datos->nombreAlimento != a->datos->nombreAlimento){
            if(aux->sig !=NULL){
                aux=aux->sig;
            }
            else{
                printf("\nEl elemento con nombre = %s no se encuentra en la lista\n", a->datos->nombreAlimento);
                aux=NULL;
                return(aux);
                break;
            }
        }
        if(aux->datos->nombreAlimento ==  a->datos->nombreAlimento){
            printf("\nEl elemento con nombre = %s si esta en la lista\n", a->datos->nombreAlimento);
            return(aux);
        }
    }
    else{
        printf("\n EL ELEMENTO NO SE ENCUENTRA LA LISTA NO TIENE NADA \n");
        return(NULL);
    }
    return(aux);
}

void vaciar_Lista (ListaSimple *lista){
    Nodo *aux = lista->cabeza;
    if(lista_vacia(*lista) != 1){
        while (aux != NULL){
            aux = aux->sig;
            quitar_cabeza(lista);
        }
    }
    else
        printf("\nLista vacia\n");
    free(aux);
}

void imprimir_Lista (ListaSimple *lista){
    Nodo *aux = lista->cabeza;
    Producto *product;
    if (lista_vacia(*lista) != 1){
        while (aux != NULL){
            product = aux->datos;
            printf ("\nNombre: %s",product->nombreAlimento);
            printf("\n Tipo: %s",product->tipoAlimento);
            printf("\n Precio: $%.2f",product->precio);
            printf("\n Fecha de compra: %02d/%02d/%d",product->diaCompra,product->mesCompra,product->anioCompra);
            printf("\n Fecha caducidad: %02d/%02d/%04d",product->diaCaducicad,product->mesCaducidad,product->anioCaducidad);
            printf("\n Disponibilidad: %d\n", product->disponibilidad);
            aux = aux->sig;
        }
    }
    else
        printf("\nLista vacia\n");
}
                        /* FUNCIONES DE ORDENAMIENTO */
/*Funciones para manipulación del arreglo*/

void pedir_numeros(int a[]){
    int num, i;
    printf("\nDame 10 numeros entre 1 y 10 conforme se soliciten");

    for(i=0; i<10;i++){
        verificar:
            printf("\nDame un numero entre 1 y 10\n");
            scanf("%d",&num);
            if(num >0 && num <11){
                a[i]=num;
            }
            else{
                printf("\nNumero fuera de rango ingresa uno nuevo\n");
                goto verificar;
            }
    }
}

void print_array(int a[], int n){
    int i;
    for(i=0; i<n;i++){
        printf("\nEl numero en la posición %d es %d", i, a[i]);
    }
    printf("\nimpresion finalizada");
}

void copiar_arreglo(int a[],int b[],int n){
    int i;
    for(i=0; i<n;i++){
        b[i]=a[i];
        
    }
    printf("\nEl arreglo se copio correctamente");
}

/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/
/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/
/*ORdenamientos básicos */

void ordenamiento_seleccion(int a[], int n){
    int indiceMenor, i , j;
    for(i=0; i<n-1; i++){
        indiceMenor=i;
        for(j=i+1 ; j<n ; j++){
            if(a[j] < a[indiceMenor]){
                indiceMenor = j;
            }
        }
        if(i != indiceMenor){
            int aux = a[i];
            a[i]=a[indiceMenor];
            a[indiceMenor]=aux;
        }
    }
    printf("\nYa ordené ascendentemente todos los elementos");
}

void ordenamiento_insercion(int a[],int n){
    int i,j,aux;
    for(i = 1; i < n ; i++){
        j = i;
        aux = a[i];
        while(j > 0 && aux < a[j-1]){
            a[j] = a[j-1];
            j--;
        }
        a[j] = aux;
    }
    printf("\nYa ordené ascendentemente todos los elementos");
}

void ordenamiento_burbuja(int a[], int n){  // a= [7,5,2,9] //a= [5,2,7,9]
    int interruptor=1; //n=4
    int pasada, j;
    //pasada = 0 hasta pasada < 4-1=3 && iterruptor=1
    for(pasada = 0; pasada < n-1 && interruptor; pasada++){ //pasada=1//pasada=2
        interruptor =0;
        //desde j=0 hasta j menor 4-1-1=2
        for(j=0 ; j < n-pasada-1 ; j++){ //j=0 //j=1//j=2 /////con pasada=2 4-2-1=1
            if(a[j]>a[j+1]){ //5>2//5>7//   ///2>5
                int aux;
                interruptor=1;
                aux= a[j]; // aux=5
                a[j]=a[j+1];//a[0]=2
                a[j+1]=aux;//a[1]=5...a= [2,5,7,9]
            }
        }
    } 
    printf("\nYa ordené ascendentemente todos los elementos");   
}

void ordenamiento_burbuja2(int a[], int n){ //a= [7,5,2,9], n=4
    int i,j, indiceIntercambio;
    i = n-1;  //i=4-1=3
    while(i>0){ //3>0
        indiceIntercambio = 0;
        for(j=0 ; j<i ; j++){ //desde j= 0 hasta j < 3 con j=0// j=1 //j=2 //j=3
            if(a[j+1]<a[j]){ // 5<7 // 2<7 //9<7
                int aux = a[j]; //aux=7 // aux=7
                a[j] = a[j+1]; //a[0]=5 //a[1]=2
                a[j+1] = aux; //a[1]=7 ... a[5,7,2,9] //a[2]=5...a[5,2,7,9]
                indiceIntercambio = j; //iI=0 //iI=1
            }
        }
        i = indiceIntercambio; //i=1
    }
    printf("\nYa ordené ascendentemente todos los elementos");
}

/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/
/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/
/*Busquedas iterativas o secuenciales (simples)*/

/*Busqueda binaria iterativa*/
/*devuelve el indice del elemento buscado en caso de ser encontrado o un -1 en caso de no estar*/
/*int busqueda_binaria(int a[], int n, int elemento){ //a= [2,4,6,8,10,12,14,16,18,19,20,22,24]
    int central, bajo, alto, valorCentral;
    bajo = 0;
    alto = n-1; //alto = 12
    printf("\nEl elemento a buscar en la lista es el %d", elemento);
    while(bajo <= alto){ //0 <= 12    ////0 <= 5
        central = (bajo + alto)/2; //central = 0+12/2= 6  ////central= 0+5/2= 2.5->2
        //printf("\nposicion central = %d",central);
        valorCentral = a[central]; //vC= 14 ////vC=6
        //printf("\nvalor central = %d",valorCentral);
        
        if(elemento == valorCentral){ //14==14 // 8==14 /// 8 ==6
            printf("\nEl elemento %d se encuentra en la posición %d", elemento, central);
            printf("\nYa encontré el elemento que buscabas por busqueda binaria iterativa, regresaré al menú principal...");
            return (central);
        }
        else if(elemento < valorCentral){ //8 < 14 ////8<6
            alto = central - 1; //alto = 6-1 = 5
        }
        else{ ////
            bajo = central + 1; //bajo = 2+1=3
        }
    }
    printf("\nError el elemento %d no se encuentra en ninguna posición de la lista, regresaré al menú princupal...",elemento);
    return (-1);
}*/

/*Busqueda iterativa*/
int busqueda_iterativa(int a[], int n, int elemento){
    int i;
    printf("\nEl elemento a buscar en la lista es el %d", elemento);
    for(i=0; i<n;i++){
        if(a[i] == elemento){
            printf("\nEl elemento %d se encuentra en la posición %d", elemento, i);
            printf("\nYa encontré el elemento que buscabas por busqueda iterativa, regresaré al menú principal...");
            return(i);
        }
    }
    printf("\nError el elemento %d no se encuentra en ninguna posición de la lista, regresaré al menú princupal...",elemento);
    return(-1);
}

/* Ordenamientos recursivos*/

/*El ordenamento de mezclas o Mergesort necesita de dos funciones, de si misma y de otra función que
se encargara de ordenar o "mezclar" los elementos*/

void MergeSort(int a[], int primero, int ultimo){
    int central;
    if(primero < ultimo)
    {
        central = (primero + ultimo)/2;
        MergeSort(a, primero, central);
        MergeSort(a, central+1, ultimo);
        mezcla(a, primero, central, ultimo);
    }
}

void mezcla(int a[], int izquierda, int central, int derecha){
    int temp[M];
    int x,y,z;
    x = z = izquierda;
    y = central + 1;

    while(x <= central && y <= derecha){
        if(a[x] <= a[y]){
            temp[z++] = a[x++];
        }
        else{
            temp[z++] = a[y++];
        }
    }    
    while(x <= central){
        temp[z++] = a[x++];
    }
    while(y<=derecha){
        temp[z++] = a[y++];
    }
    for(z= izquierda ; z <= derecha ; z++){
        a[z] = temp[z];
    }
}

/*Ordenamiento recursivo Quicksort*/
/*Ordenamiento rapido*/

void Ordenamiento_quick(int a[], int primero, int ultimo){
    printf("hola");
    int i, j, central, pivote;
    printf("llego aqui");
    central = (primero + ultimo)/2;
    pivote = a[central];
    i = primero;
    j= ultimo;
    do {
        while(a[j] < pivote){i++;}
        while(a[j] > pivote){j--;}
       
        if(i <= j){
            
            int temp;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }while(i <= j);
    if(primero < j)
        {Ordenamiento_quick(a, primero, j);} //recursión para sublista izquierda
    if(i < ultimo)
        {Ordenamiento_quick(a, i, ultimo);} //recursión para sublista derecha
    //printf("\nYa ordené ascendentemente todos los elementos");
}

void QuickSort(int a[], int ini, int fin){
    int pivote, izq, der, centro;

    if(ini < fin){
        pivote = a[ini];
        izq = ini;
        der = fin;
        while(izq < der){
            while(der > izq && a[der] > pivote){
                der--;
            }
            if(der > izq){
                a[izq] = a[der];
                izq++;
            }
            while(izq < der && a[izq] < pivote){
                izq++;
            }
            if(izq < der ){
                a[der] = a[izq];
                der--;
            }
        }
        a[der] = pivote;
        centro = der;
        QuickSort(a,ini,centro-1);
        QuickSort(a, centro+1,fin);
    }
    
}

/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/
/*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/

/* Busqueda recursiva */

/*int busqueda_binaria_recursiva(int a[], int inferior, int superior, int elemento){
    int central;
    printf("\nEl elemento a buscar en la lista es el %d", elemento);
    if(inferior > superior){
        printf("\nError el elemento %d no se encuentra en ninguna posición de la lista, regresaré al menú princupal...",elemento);
        return(-1);
    }
    else{
        central = (inferior + superior)/2;
        if(a[central] == elemento){
            printf("\nEl elemento %d se encuentra en la posición %d", elemento, central);
            printf("\nYa encontré el elemento que buscabas por busqueda binaria recursiva, regresaré al menú principal...");
            return(central);
        }
        else if(a[central] < elemento){
            return busqueda_binaria_recursiva(a, central+1, superior, elemento);
        }
        else{
            return busqueda_binaria_recursiva(a, inferior, central-1, elemento);
        }
    }
}*/
int busqueda_binaria2(ListaSimple *a, Nodo *elemento){ //a= [2,4,6,8,10,12,12,12,18,19,20,22,24]
    int central, bajo, alto;
    float valorCentral;
    Nodo *aux;
    char z[25];
    aux = a->cabeza;
    bajo = 0;
    alto = 0;
    printf("\nEl elemento a buscar en la lista es el %f", elemento->datos->precio);
    while(a->cabeza->sig!=NULL){
        aux = aux->sig;
        alto++;
    }
    aux = a->cabeza;
    while(bajo <= alto){ //0 <= 12    ////0 <= 5
        central = (bajo + alto)/2; //central = 0+12/2= 6  ////central= 0+5/2= 2.5->2
        //printf("\nposicion central = %d",central);
        for(int i = 0; i<central;i++){
            aux = aux->sig;
        }
        valorCentral = aux->datos->precio; //vC= 14 ////vC=6
        //printf("\nvalor central = %d",valorCentral);
        
        if(elemento->datos->precio == valorCentral){ //14==14 // 8==14 /// 8 ==6
            
        }
      //  else if(elemento < valorCentral){ //8 < 14 ////8<6
        //    alto = central - 1; //alto = 6-1 = 5
        //}
        else{ ////
            bajo = central + 1; //bajo = 2+1=3
        }
    }
    printf("\nError el elemento %d no se encuentra en ninguna posición de la lista, regresaré al menú princupal...",elemento);
    return (-1);
}

int busqueda_binaria_recursiva2(ListaSimple *original, int inferior, int superior, Nodo *elemento,ListaSimple *impresion){
    int central;
    printf("\nEl elemento a buscar en la lista es el %d", elemento);
    Nodo *aux;
    aux = original->cabeza;
    ListaSimple *temporal;
    temporal = crear_ListaSimple();
    temporal = original;
    central = (inferior + superior)/2;
    int i = 0;
    while(i<central){
        aux = aux->sig;
        i++;
    }
    if(inferior > superior){
        printf("\nError el elemento %d no se encuentra en ninguna posición de la lista, regresaré al menú princupal...",elemento);
        return(-1);
    }
    else{
        if(aux->datos->precio == elemento->datos->precio){
            insertar_cabeza(impresion,aux);
            return(central);
            
        }
        else if(aux->datos->precio < elemento->datos->precio){
            return busqueda_binaria_recursiva2(temporal, central+1, superior, elemento,impresion);
        }
        else{
            return busqueda_binaria_recursiva2(temporal, inferior, central-1, elemento,impresion);
        }
    }
}
ListaSimple *ordenamiento_Refrigerador (ListaSimple *original,int max){
    printf("entramos en el ordenamiento\n");
    Nodo *aux1=NULL;
    Nodo *menor=NULL;
    ListaSimple *temporal, *regreso;
    temporal = original;
    regreso = crear_ListaSimple();
        
        while(lista_vacia(*temporal)!=1){
            printf("\nentramos en el bucle\n");
            aux1 = temporal->cabeza;
            menor = aux1;
            aux1=aux1->sig;
            do{
                printf("\nEntramos en el segundo bucle\n");
                if(menor->datos->precio>aux1->datos->precio){
                    printf("\nEntramos en el if\n");
                    menor = aux1;
                    aux1 = aux1->sig;
                    printf("Menor : %s",menor->datos->nombreAlimento);
                }
                else{
                    printf("\nEntramos en else\n");
                    aux1 = aux1->sig;
                }
            }while(aux1->sig!=NULL);
            printf("\nsalimos del segundo bucle\n");
            insertar_cabeza(regreso,menor);
            printf("Imprimir lista regreso*---------------------")
            imprimir_Lista(regreso);

            quitar_enmedio(temporal,menor);
            printf("\nSe quito menor: %s\n",menor->datos->nombreAlimento);
        }
    free(temporal);
    free(aux1);
    free(menor);
    return regreso;
}