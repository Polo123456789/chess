====
TODO
====

- [ ] <++>

uci-interface
-------------

- [ ] Create spec
- [ ] Detail continuation

Diseño
======

Overview
--------

El tablero se representara con una mezcla de un ``mailbox`` y una
``Piece-List``.

Se generaran las jugadas legales, y se usa un algoritmo minimax para determinar
cual de las jugadas se tienen que hacer.

Layout del proyecto
-------------------

Cada proyecto tiene en su documentacion:

* introduction.rst: Con una guia rapida
* spec.rst: Describiendo la interfaz
* Y explicaciones de las cosas que lo necesiten.

engine
  Representacion del tablero, busqueda de jugadas, y evaluacion

uci-interface
  UCI loop

tui
  Un programa de terminal que siga el protocolo uci para jugar ajedrez.

engine-lib
~~~~~~~~~~

.. TODO(pabsan): Revisar luego de implementar el uci-interface

Tiene que representar al tablero de ajedrez y todas sus reglas. Tiene que poder
generar todas las jugadas legales y evaluar las posiciones que salgan de ella.

Gracias a que tiene que poder hacer interfaz con el protocolo uci, tiene que
poder:

* Recibir una posicion, crear el arbol de jugadas y evaluarlo.
* Enviar constantemente informacion de los calculos que se estan haciendo.
  (Usando uci-interface).
* Poder realizar los calculos con ciertas restricciones (De tiempo, o liminando
  la profundidad) (Tomandolas de uci-interface).
* Poder, en cualquier momento, detener los calculos.
* Luego de detenerse los calculos, cambiar la posicion de la partida.

tui
~~~


