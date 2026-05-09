# Introducción a la solución

Tenemos un cifrado tipo César con un *rotor* que avanza una posición
cada vez que se procesa una letra. Para descifrar un texto basta con
simular el proceso: mantenemos el valor del rotor y, para cada letra,
restamos su valor (módulo $26$) y avanzamos el rotor en uno. Los
caracteres que no son letras se imprimen tal cual y no avanzan el
rotor. Cada frase se descifra desde cero, partiendo del rotor inicial
que da la entrada.

# La idea

Para cada letra mayúscula $c$ con valor $v(c) \in \{0, ..., 25\}$
(siendo `A` $\to 0$, `B` $\to 1$, etc.) y rotor actual $r$, la letra
descifrada es

$$ d = (v(c) - r) \mod 26 $$

y a continuación el rotor pasa a $(r + 1) \mod 26$.

# Resto y módulo no son lo mismo

Aunque en el lenguaje coloquial los términos "resto" y "módulo" se
usan como sinónimos, matemáticamente son dos operadores diferentes que
solo coinciden cuando el dividendo es no negativo. Cuando hay signos
en juego, divergen.

Dados $a$ (dividendo) y $n > 0$ (divisor), las dos operaciones se
definen para que cumplan:

$$ a = q \cdot n + r, \quad 0 \le |r| < n $$

es decir, son congruentes módulo $n$. La diferencia está en el signo
de $r$:

- *Resto* (`rem(a, n)`): el resultado tiene el mismo signo que
  $a$. Es lo que da el redondeo hacia cero al calcular $q$.
- *Módulo* (`mod(a, n)`): el resultado tiene el mismo signo que $n$;
  como en este problema $n > 0$, el resultado es siempre no negativo.
  Es lo que da el redondeo hacia $-\infty$ al calcular $q$.

Ejemplo con $a = -3$ y $n = 26$:

- `rem(-3, 26) = -3` (mismo signo que $-3$)
- `mod(-3, 26) = 23` (mismo signo que $26$)

Para usar el resultado como índice en el alfabeto necesitamos que sea
no negativo, así que lo que queremos es módulo, no resto.

Los lenguajes no se ponen de acuerdo en qué operador asocian al
símbolo `%`:

- **C++** (y C): `%` es *remainder*. `(-3) % 26 == -3`. No hay un
  operador de módulo en la biblioteca estándar; hay que escribirlo a
  mano.
- **Python**: `%` es *módulo*. `(-3) % 26 == 23` directamente. El equivalente a
  *remainder* sobre enteros se obtiene a través de `math.fmod`, que opera sobre
  `float`.
- **Java**: como en C++, `%` es *remainder* y `(-3) % 26 == -3`. Existe la
  operación de módulo: `Math.floorMod(-3, 26) == 23`.

# Cómo simular módulo con resto

Si solo se dispone de *remainder* (caso de C++), el módulo se obtiene
con un solo retoque: tras hacer el *remainder*, el resultado está en
$(-n, n)$, así que sumándole $n$ y volviendo a aplicar el *remainder*
queda en $[0, n)$:

$$ \mathrm{mod}(a, n) = ((a \bmod_{rem} n) + n) \bmod_{rem} n $$

```cpp
int mod(int a, int n) {
    return ((a % n) + n) % n;
}
```

# El coste

El trabajo es proporcional al número de caracteres total leídos, que
es $O(\text{frases} \cdot 128)$ en el peor caso.

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [B.cpp](src/B.cpp) | :x: |
