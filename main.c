#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"
#include <time.h>
//prueba de gitttttttttttttttttttttttttttttttttttt  PULL

//preuba git push


//prueba gitt pushh 22222
#define ESC 27

//Prototipado.
void optionMenu();
void codigoAscci();
void mostrarDir();
void cargarPilaRandom(Pila *p);//funcion que modifica pila original
void cargaPila(Pila *p);//funcion que modifica pila original
void mostrarPila(Pila p);//funcion que utiliza copia.
void pasapila (Pila *origen, Pila *destino); //funcion que modifica pila original
void pasapilaEnorden(Pila *origen, Pila *destino); //funcion que modifica pila original
void pilaOrdenadaMenores(Pila *p); //funcion que modifica pila original
void insertPilaOrdenada(Pila *p);//funcion que modifica pila original
void unirPilasEnOrden (Pila *origen, Pila *destino);//funcion que modifica pila original
void mostrarEnDecimal(Pila p);//funcion que utiliza copia.
void cargarPilaRandom1digito(Pila *p);//funcion que modifica pila original
void mostrarPilaVertical(Pila p);//funcion que utiliza copia.


float dividirElementosPila( int suma,int cantidad);
float promedioElementosPila(Pila P);
int buscaMenor(Pila *p);
int sumarElementosPila(Pila p);
int contarElementosPila(Pila p);
int DigitosNum(int num);
int buscaNumeroPila(Pila p, int num);

//Cuerpo main.
int main()
{
    srand(time(NULL));  // Inicializar la semilla para números aleatorios
    Pila dada;
    Pila destino;
    inicpila(&dada);
    inicpila(&destino);


//    char option ;
    int option;

    do
    {

        optionMenu();
//        option=getch();
        scanf("%d",&option);
        fflush(stdin);

        system("cls");


        //switch.
        switch(option)
        {

        case 0:

            printf("\nfinalizando programa .......\n");

            break;

        case 1 :
            codigoAscci();

            break;

        case 2 :
            mostrarDir();

            break;

        case 3 :

            cargarPilaRandom(&dada);


            break;
        case 4:

            printf("\n<< Cargando pila  >>\n");
            cargaPila(&dada);

            break;

        case 5:
            mostrarPila(dada);
            break;
        case 6:

            printf("pila de origen cargada\n");
            mostrarPila(dada);
            pasapila(&dada,&destino);
            printf("pila origen descargada\n");
            mostrarPila(dada);
            printf("pila destino cargada \n");
            mostrarPila(destino);

            break;
        case 7:

            printf("pila de origen cargada\n");
            mostrarPila(dada);
            mostrarPila(destino);
            pasapilaEnorden(&dada,&destino);
            printf("pila origen descargada\n");
            mostrarPila(dada);
            printf("pila destino cargada en orden \n");
            mostrarPila(destino);

            break;
        case 8:

            printf("\n pila DADA CARGADA \n");
            mostrarPila(dada);
            system("pause");
            int menor = buscaMenor(&dada);
            printf("El menor es : %d \n",menor);
            printf("\n DADA SIN MENOR \n");
            mostrarPila(dada);

            break;

        case 9:
            printf("Pila con carga inicial\n");
            mostrarPila(dada);
            pilaOrdenadaMenores(&dada);
            printf("pila ordenada\n");
            mostrarPila(dada);

            break;


        case 10:


            printf("pila dada actual\n");
            mostrarPila(dada);
            insertPilaOrdenada(&dada);
            printf("pila dada con carga nueva ordenada\n");
            mostrarPila(dada);

            system("pause");
            system("cls");

            break;


        case 11:



            printf("pila dada cargada\n");
            mostrarPila(dada);
            printf("pila destino \n");
            mostrarPila(destino);
            system("pause");
            unirPilasEnOrden (&dada, &destino);
            printf("pila dada descargada\n");
            mostrarPila(dada);
            printf("pila destino actualizada en orden \n");
            mostrarPila(destino);
            break;

        case 12:

            printf("pila DADA\n");
            mostrarPila(dada);
            float promedio = promedioElementosPila(dada);
            printf("el promedio de la pila es :%.2f\n", promedio);



            break;

        case 13:


            cargarPilaRandom1digito(&dada); //se pasa con & y se usa puntero para editar la pila original.

            mostrarEnDecimal(dada); // se pasas sin & y no se usa puntero para no editar la pila original.


            break;


        case 14:
        {


            int num;                                 //declarar variable.
            printf("ingrese un numero:\n");
            scanf("%d",&num);                       //ingreso y guardado de variable en num.

            int digitos=DigitosNum(num);   // se declara como entero digitos y se dice que digitos=DigitosNum(num) para obtener el return de la funcion, se pasa a la funcion(num) sin & para que utilice una copia.

            printf("el numero: %d tiene %d digitos\n",num,digitos); //muestra copia de num y digitos retornado.
        }
        break;

        case 15:
        {
            int num;
            printf("Ingrese valor a buscar:\n");
            scanf("%d", &num);

            int encontrado = buscaNumeroPila(dada, num);// se declara encontrado como entero y se indica que  int encontrado = buscaNumeroPila(dada, num), para obtener el retorno de la funcion. dada y num estan sin & porque se pasan como copia.

            if (encontrado == 1)
            {
                printf("\nEl número %d se encuentra en la pila\n", num); //si encontrado devuelve 1 imprime que esta.
            }
            else
            {
                printf("\nEl número %d no se encuentra en la pila\n", num); //si encontrado devuelve 1 imprime que NO esta.
            }
        }
        break;


        }
        system("pause");
        system("cls");
    }
    while(option!=0);

    return 0;
}


