# Problema H - Heathcliff en busca de Catherine

Una terrible noticia llega a Cumbres Borrascosas desde la casa de los
Linton: Catherine está gravemente enferma.

Bajo la lluvia y el viento del páramo, Heathcliff debe salir de
inmediato para llegar hasta ella, ya que si no llega a tiempo, teme
que pueda perderla para siempre. Pero el camino está lleno de senderos
que lo llevan por colinas, bosques y ríos. A lo largo del recorrido
hay claros en el páramo donde varios caminos se cruzan. Heathcliff
debe decidir: ¿deberá subir la colina primero o atravesar el río? Cada
sendero tiene un tiempo distinto, y cada minuto cuenta.

Ayuda a Heathcliff a elegir el camino más rápido para llegar a
Catherine y no perder ni un instante.

## Entrada

La entrada está compuesta por diversos casos de prueba, ocupando cada
uno de ellos varias líneas.

La primera línea contiene tres enteros: $N$, $M$ y $S$. $N$ indica el
número de claros ($2 \le N \le 10^5$), $M$ indica el número de
senderos ($N - 1 \le M \le 6N$) y $S$, el claro desde donde comienza
Heathcliff su camino ($1 \le S \le 10^5$). La siguiente línea contiene
un entero que indica el lugar de destino ($1 \le D \le 10^5$), la casa
de los Linton, donde se encuentra Catherine. La siguientes $M$ líneas
describen los senderos. Cada una contiene tres enteros: $U$, $V$ y
$W$. $U$ y $V$ indican los claros conectados por un camino ($1 \le u,
v \le N$) y $W$ indica el tiempo que tarda en recorrer ese sendero
($1 \le W \le 100$).

Se garantiza que para todos los casos el camino mínimo existe y es
único.

## Salida

Para cada caso de prueba se escribirá una línea con el camino que
debe realizar Heathcliff y el tiempo total que tarda en recorrerlo.

## Entrada de ejemplo

```
5 6 1
5
1 2 10
1 3 5
2 3 2
2 4 1
3 4 9
4 5 4
6 8 2
6
1 2 3
2 3 4
2 4 2
3 5 6
4 5 1
4 6 7
5 6 2
1 3 5
```

## Salida de ejemplo

```
1 3 2 4 5 -> 12
2 4 5 6 -> 5
```
