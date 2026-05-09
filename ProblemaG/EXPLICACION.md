# Introducción a la solución

Cada personaje declara sus antecesores. Modelamos el árbol genealógico
como un grafo dirigido en el que cada antecesor $a$ apunta hacia su
descendiente $i$ (es decir, una arista $a \to i$ por cada par
"antecesor-descendiente"). El enunciado pide rechazar la
configuración si "un personaje es descendiente de un descendiente
suyo", que en términos de grafo es exactamente que exista un ciclo.

El problema, por tanto, se reduce a comprobar si el grafo dirigido
es acíclico.

# La idea: DFS con tres colores

Una forma estándar de detectar ciclos en un grafo dirigido es un DFS
con tres estados por nodo:

- *Blanco*: aún no se ha visitado.
- *Gris*: está en la rama de DFS que tenemos abierta ahora mismo
  (entre el momento de entrar al nodo y el de salir).
- *Negro*: ya se le ha hecho DFS por completo y se ha cerrado.

Iteramos sobre los nodos en orden y, para cada nodo blanco, lanzamos
un DFS. Al entrar a un nodo lo marcamos gris; al recorrer sus
vecinos:

- Si encontramos un vecino gris, hemos cerrado un ciclo (la rama
  actual ha vuelto a un nodo que aún tenemos abierto). El grafo no
  es acíclico.
- Si encontramos un vecino blanco, recursamos en él.
- Si encontramos un vecino negro, ya está completamente explorado y
  sabemos que no va a llevarnos a ningún ciclo (de haberlo, lo
  habríamos detectado al cerrarlo). Lo ignoramos y seguimos con los
  demás vecinos.

Al salir de un nodo, lo pintamos negro. Si terminamos de procesar
todos los nodos sin haber tocado nunca un gris, el grafo es acíclico.

# Coste

Cada arista se recorre una sola vez en total (al entrar al primero
de sus dos extremos en estado blanco), y cada nodo se procesa una
sola vez. El coste por caso de prueba es $O(N + E)$. Con $N \le 10^4$
sumado entre todos los casos, sobra holgado.

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [G.cpp](src/G.cpp) | :x: |
