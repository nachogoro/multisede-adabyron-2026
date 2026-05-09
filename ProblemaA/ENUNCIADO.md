# Problema A - Archivadores S.A.

En el primer día de trabajo del becario Gumersindo en la empresa
Archivadores S.A., recibe un WhatsApp del jefe. Urgentemente, debe
bajar al archivo y ordenar los archivadores de los clientes. Si no lo
hace, ese será su primer y último día.

Al bajar, ve un montón de archivadores. Cada uno tiene un número de
cliente y una pegatina indicando la prioridad del cliente en la
empresa ($1$ = más urgente, $5$ = menos urgente). Sin embargo, los
nervios y la preocupación por entregar el trabajo antes de que llegue
el jefe provocan que algunos archivadores se rompan al abrirlos.
Preocupado, Gumersindo decide cambiar su prioridad a $6$ para moverlos
al final.

Gumersindo debe ordenar los archivadores siguiendo estas reglas.
Primero debe colocar los archivadores que no están rotos, ordenados
por prioridad (de más urgente a menos). Si dos archivadores tienen la
misma prioridad, se ordenan por número de cliente (de menor a mayor).
Los archivadores rotos deben colocarse al final, ordenados siguiendo
la misma lógica.

## Entrada

La entrada comienza con un entero $t$ que indica el número de casos de
prueba. Cada caso de prueba se describe en una línea que comienza con
un entero $n$ ($1 \le n \le 10^4$), que indica el número de
archivadores. A continuación aparecen $n$ pares de números. Cada par
representa un archivador mediante: el número de cliente $w$ ($1 \le w
\le 10^5$) y su prioridad $p$ (entero entre $1$ y $6$), separados por
espacios. Las prioridades del $1$ al $5$ indican archivadores en buen
estado (siendo $1$ la más urgente), mientras que la prioridad $6$
indica que el archivador está roto.

## Salida

Para cada caso de prueba, se debe imprimir primero la lista de
archivadores en buen estado, ordenados según prioridad y número de
cliente, y después los archivadores rotos, indicando que están rotos.

## Entrada de ejemplo

```
4
7 120 3 150 1 200 2 300 6 500 6 180 1 250 3
4 10 1 20 6 30 1 40 6
5 5 3 2 1 8 6 1 2 7 6
11 90 2 45 1 300 6 210 3 500 6 10 1 75 2 600 6 33 3 120 1 450 2
```

## Salida de ejemplo

```
150 1 180 1 200 2 120 3 250 3 300 ROTO 500 ROTO
10 1 30 1 20 ROTO 40 ROTO
2 1 1 2 5 3 7 ROTO 8 ROTO
10 1 45 1 120 1 75 2 90 2 450 2 33 3 210 3 300 ROTO 500 ROTO 600 ROTO
```
