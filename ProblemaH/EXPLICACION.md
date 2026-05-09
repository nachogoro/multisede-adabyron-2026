# Introducción a la solución

Tenemos un grafo no dirigido y ponderado (los claros son los nodos y
los senderos son las aristas, con peso igual al tiempo de recorrido).
Queremos el camino más corto del claro $S$ al claro $D$, además del
propio camino para imprimirlo. El enunciado nos garantiza que el
camino existe y que es único, así que no hay que preocuparse por el
desempate.

# La idea: Dijkstra recordando antecesores

Dijkstra con cola de prioridad calcula la distancia mínima desde $S$
a todos los demás nodos. Para poder *reconstruir* el camino, basta
con guardar, junto a cada distancia mejorada, el nodo desde el que
se ha llegado:

```
si dist[u] + w(u, v) < dist[v]:
    dist[v]  = dist[u] + w(u, v)
    padre[v] = u
```

Cuando se acaba el algoritmo, el camino óptimo a $D$ se recupera
recorriendo los padres hacia atrás: $D \to \mathrm{padre}[D] \to
\mathrm{padre}[\mathrm{padre}[D]] \to \cdots \to S$. Invertimos esa
lista y la imprimimos.

Como solo nos interesa $D$, podemos cortar Dijkstra en cuanto $D$
sale de la cola con su distancia definitiva.

# Coste

Dijkstra con *binary heap* (la `priority_queue` de la STL) cuesta
$O((N + M) \log N)$ por caso de prueba. Con $N \le 10^5$ y $M \le
6 N$, queda muy por debajo de cualquier límite habitual.

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [H.cpp](src/H.cpp) | :x: |
