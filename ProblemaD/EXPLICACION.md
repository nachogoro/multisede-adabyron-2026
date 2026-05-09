# Introducción a la solución

Tenemos $a$ cuentas de un color y $b$ de otro y queremos contar cuántos
collares distintos podemos formar usándolas todas, considerando que
dos collares son iguales si uno es una rotación del otro. Las
reflexiones (efecto espejo) sí cuentan como collares diferentes.

Tratar las reflexiones como collares distintos no es complejidad añadida sino
una simplificación. Si las reflexiones también contaran como iguales, el
grupo de simetrías del collar pasaría de ser el cíclico $C_n$ (solo rotaciones,
$n$ elementos) al diédrico $D_n$ (rotaciones más reflexiones, $2n$ elementos),
lo que duplica el número de simetrías a considerar y obliga a cuidar más casos
en cualquier enfoque que se elija.

# Enfoque por fuerza bruta

Como $a + b \le 20$, los collares son cadenas de longitud $n \le 20$
con composición $(a, b)$ fijada. Los candidatos a explorar son las
$\binom{n}{a}$ permutaciones distintas de la cadena
`AAA...BBB`, que para $n = 20$ y $a = 10$ alcanzan el peor caso de
$184\,756$.

La idea es generarlos uno a uno y, para cada uno, decidir si es un
collar nuevo o una rotación de uno ya contado:

1. Inicializamos un conjunto `vistas`, vacío, en el que iremos
   guardando todas las rotaciones de cada collar que contemos.
2. Generamos las permutaciones con `next_permutation` partiendo de la
   cadena ordenada. Para cada candidato $s$:
   - Si $s$ está en `vistas`, es una rotación de un collar ya
     contado: lo ignoramos.
   - Si no, es un collar nuevo: incrementamos el total e insertamos
     las $n$ rotaciones de $s$ en `vistas`.
3. Al terminar, el total es la respuesta.

Para enumerar las rotaciones sin programar desplazamientos podemos valernos de
un pequeño truco: si $s$ es la cadena, $s + s$ contiene como subcadenas de
longitud $n$ exactamente las $n$ rotaciones de $s$, en las posiciones $0, 1,
\ldots, n-1$.

Como $(a, b)$ tiene a lo sumo $21 \times 21$ valores distintos, podemos
memoizar el resultado por par para que casos de prueba repetidos no rehagan
trabajo. Además, intercambiar los dos colores no cambia la cuenta ($(a, b)$
y $(b, a)$ son problemas equivalentes), así que normalizamos la clave a
$(\min(a, b), \max(a, b))$ y el caché se reduce a $120$ entradas distintas.

# Variante: el lema de Burnside

Como $\binom{n}{a}$ cuenta cadenas ignorando rotaciones, una primera
idea es dividir entre $n$ (total de cadenas entre tamaño del grupo
de rotaciones) y obtener el número de "familias". Pero falla: no
todas las familias tienen el mismo tamaño. Con $n = 6$, las seis
rotaciones de `AAABBB` son distintas (familia de tamaño $6$), pero
`ABABAB` solo tiene dos rotaciones distintas, `ABABAB` y `BABABA`
(familia de tamaño $2$). Si dividiéramos por $6$ a secas, contaríamos
la familia de `ABABAB` con peso $1/3$ en lugar de con peso $1$. El
*lema de Burnside* corrige justamente este desbalance.

## El lema, particularizado al problema

Llamemos $r^d$ a la rotación que desplaza la cadena $d$ posiciones, y
$\mathrm{Fix}(r^d)$ al conjunto de cadenas a las que la rotación
$r^d$ no afecta (las que se quedan iguales después de aplicarla). El
lema afirma:

$$ \text{(collares distintos)} = \frac{1}{n} \sum_{d=0}^{n-1}
|\mathrm{Fix}(r^d)| $$

Cada familia (sea grande o pequeña) contribuye a la suma exactamente $n$. Si
una familia tiene $m$ elementos, cada uno de ellos está fijado por $n / m$
rotaciones, y $m \cdot (n/m) = n$. Al dividir entre $n$, cada familia aporta
$1$, que es lo que queremos.

Solo queda saber, para cada $d$, cuántas cadenas fija $r^d$.

## Cuántas cadenas fija cada rotación

Para $d = 0$, $r^0$ es la rotación trivial y *toda* cadena cumple
$r^0 s = s$: $|\mathrm{Fix}(r^0)| = \binom{n}{a}$.

Para $d \ne 0$, una cadena $s$ está fijada por $r^d$ si y solo si es
periódica con período $g = \gcd(d, n)$. La razón es que $r^d$ obliga
a $s_i = s_{i + d \bmod n}$, y al iterar esta condición las
posiciones $i, i+d, i+2d, \ldots$ recorren los múltiplos de $g$
módulo $n$. Todas las posiciones de un mismo múltiplo de $g$ deben
tener el mismo carácter, así que la cadena consiste en $n/g$ copias
seguidas de un bloque de tamaño $g$.

¿Cuántos bloques cumplen la composición pedida? El bloque tiene
$a g / n$ caracteres del primer color (el resto del segundo). Si ese
número no es entero (es decir, si $n / g$ no divide a $a$), no existe
ningún bloque y $|\mathrm{Fix}(r^d)| = 0$. Si lo es, el número de
bloques posibles es $\binom{g}{a g / n}$.

## Agrupación por el $\gcd$

El número de cadenas fijas por $r^d$ solo depende de $g = \gcd(d,
n)$, así que conviene reorganizar la suma por divisores de $n$ en
lugar de por desplazamientos. Para un divisor $g$ de $n$ fijo, los
$d \in \{0, \ldots, n-1\}$ con $\gcd(d, n) = g$ son los múltiplos de
$g$ tales que $d/g$ es coprimo con $n/g$ en el rango $\{0, \ldots,
n/g - 1\}$: hay exactamente $\varphi(n/g)$ valores de $d$ que cumplen
eso.

## La fórmula final

Combinando los dos pasos anteriores:

$$ \text{(collares distintos)} = \frac{1}{n} \sum_{\substack{g \mid n
\\ (n/g) \mid a}} \varphi(n/g) \cdot \binom{g}{a g / n} $$

Sustituyendo $k = n / g$ queda algo más cómodo de implementar:

$$ \text{(collares distintos)} = \frac{1}{n} \sum_{\substack{k \mid n
\\ k \mid a}} \varphi(k) \cdot \binom{n/k}{a/k} $$

La suma recorre los divisores comunes de $n$ y $a$, que para $n \le
20$ son a lo sumo seis. Cada caso son unas pocas operaciones.

# Soluciones

| Solución | Descripción | Verificado con el juez |
| :------: | :---------- | :--------------------: |
| [D.cpp](src/D.cpp)                   | Fuerza bruta | :x: |
| [D_burnside.cpp](src/D_burnside.cpp) | Fórmula de Burnside. | :x: |
