# Introducción a la solución

Tras cada envío hay que reportar la puntuación de quien ocupe la
$k$-ésima posición en la clasificación, ordenada de mayor a menor.
Como las puntuaciones de los concursantes cambian a lo largo del
tiempo, no basta con un `sort` puntual: hay que mantener la
clasificación de forma incremental, con un coste por envío que no
crezca con $n$.

# La idea: separar el top del resto

Llamemos *top* al conjunto de los $k$ concursantes con mayor
puntuación en cada momento, y *resto* a los $n - k$ restantes. La
respuesta tras cada envío es la puntuación más baja del *top*, que
es a su vez la "frontera" entre las dos partes.

Mantenemos dos estructuras ordenadas, una para cada conjunto. Tras
cada envío, los datos clave a la vista son:

- El mínimo de las puntuaciones del *top*. Es la respuesta.
- El máximo de las puntuaciones del *resto*. Lo necesitamos para
  saber si, tras el cambio, alguien del *resto* debería pasar al
  *top*.

# Implementación con dos multisets

Cada estructura se modela con un `multiset<pair<long long, int>>` con
pares (puntuación, identificador). Como los `multiset` están
ordenados, el primer elemento del *top* es la frontera y el último
del *resto* es el mejor de los rezagados, ambos accesibles en $O(1)$
con `begin()` y `rbegin()`.

Tras leer un envío $(p, d)$:

1. Buscamos el par antiguo $(\text{puntos}[p], p)$ y lo borramos del
   multiset que le toque, según `en_top[p]`.
2. Actualizamos $\text{puntos}[p] \mathrel{+}= d$ e insertamos el par
   nuevo en el mismo multiset.
3. Si el mejor del *resto* supera ahora al peor del *top*, los
   intercambiamos. Como en este envío solo ha cambiado la puntuación
   de $p$, basta un único intercambio: ningún otro concursante puede
   merecer subir.

Tras la posible permutación, el primer elemento del *top* es la
respuesta del envío.

# Coste

Cada envío hace un puñado de operaciones de inserción y borrado en
las dos estructuras. Tanto los multisets como los heaps las
realizan en $O(\log n)$. Total por caso: $O((n + m) \log n)$.

# Soluciones

| Solución | Descripción | Verificado con el juez |
| :------: | :---------- | :--------------------: |
| [I.cpp](src/I.cpp)             | Dos multisets con borrado e inserción explícitos. | :x: |
