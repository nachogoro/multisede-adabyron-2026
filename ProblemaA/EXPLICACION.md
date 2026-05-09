# Introducción a la solución

Tenemos una lista de archivadores; cada uno con un número de cliente y
una prioridad entre $1$ y $5$. Algunos están rotos y, en lugar de su
prioridad real, su prioridad pasa a $6$. Hay que imprimirlos
ordenados:

1. Primero por prioridad de menor a mayor (los rotos, con prioridad
   $6$, quedan al final).
2. Dentro de la misma prioridad, por número de cliente de menor a
   mayor.

Cuando se imprime un archivador roto, en lugar de la prioridad ($6$)
se escribe la palabra `ROTO`.

# La idea

El truco del enunciado es darse cuenta de que el archivador roto no
es un caso especial para el orden, solo para la impresión. Si los
rotos llevasen una prioridad cualquiera distinta de las normales, el
problema sería trivial; al asignarles la prioridad $6$, el propio
enunciado nos lo está poniendo en bandeja: el mismo criterio
*(prioridad, cliente)* sirve para ordenar los dos grupos a la vez.
Solo cuando vamos a escribir la salida nos preocupamos de si la
prioridad es $6$ para sustituirla por `ROTO`.

A partir de ahí, la solución es directa:

1. Leer los $n$ archivadores como pares.
2. Ordenarlos por *(prioridad, cliente)*.
3. Imprimirlos uno detrás de otro, escribiendo `ROTO` cuando la
   prioridad sea $6$.

# El coste

La operación dominante es el `sort`, que es $O(n \log n)$. Con $n \le
10^4$ archivadores por caso, sobra holgadamente.

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [A.cpp](src/A.cpp) | :x: |
