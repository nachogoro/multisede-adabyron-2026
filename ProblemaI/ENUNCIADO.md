# Problema I - Por delante de los primeros

A diferencia de otros concursos de programación como el *AdaByron* que
estáis concursando ahora mismo, en la Olimpiada Informática cada envío
puede dar por un número variable de puntos. Esta medida pretende
evitar situaciones de empate, por lo que los envíos erróneos, o el
tiempo que se tarda en resolver un problema, pasan a ser preocupaciones
menores para los concursantes.

Para motivar a sus alumnos a participar, José María, un profesor de
instituto, aseguró que si alguien quedaba *estrictamente* por delante
del primer puesto, entonces los invitaría a todos a cenar. Tras darse
cuenta de que eso era matemáticamente imposible (dado que quedar en
primer puesto no cuenta como quedar por delante de los primeros), al
final se conformó con que alguien quedase por delante de la $k$-ésima
posición. Si alguno de sus estudiantes lo logra, prometió invitarlos a
todos a una deliciosa merienda en la cafetería de la facultad. Al fin
y al cabo, el profesor estará contento de su duro trabajo, siempre y
cuando no terminen por detrás de los últimos.

## Entrada

La entrada empieza con una línea indicando el número de casos de
prueba que vendrán a continuación.

Cada caso de prueba empieza con una línea con tres números que indican
el número $n$ de participantes que hay en el concurso (hasta $10^5$),
el número total de envíos $m$ que se producen a lo largo del concurso
(hasta $10^5$) y la posición $k$ en la que se quiere estar durante el
tiempo de concurso (entre $1$ y $n$).

A continuación, vienen $m$ líneas con la información de todos los
envíos, ordenados según el instante en el que se producen. Cada una
de esas líneas contiene dos enteros, indicando el identificador del
concursante que ha realizado ese envío (entre $1$ y $n$), y la
cantidad de puntos conseguidos (entre $0$ y $10^9$).

## Salida

Por cada caso de prueba se escribirá una línea con $m$ números
separados por un espacio. Cada número indica, tras cada envío, la
puntuación que tendrá el concursante que ocupe la $k$-ésima posición.

## Entrada de ejemplo

```
2
3 4 2
1 5
2 4
3 7
1 2
3 3 3
1 5
2 4
3 7
```

## Salida de ejemplo

```
0 4 5 7
0 0 4
```