//Funciones.
void optionMenu()
{
    printf("\n\t\t\t\t\t || MENU OPCIONES ||\n");

    printf("\n1-tabla ASCCI \n");
    printf("\n2-Mostrar Directorio \n");
    printf("\n3-Carga pila random\n");
    printf("\n4-Carga pila\n");
    printf("\n5-Muestra pila\n");
    printf("\n6-Pasar pila\n");
    printf("\n7-Pasar pila en orden \n");
    printf("\n8- Hacer una función que encuentre el menor elemento de una pila y lo retorna. La misma debe eliminar ese dato de la pila\n");
    printf("\n9- Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 4. (Ordenamiento por selección)");
    printf("\n10- Hacer una función que inserta en una pila ordenada un nuevo elemento, conservando el orden de ésta.\n");
    printf("\n11- Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 6. (Ordenamiento por inserción)\n");
    printf("\n12- Hacer una función que calcule el promedio de los elementos de una pila, para ello hacer también una función que calcule la suma, otra para la cuenta y otra que divida. En total son cuatro funciones, y la función que calcula el promedio invoca a las otras 3\n");
    printf("\n13- Hacer una función que reciba una pila con números de un solo dígito (es responsabilidad de quien usa el programa) y que transforme esos dígitos en un número decimal.\n");
    printf("\n14- Hacer función que retome cuántos dígitos tiene un número ingresado\n");
    printf("\n15- Buscar un numero en una pila\n");


    printf("\n0-para salir ...\n");
}



void codigoAscci() // muestra codigo ascii.
{

    for(int i=0 ; i<256; i++)
    {

        printf("nro: %4d -- %4c ||",i,i);

        if(i%5==0)
        {


            printf("\n");
        }

    }

}

void mostrarDir()//muestra directorio raiz.
{

    system("dir");
}
void cargarPilaRandom(Pila *pila) //carga pila de manera random.
{


    int cant=0;

    printf("\n\n Cargar Pila Random\n");
    printf("\n cuantos numeros desea cargar\n");
    scanf("%d",&cant);



    for(int i=0; i<cant; i++)
    {
//       int num=rand()%100;
//
//       apilar(&dada,num);

        apilar(pila,rand()%100);


    }
    printf("\ncargando pila\n");

}
void mostrarPila(Pila p)//muestra pila en orden usando una copia , por eso no usa puntero, para no alterar la pila orig.
{

    Pila aux;
    inicpila(&aux);

    int cont = 0;



    while(!pilavacia(&p))
    {

        printf("%4d |",tope(&p));
        cont++;
        if(cont%5==0) printf("\n");

        apilar(&aux,desapilar(&p));

    }
    printf("\n");
    printf("\n");
}

void cargaPila(Pila *p) //carga pila de manera manual
{
    int nro;
    char option = 's';

    do
    {
        printf("ingrese dato a cargar\n");
        scanf("%d", &nro);
        fflush(stdin);
        apilar(p, nro);
        printf("\n\ desea seguir cagando s/n\n");
        scanf("%c",&option);
        fflush(stdin);
    }
    while(option =='s');  /// cont != 27
}

void pasapila(Pila *origen, Pila *destino) //pasa elementos de una pila a la otra .
{


    while(!pilavacia (origen))
    {


        apilar (destino,desapilar (origen));


    }


}
void pasapilaEnorden(Pila *origen, Pila *destino)// pasa elementos de una pila a la otra en el orden de la primera.
{
    Pila aux;
    inicpila(&aux);

    pasapila(origen,&aux);
    pasapila(&aux,destino);

}





void pilaOrdenadaMenores(Pila *p) //ordena una pila de menor a mayor.
{
    Pila menores;
    inicpila(&menores);

    while(!pilavacia(p))
    {
        int menor = buscaMenor(p);
        apilar(&menores,menor);
    }
    pasapila(&menores,p);
}

void insertPilaOrdenada(Pila *p) //ingresa uno o varios datos de manera manual y ordena la pila de menor a mayor.
{

    cargaPila(p);

    pilaOrdenadaMenores(p);

}
void unirPilasEnOrden (Pila *origen, Pila *destino) // pasa una pila a otra y la ordena de menor a mayor a medida que va cargando la pila.
{

//7. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una
//nueva pila ordenada. Usar la función del ejercicio 6. (Ordenamiento por inserción)

    while(!pilavacia (origen))
    {

        apilar(destino,desapilar(origen));

        pilaOrdenadaMenores(destino);
    }
}

