
Análisis del problema
====

####**Introducción**

El objetivo de este proyecto es crear un juego llamado “La Plataforma”, el cual consiste en que el usuario utiliza un personaje controlado con el teclado, que se mueve en una pantalla fija, sobre una plataforma y debe intentar esquivar los obstáculos que se le presentarán durante el juego, estos pueden llegar desde arriba, abajo, izquierda y derecha y conforme avance el juego llegaran mas y con mayor velocidad. Nuestra meta es crear este juego usando qt, primero con figuras geométricas y luego con gráficos y agregarle algunos cambios e ideas propias al juego, con esto, nuestra aplicación no sería idéntica al juego y agregaremos nuestras propias ideas. Nuestro juego utilizará gravedad a la hora de realizar saltos, esto se ampliará más adelante, además el jugador podrá agacharse.


####**Ejemplos del juego:**

[![tp1.png](https://s17.postimg.org/5h38llr3z/tp1.png)](https://postimg.org/image/q182k36uz/)

[![tp2.png](https://s16.postimg.org/5raua18d1/tp2.png)](https://postimg.org/image/r0ygkvonl/)

En el ejemplo podemos ver los obstáculos verticales y horizontales con velocidad constante que se presentan y que el usuario debe tratar de esquivar moviéndose, ya sea hacia los lados, saltando o agachándose. Además note que en el juego hay un puntaje acumulado, según el número de  objetos que se hayan esquivado, también se pueden ver monedas que cumplen una función en el juego pero que no incluiremos en nuestro programa y por último una barra azul que permite detener el tiempo por unos segundos, sin embargo usaremos otro tipo de “poderes” para el jugador como un agregado para el juego.

####**Controles del juego y gravedad**

El jugador utilizara las cuatro flechas direccionales a la hora de jugar, las flechas izquierda y derecha, se encargan de mover el personaje hacia ambos lados de la plataforma, lo que le permite desplazarse por esta y poder esquivar los objetos que caen del cielo. La flecha de abajo le permite al personaje agacharse, lo que lo hace más bajo y puede esquivar los misiles que se aproximan horizontalmente, y por último la flecha de arriba le permite al jugador saltar, con esto el jugador podrá saltar objetos como sierras que salgan de la plataforma o incluso saltar los misiles de los lados. El salto tendrá un aspecto particular y es el hecho del uso de las fórmula de la aceleración de la gravedad, esto quiere decir que la aceleración con la que baje el personaje después de saltar, está relacionada con la masa y la distancia desde la que caiga.


####**Objetos y enemigos**


Aunque ya se han mencionado los tipos de objetos que atacan al personaje durante el juego, se deben explicar a profundidad para entenderlos mejor:

 - Cubos: Estos corresponden a figuras cuadradas que caen del cielo
   verticalmente y desaparecen al alcanzar la plataforma o al personaje,
   si golpea la cabeza del personaje, el objeto desaparece, y el
   personaje “muere”.
   
 - Misiles: Estos objetos corresponden a rectángulos alargados pero
   delgados que cruzan la pantalla del juego horizontalmente, pueden
   pasar de izquierda a derecha o de derecha a izquierda, esto se
   escogerá aleatoriamente y su velocidad de aparición varía según
   avance el juego. El personaje puede agacharse o saltar para
   esquivarlos, pero si es impactado pierde.
   
   
 - Sierras: Estos objetos salen de la plataforma y se mueven
   horizontalmente, pueden moverse hacia ambos lados y la única forma de
   esquivarlos es saltandolos. Si impacta al jugador pierde.
   
   
 - Poderes: Este objeto no es un enemigo, sino más bien un aliado, caen
   del cielo y ayudan al jugador dándole beneficios que se explicarán
   posteriormente.

####**Reglas del juego**

El jugador pierde si:

 - Se cae de la plataforma en la que se inicia. 
 - Los “cubos” caídos desde el cielo tocan al jugador. 
 - Los “misiles ”disparados horizontalmente tocan al jugador. 
 - La “sierra” que sale desde abajo toca al jugador.

   Hay excepciones con los objetos, ya que el jugador puede adquirir un
   poderes que no le afecten el impacto de los objetos.

Los poderes durarán 15 segundos y saldrán aleatoriamente.

Si el jugador tiene un poder activo y toca otro objeto de poder, el jugador se quedará con el último poder y se reiniciará los segundos restantes (15 de nuevo).

La partida nunca terminará: lo que pasará -para aumentar la dificultad- es que los objetos “enemigos” saldrán más rápidamente y en mayor cantidad.  Esto cada 20 segundos.

No habrá vidas: la partida reiniciará cada vez que el jugador pierde, eventualmente el puntaje se reiniciará.  Cabe rescatar que se tendrá un registro de las mayores puntuaciones.

####**Puntaje**

Los criterios para aumentar el puntaje son los siguientes:

 - Por cada cubo caído del cielo: 1 punto. 
 - Por cada misil disparado: 2 puntos. 
 - Por cada sierra accionada: 5 puntos.

Cabe rescatar que no se sumará los puntos anteriormente dichos si los objetos tocan al jugador.  También que se sumará los puntos respectivos cuando los objetos desaparecen (cuando los cubos impactan en el suelo, los misiles desaparecen de la pantalla y la sierra recorre toda la plataforma y desaparece).


**Opcional:** se tiene la propuesta de hacer un segundo tipo de puntaje, por tiempo:
Esto quiere decir que se tomará como puntaje los segundos que duró el jugador.  Así, por ejemplo, si el jugador duró 76 segundos vivos, 76 será el puntaje obtenido.

####**Poderes**

Como se dijo anteriormente, todos los poderes durarán 15 segundos sin excepción.  Se representarán como un objeto rojo y caerá desde el cielo lentamente.

 - Ningún objeto “enemigo” te hará daño. 
 - Poder volar. 
 - Te puede impactar un objeto una vez (después de que un objeto impacte al jugador se anulará el poder). 
 - Duplicar el puntaje.

Dichos poderes saldrán aleatoriamente.