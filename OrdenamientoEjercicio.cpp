#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float media(int matriz[], int m);
float mediana(int matriz[],int m);
float moda(int matriz[],int m);
float histograma(int matriz[],int m);

int main(void)
{
	int i, j, posicion, temp=0, n, max, min;
    
    srand(time(NULL));
    
    printf("Numero de Elementos a Ordenar: ");
    scanf("%d", &n);
    int lista[n];
    
    // Generate random numbers and populate the array
    for(i = 0; i < n; i++)
    {
        lista[i] = rand() % (100 + 1 - 1) + 1;
    }
    
    // Initialize max and min with the first element of the array
    max = lista[0];
    min = lista[0];
    
    // Find the maximum and minimum values
    for(i = 0; i < n; i++)
    {
        if(lista[i] > max)
        {
            max = lista[i];
        }	
        if(lista[i] < min)
        {
            min = lista[i];
        }	
    }
    
    // Print the original array, maximum, and minimum values
    printf("Lista sin Ordenar\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", lista[i]);
    }
    printf("\n");
    
    for (i=0; i<n; i++)
	{
		posicion=i;
		for(j=i+1;j<n;j++)
		{
			if(lista[posicion]>lista[j])
			{
				posicion=j;
			}
		}
		if(posicion!=i)
		{
			temp=lista[i];
			lista[i]=lista[posicion];
			lista[posicion]=temp;
		}
	}
		//printf("%d ",b[j]);
		
	printf("Matriz A Ordenada:\n");
	
	for (i=0; i<n; i++)
	{
		printf("%d ",lista[i]);
	}
	
	printf("\n");
    
    printf("El numero mayor es: %d\n", max);
    printf("El numero menor es: %d\n", min);
    
    printf("\n");
	
	//media(lista,n);
	//moda(lista[n],n);
	//mediana(lista,n);
	printf("La media es: %f\n",media(lista,n));
	printf("La mediana es: %f\n",mediana(lista,n));
	printf("La moda es: %f\n",moda(lista,n));	
	printf("El histograma es: %f\n",histograma(lista,n));		
	
	return 0;
}


float media(int matriz[], int m) 
{
    int i;
    float suma = 0.0, prom;

    for(i = 0; i < m; i++) {
        suma += matriz[i];
    }
    prom = suma / m;

    return prom;
}

float mediana(int matriz[], int m) 
{
    if (m % 2 == 0) 
	{
        return (matriz[m / 2 - 1] + matriz[m / 2]) / 2.0;
    } 
	else 
	{
        return matriz[m / 2];
    }
}

float moda(int matriz[], int m) {
    int maxCount = 0, mode = -1;
    
    for (int i = 0; i < m; i++) {
        int count = 0;
        for (int j = 0; j < m; j++) {
            if (matriz[j] == matriz[i]) {
                count++;
            }
        }
        
        if (count > maxCount) {
            maxCount = count;
            mode = matriz[i];
        }
    }
    
    return (float)mode;
}

float histograma(int matriz[], int m) {
   
    int max = matriz[0];
    for (int i = 1; i < m; ++i) {
        if (matriz[i] > max) {
            max = matriz[i];
        }
    }

    
    int frequency[max + 1];
    for (int i = 0; i <= max; ++i) {
        frequency[i] = 0;
    }

    
    for (int i = 0; i < m; ++i) {
        ++frequency[matriz[i]];
    }

    
    printf("Histograma:\n");
    for (int i = 0; i <= max; ++i) {
        printf("%d: ", i);
        for (int j = 0; j < frequency[i]; ++j) {
            printf("*");
        }
        printf("\n");
    }

    return 0.0; 
}
