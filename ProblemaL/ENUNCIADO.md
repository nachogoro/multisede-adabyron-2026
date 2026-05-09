# Problema L - Una ronda más y nos ponemos

Desde que se popularizó un conocido juego de cartas por equipos en su
universidad, Juan aprovecha cada rato libre que tiene para buscar a
más personas con las que jugar. Como resultado, siempre acaban los
mismos cuatro pasando las horas en la cafetería de la facultad, o
quedando cualquier domingo por la tarde para echarse una partida en
algún bar.

Un día, tras jugar algunas rondas amistosas contra el equipo *Envido
de Fenwick*, decidieron empezar a contabilizar los puntos para darle
emoción, de manera que ganase el primer equipo en acumular $24$
puntos. Sin embargo, la cosa se torció y Juan acabó perdiendo varias
partidas seguidas. No obstante, esto le dejó pensando... ¿Habrían
podido ganar si hubiesen empezado a contar los puntos en otro
momento?

## Entrada

La entrada estará formada por distintos casos de prueba.

Cada caso de prueba empieza con una línea con dos números, indicando
el número de rondas jugadas en total (hasta $10^6$) y el número de
puntos necesarios para ganar una partida (hasta $10^9$).

A continuación, viene una línea con un número entre $-10^9$ y $10^9$
por cada ronda. Un entero positivo $x > 0$ indica una cantidad $|x|$
de puntos ganados en esa ronda. En cambio, un número negativo $x < 0$
indica que el equipo rival ha ganado $|x|$ puntos. Finalmente, un cero
indica que no se han otorgado puntos a ningún equipo durante esa
ronda.

Se garantiza que entre todos los casos de prueba no habrá más que un
total de $10^6$ rondas.

## Salida

Por cada caso de prueba, se escribirá una línea con el número máximo
de partidas seguidas que se podrían haber ganado, si se pudiese haber
escogido el momento en el que se empezaron a contabilizar los puntos
de la primera partida. Ten en cuenta que cada vez que termina una
partida y empieza la siguiente justo después, los marcadores de
puntos se vuelven a poner a cero.

## Entrada de ejemplo

```
12 24
9 6 3 9 -24 9 26 6 -3 9 3 6
17 47
43 44 32 0 -10 4 37 28 -13 18 26 -22 25 -1 -33 23 35
```

## Salida de ejemplo

```
2
4
```