float promedioElementosPila(Pila p)//calcula el promedio de una pila llamando 3 variables.
{

    int suma=sumarElementosPila(p);
    int cantidad=contarElementosPila(p);


    float promedio=dividirElementosPila(suma,cantidad);

    return promedio;
}



int buscaMenor(Pila *p) // busca el menor en una pila.
{
    if (pilavacia(p))
    {
        printf("La pila está vacía, no hay menor.\n");
        return -1; // Retorno de error
    }

    Pila aux;
    inicpila(&aux);
    Pila aux2;
    inicpila(&aux2);
    int menor = desapilar(p); // Extraer el primer elemento como referencia

    while (!pilavacia(p))
    {
        if (tope(p) < menor)
        {
            apilar(&aux, menor);  // Guardamos el anterior menor en aux
            menor = desapilar(p); // Nuevo menor encontrado
        }
        else
        {
            apilar(&aux, desapilar(p));
        }
    }
    pasapila(&aux,p);

    return menor;
}
// Restaurar la pila sin el menor
//    while (!pilavacia(&aux))
//    {
//        if (tope(&aux) != menor)  // Solo re-apilamos los que no sean el menor
//        {
//            apilar(p, desapilar(&aux));
//        }
//        else
//        {
//            apilar(&aux2,desapilar(&aux)); // Eliminamos el menor sin volver a apilarlo
//        }
//    }
//
//    return menor;
//}

int DigitosNum(int num)// cuenta cuantos digitos tiene un numero ingresado. se declara (int num) sin puntero y se utiliza la copia de num en case 14.
{



    if (num == 0)
    {
        return 1; // El número 0 tiene 1 dígito. digitos retorna como 1.
    }

    if (num < 0)
    {
        num = -num; // Convertimos a positivo para contar los dígitos correctamente.
    }

    int digitos = 0;// se vuelve a declarar como entero .siempre inicializar en 0.

    while (num > 0) //cuando el numero mayor a 0 lo divide x 10 y suma 1 por cada ciclo.
    {
        digitos++; //contador
        num = num / 10;
    }

    return digitos;
}
int sumarElementosPila(Pila p)//suma todos los elementos dentro de una pila.
{

    Pila aux;
    inicpila(&aux);
    int suma=0;


    while(!pilavacia(&p))
    {

        suma= suma+tope(&p);
        apilar(&aux,desapilar(&p));

    }
    return suma;
}

int contarElementosPila(Pila p)//cuenta cuantos elementos tiene una pila.
{
    Pila aux;
    inicpila(&aux);
    int cantidad=0;

    while(!pilavacia(&p))
    {
        cantidad++;
        apilar(&aux,desapilar(&p));
    }
    return cantidad;
}

float dividirElementosPila( int suma,int cantidad)//divide los elementos de una pila para calcular un prommedio.
{
    float div = (float)suma/(float)cantidad;

    return (float)div;
}

int buscaNumeroPila(Pila p, int num) //busca un numero en la pila y devuelve un 1 si se encontro.
{
    Pila aux;
    inicpila(&aux);
    int encontrado = 0; //inicializar siempre en 0

    while (!pilavacia(&p)) //mientras la pila no este vacia.
    {
        if (tope(&p) == num) //si tope es == a num.
        {
            encontrado = 1; // Encontrado, pero seguimos recorriendo
        }
        apilar(&aux, desapilar(&p));
    }

    // Restaurar la pila original
    pasapila(&aux, &p);

    return encontrado; //si se encuentra el numero buscado en la pila encontrado va cambiar a 1, si se vacio la pila y no estaba el n° encontrado queda en 0 como esta al inicio.

}

void mostrarEnDecimal(Pila p) //Muestra los numeros dentro de una pila como decimal.
{
    Pila aux;
    inicpila(&aux);

    printf("\pila cargada con numeros de 1 solo digito\n");
    mostrarPilaVertical(p);

    system("pause");
    while(!pilavacia(&p))
    {
        printf("%d",tope(&p));
        apilar (&aux,desapilar(&p));


    }

    printf("\n");
//    while (!pilavacia(&aux)){
//            printf("%d" ,tope(&aux));
//          apilar (&p,desapilar(&aux));

//    }

}

void cargarPilaRandom1digito(Pila *p)//Carga pila con numeros de 1 solo digito de 0 a 9.
{


    int num;
    printf("ingrese cantidad de numeros a cargar \n");
    scanf("%d",&num);

    for(int i=0; i<num; i++)
    {

        apilar(p,rand()%9);

    }
    printf("\ncargando pila\n");

}

void mostrarPilaVertical(Pila p) //Muestra pila de arriba hacia abajo.
{

    Pila aux;
    inicpila(&aux);


    printf("mostrando pila apilada DADA\n\n\n");

    while(!pilavacia(&p))
    {
        printf("%d\n",tope(&p));
        apilar(&aux,desapilar(&p));

    }
}
