# Problema F - Sa festa des Gambirots

La *colla castellera* universitaria "Gambirots de la UIB" está
preparando una importante actuación para celebrar su segundo
aniversario, y, para la ocasión, el *casteller* Pinyol ha decidido
grabar una versión orquestal de su himno. Por suerte, hay bastantes
integrantes que están especializados en el mundo de la música y que
saben tocar un instrumento o incluso varios, por lo que no será
necesario contratar a ningún músico. Sin embargo, el compositor
encargado de la orquestación se emocionó poniendo muchas partes a los
instrumentos, y como no hay muchos músicos, probablemente no podrán
tocar toda la pieza de una sola vez, de modo que tendrán que grabarla
en varias tomas por separado, para luego juntarlas.

Así, por ejemplo, si tenemos una violinista, una violista y un
chelista en la *colla*, y queremos grabar una versión del himno para
cuarteto de cuerda (con dos violines, una viola y un violonchelo),
entonces tendremos que hacer dos grabaciones: la primera, con los tres
músicos a la vez; y la segunda, para la parte de violín que queda por
grabar.

Si, por otra parte, suponemos que la violinista y el chelista saben
además tocar la gralla[^1], y queremos tocar para un sexteto con dos
violines, viola, violonchelo y dos grallas, entonces tendremos que
realizar tres tomas para grabar toda la pieza:

|         | Intérprete 1 | Intérprete 2 | Intérprete 3 |
| :-----: | :----------: | :----------: | :----------: |
| Toma 1  | Violín       | Viola        | Violonchelo  |
| Toma 2  | Violín       | --           | Gralla       |
| Toma 3  | Gralla       | --           | --           |

Los estudios de grabación suelen costar bastante dinero y la *colla*
no dispone de demasiado presupuesto para ello. Por eso, Blat, el nuevo
jefe de tesorería, te ha pedido cuál es el número mínimo de tomas que
tendrán que hacer para grabar toda la obra.

[^1]: Instrumento de viento madera tradicional catalán, ampliamente
    utilizado en el mundo *casteller*.

## Entrada

La entrada estará formada por distintos casos de prueba.

Cada caso de prueba empieza con una línea con dos números que indican
el número $T$ de tipos de instrumentos distintos que aparecen en la
partitura (hasta $70$), y el número $M$ de músicos que hay en la colla
(entre $1$ y $70$). A continuación, aparecerá una línea con $T$
números, indicando el número de partes que deberán grabarse para cada
instrumento (entre $1$ y $10^9$).

Cada una de las siguientes $M$ líneas empieza con el número $n_i$ de
instrumentos distintos que sabe tocar el $i$-ésimo músico, seguido de
$n_i$ números con los identificadores de tales instrumentos (entre $1$
y $T$). Hay que tener en cuenta que, en una misma grabación, cada
músico puede tocar una parte de uno de sus instrumentos o no tocar,
pero no puede tocar a la vez dos partes distintas de un mismo
instrumento o de instrumentos distintos.

La entrada termina con una línea con dos ceros que no debe procesarse.

## Salida

Por cada caso de prueba se escribirá una línea con el número mínimo
posible de grabaciones necesarias para poder grabar todas las partes
del himno de la *colla*. Si es imposible grabar la partitura con los
músicos que hay en la colla, se escribirá en su lugar `IMPOSIBLE` en
una línea.

## Entrada de ejemplo

```
3 3
2 1 1
1 1
1 2
1 3
4 3
2 1 1 2
2 1 4
1 2
2 3 4
3 1
2 1 1
1 1
0 0
```

## Salida de ejemplo

```
2
3
IMPOSIBLE
```
