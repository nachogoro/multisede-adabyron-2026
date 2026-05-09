# Problema G - Estos dioses están locos

Llogurcito es un estudiante de quinto de historia antigua. Está
estudiando la mitología griega, que es muy extensa y extraña. Para
nosotros cada ser humano es descendiente de un padre y una madre. Pero
para ellos esto sería demasiado sencillo. En el universo mitológico
sucede que salen seres a partir de un solo ser, de dos, de tres, o de
los que haga falta. Incluso algunos seres como Caos han sido
engendrados de la nada. Pero en ningún caso sucede que un personaje es
engendrado por el mismo.

Llogurcito, aunque le cuesta, acepta que esto pueda suceder, pero no
va a aceptar que un personaje de la mitología sea descendiente de un
propio descendiente suyo, ¡eso sí que no!

Tenemos que indicarle si la configuración del árbol genealógico es
posible.

## Entrada

La entrada comienza con un número $t$ que indica el número de árboles
genealógicos a tratar. Cada árbol comienza con el número de personajes
$N$. A continuación, para cada personaje $i$ ($1 \le i \le N$) tenemos
$M_i$ el número de ascendientes que tiene el personaje $i$, seguido de
$M_i$ números $a_1, a_2, ..., a_{M_i}$, los índices de sus antecesores
($1 \le a_j \le N$ y $a_j \ne i$). Entre todos los casos de prueba
nunca se superarán los $10^4$ personajes.

## Salida

Para cada caso de prueba tiene que indicar si es posible (`SI`) o no
es posible (`NO`).

## Entradas de ejemplo

```
2
4
0
1 1
3 1 2 4
2 1 2
5
1 2
1 3
2 1 2
0
0
```

## Salidas de ejemplo

```
SI
NO
```
