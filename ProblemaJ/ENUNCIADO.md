# Problema J - Premios narvalenses

La Organización de Narvales Canadienses y Estadounidenses (ONCE) ha
organizado una lotería con un premio de hasta $30$ bacalaos de cada
número premiado. Cada boleto contiene un número de hasta $30$ dígitos.

Como este año han pescado muchos bacalaos, han decidido que se
sortearían varios números ganadores (hasta $10^5$) y el premio de cada
boleto jugado se calcularía como la suma de las longitudes de los
prefijos que coinciden con los diferentes números ganadores.

Tu tarea es, dada la lista de boletos y los números ganadores,
determinar cuántos bacalaos tendrán que preparar para dar todos los
premios. Además, los narvales canadienses nos aseguran que como máximo
han repartido $10^5$ boletos.

## Entrada

La entrada consiste en un primer número $m$ ($1 \le m \le 10^5$) con
el total de boletos ganadores seguido de $m$ líneas con el valor de
estos boletos. Los boletos premiados pueden repetirse y no
necesariamente habrá alguien con el mismo valor que un boleto
premiado. Seguidamente viene el número $n$ ($1 \le n \le 10^5$) de
boletos vendidos, con $n$ líneas de los valores de esos boletos
vendidos.

Todos los boletos contienen la misma cantidad de dígitos y, estos
dígitos, siempre son valores primos entre $1$ y $9$.

La entrada acaba con un caso con $0$ boletos ganadores.

## Salida

La salida consiste en el número de pescados que se lleva cada uno. Al
final de cada caso, tiene que aparecer el total de bacalaos que
necesitaran para poder dar todos los premios y deberá estar separado
del siguiente caso de prueba por `---`.

## Entrada de ejemplo

```
4
223357
775532
223357
235757
5
223357
775532
235723
225537
227335
0
```

## Salida de ejemplo

```
13
6
6
5
5
35
---
```

## Aclaración

Si juegas con el boleto $235$, y los premiados son $232$, $235$ y $225$
obtienes $6$ bacalaos. Dos bacalaos por 23, tres por 235 y uno por 225.
