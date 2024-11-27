# Nestor_bot
## Descripción:
Un robot controlado con esp32, que recibe señales bluetooth de un control de Playstation3 (Ps3), movilizado con motores dc que estan direccionados por un puente h, con 2 brazos hechos con servomotores que a traves de una garra improvisada puede sujetar objetos livianos y con un esp32 cam puede transmitir video a traves de wifi para poder ver lo a lo mismo que el robot ve.
##contenido del repositorio:
- /code: en esta carpeta  se puede encontrar el codigo para el funcionamiento del robot, en el cual se encuentra la deteccion del control Ps3 y la logica para el envio correcto de señales. El codigo fue diseñado y utilizado en arduino ide con lenguaje c.
- /hardware: en esta carpeta se podra encontrar el esquema y diseño de la pcb del robot hecho en la herraienta de diseño Kicad, en la version 8.0.
---
## Notas:
- El codigo para el funcionamiento del esp32 cam se puede conseguir facilmente en los ejemplos de esp32 en el arduino ide. Tambien se podria crear un codigo propio del funcionamiento para customizar el proyecto.
- Para poder tener mayor flexibilidad en el movimiento de la camara en la posicion mas conveninete simplemente conectamos de manera directa la placa principal con el esp32 cam con cables para alimentarlo.
- Para el ensamblaje y la presentacion final en este caso solo utilizamos carton prenzado con tornillos y poco mas, por esa razon no hay un diseño 3d del proyecto.
---
Este proyecto fue realizado como trabajo de aprendisaje escolar en la Tecnina N5 de Temperley, tambien conocida como "2 de abril" en Buenos Aires Argentina.
