# Problema B - Bombe, el Descifrador de Enigma

En septiembre de 1939, Gran Bretaña declaró la guerra a Alemania. En
ese mismo momento, el matemático Alan Turing era reclutado por el
ejército británico como criptólogo en la base militar de Bletchley
Park. ¿Su misión? Revelar el sistema de cifrado de la máquina Enigma,
utilizada por los nazis para proteger sus comunicaciones secretas.

La máquina funcionaba de forma similar a una máquina de escribir, pero
tenía un complejo mecanismo interno formado por varios rotores que, al
pulsar una letra, giraban y la sustituían por otra. Para encriptar el
mensaje, cada rotor se colocaba inicialmente en una posición
determinada. Tras cada pulsación, los rotores avanzaban, lo que
cambiaba continuamente el sistema de cifrado. Este mecanismo generaba
millones de combinaciones posibles.

Turing y su equipo trabajaban contrarreloj, conscientes de que cada
mensaje descifrado podía salvar miles de vidas, aunque la gran
cantidad de combinaciones hacían imposible cumplir con la misión. El
tiempo apremiaba, así que Turing pensó que la mejor forma de derrotar
a una máquina era con otra máquina.

A finales de 1939, lo consiguieron. Crearon Bombe, una máquina capaz
de descartar gran parte de las combinaciones imposibles y acelerar
enormemente el proceso de descifrado. Ahora, vuestra misión es
continuar su trabajo: utilizad la combinación de rotores que
proporciona Bombe y tratad de descifrar el mensaje.

Esta máquina solo funciona con letras mayúsculas del alfabeto
anglosajón, y para simplificar el problema, vuestra máquina tiene un
único rotor. Este rotor representa un desplazamiento dentro del
alfabeto. Cuando se descifra el mensaje, cada letra de la frase
cifrada se desplaza varias posiciones hacia atrás en el abecedario,
según el valor del rotor en ese momento. Después de procesar una
letra, el rotor avanza una posición. Esto se puede expresar como:
$rotor = (rotor + 1) \mod 26$, de modo que, después de la Z, el rotor
vuelve a empezar desde el principio del alfabeto.

## Entrada

La entrada del programa consiste en dos números: el primero indica la
cantidad de frases a descifrar y el segundo indica la posición inicial
del rotor, que puede ser un entero del $1$ al $26$. Después, aparecen
cada una de las frases cifradas. Cada frase puede tener una longitud
máxima de $128$ caracteres y se descifran con el mismo rotor inicial.

## Salida

La salida devuelve las frases descifradas.

## Entrada de ejemplo

```
4 10
RZXN AJDUG
FLYBG P WRFTL ZOQC BOOEXVXU
DCQF HGYJLXM OEDPDS UTDKFT AZRQZ QA IC JIAZUG
OYTBFPRLWGU CWYCHS EGVGNLYIMY PX ZSCIRBX
```

## Salida de ejemplo

```
HOLA MUNDO
VAMOS A GANAR ESTE CONCURSO
TRES TRISTES TIGRES TRAGAN TRIGO EN UN TRIGAL
ENHORABUENA HABEIS DESCIFRADO EL MENSAJE
```
