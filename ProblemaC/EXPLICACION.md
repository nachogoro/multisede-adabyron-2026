# Introducción a la solución

Tenemos una rejilla unidimensional con alturas. Si dejamos a Oniso
hecho bola en una posición $x$, puede pasar una de tres cosas:

- Rueda a $x+1$ si $h[x+1] < h[x]$ y $h[x-1] > h[x]$.
- Rueda a $x-1$ si la condición simétrica se cumple.
- Se queda quieto en cualquier otro caso.

Hay que contar desde cuántas posiciones acaba mojado, es decir, en
una celda con altura $\le 0$. Fuera del jardín la altura es siempre
mayor que cualquier altura del jardín, lo cual sirve para impedir que
la bolita se salga por los bordes.

# Enfoque ingenuo

Lo más natural es, para cada posición de salida $x$, simular el
descenso de la bola hasta que se pare y comprobar la altura del
destino. Eso da un coste de $O(w)$ por simulación y, en el peor caso
(una pendiente larga), $O(w^2)$ en total. Con $w \le 10^5$ por jardín
no es viable.

# La idea: expansión inversa desde el agua

Conviene mirar el problema al revés. Las celdas con $h[x] \le 0$
están mojadas seguro: están en el agua. Si una celda $x$ está mojada
y desde su vecina $y$ se rueda hacia $x$, entonces $y$ también acaba
en el agua (porque rodar es determinista: una vez en $x$, la bolita
ya no puede ir a otra parte mojada que no sea esa misma).

Esto sugiere recorrer el jardín como un *BFS* hacia atrás:

1. Marcamos como mojadas todas las celdas con $h[x] \le 0$ y las
   metemos en una cola.
2. Sacamos celdas de la cola una a una. Para cada celda $x$ que
   sacamos, miramos sus dos vecinos:
   - El vecino izquierdo $x-1$ rueda hacia $x$ si $h[x] < h[x-1] <
     h[x-2]$. Si se cumple y aún no estaba marcado, lo marcamos y lo
     añadimos a la cola.
   - Simétrico por la derecha.
3. Al vaciar la cola, contamos cuántas celdas del jardín han quedado
   marcadas.

La condición de "rodar a la izquierda" y la de "rodar a la derecha" son
mutuamente excluyentes (una pide $h[x-1] < h[x] < h[x+1]$ y la otra $h[x+1] <
h[x] < h[x-1]$), así que cada celda no mojada se descubrirá *como máximo* desde
un único vecino. La comprobación "si aún no estaba marcada" es solo para no
reencolar celdas, no porque haya ambigüedad en quién la moja.

# Los centinelas

La regla "fuera del jardín la altura es siempre mayor que cualquier
altura del jardín" tiene una traducción muy cómoda: añadir dos
celdas ficticias, una en $-1$ y otra en $w$, ambas con altura `LINF`
(un valor mayor que cualquier $a_i$ posible).

Con los centinelas, los chequeos $h[x-1]$ y $h[x-2]$ (o $h[x+1]$ y
$h[x+2]$) se hacen sin condicionales adicionales: cuando se está
junto al borde, el centinela hace que se cumpla la condición de
"altura mayor en el otro lado", que es justo lo que pide el
enunciado. En la solución se reservan $w + 2$ posiciones y los
índices reales son $1, \ldots, w$.

# Variante: DP top-down memoizada

El mismo problema puede plantearse en sentido directo. Como cada
celda rueda a un destino único (o se queda quieta) y, cuando rueda,
lo hace estrictamente hacia abajo, el grafo de dependencias entre
celdas es acíclico. Eso permite definir

$$ dp[x] = \text{¿la bola que sale de } x \text{ termina mojada?} $$

con la siguiente recurrencia:

- Si $h[x] \le 0$, $dp[x]$ es cierto.
- Si rueda a $x+1$, $dp[x] = dp[x+1]$.
- Si rueda a $x-1$, $dp[x] = dp[x-1]$.
- Si se queda quieto, $dp[x]$ es falso.

Implementada como recursión con memoización queda muy compacta. La preocupación
natural es la profundidad de la pila: con $w = 10^5$ y una pendiente larga, el
árbol de llamadas puede tener profundidad $w$. Sin embargo, cada frame de
`resolver` solo guarda el retorno y un par de variables locales (del orden de
$32$–$48$ bytes con la sobrecarga típica del compilador). Con los $8$ MB de
pila por defecto debería entrar holgado. Si el escenario fuera $w \sim 10^6$ o
un juez con la pila recortada, lo razonable sería desenrollar la recursión a
una pila explícita.

# El coste

Cada celda entra en la cola (o en la pila de programa) como mucho una
vez y se procesa en tiempo constante, así que cada caso es $O(w)$.
El enunciado garantiza que el total de alturas entre todos los casos
no supera $10^6$, así que el coste total queda limpiamente acotado.

# Soluciones

| Solución | Descripción | Verificado con el juez |
| :------: | :---------- | :--------------------: |
| [C.cpp](src/C.cpp)       | BFS inverso desde las celdas con agua. | :x: |
| [C_dp.cpp](src/C_dp.cpp) | DP top-down recursiva con memoización. | :x: |
