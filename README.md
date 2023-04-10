IDE C++ = DEV C++ 5.11

**`Enunciado del problema.`**
La Registraduría Nacional del Estado Civil, requiere de un software más robusto para el proceso de elecciones regionales. Por lo tanto ha pensado en usted y su grupo de trabajo para realizar este proyecto.
Se espera que su desarrollo en general pueda: generar aleatoriamente los tarjetones para cada ciudad, alcaldía y concejo, incluyendo voto en blanco.
Debe realizar una simulación del proceso electoral, de forma tal que la entidad quede convencida de la calidad de su desarrollo y los beneficios que logrará con este software.
Se obtendrán los resultados de los escrutinios y resultados estadísticos de interés.

ESTRUCTURA DE DATOS

**`En memoria secundaria:`**

La información deberá estar almacenada, de manera permanente, en archivos planos los cuales deben ser actualizados al final de la ejecución, dado que, por ejemplo, durante el proceso puede ser excluido o incluido un candidato. Debe tenerse la posibilidad de modificar la información ya sea agregando, eliminando o cambiando registros.

Existen por lo menos los archivos planos de ciudades, candidatos, y partidos, de la siguiente forma:

CIUDADES:
Nombre, departamento, tamaño del concejo (el cual se definirá proporcionalmente acorde con lo establecido por la registraduría, para cada ciudad), Censo electoral (cantidad de personas habilitadas para votar. Este dato será generado al azar para hacer la simulación).

PARTIDOS:
Nombre del partido, nombre del representante legal. 

CANDIDATOS:
•	Nombre
•	Apellido
•	Número de identificación
•	Sexo: F o M
•	Estado civil (Casado, Soltero, Unión libre, Divorciado)
•	Fecha de Nacimiento
•	Ciudad de Nacimiento
•	Ciudad de Residencia (los candidatos sólo podrán postularse para la ciudad en que habitan)
•	Partido.


**`En memoria Principal:`**

Con el fin de optimizar las búsquedas deberán utilizarse listas, multilistas, arreglos, pilas, colas o árboles en memoria principal. Para la realización de dichas búsquedas, deberá evitarse la utilización total de la información. Es decir se espera que apliquen los criterios y conocimientos correspondientes a la eficiencia de los algoritmos. Complejidad en tiempo y memoria. 

Por ejemplo, se deben generar las siguientes listas:

1.	Ciudades para las cuales se realizará el proceso electoral.
2.	Partidos legalmente reconocidos.
3.	Todos los candidatos al concejo de una ciudad.
4.	Todos los candidatos a la alcaldía de una ciudad.
5.	Candidatos a cada una de las alcaldías, por partido. 
6.	Candidatos a cada uno de  los concejos, por partido. 
7.	Por cada partido, la lista de candidatos a los consejos. 
8.	Por cada partido, la lista de candidatos a las alcaldías. .

**`REQUERIMIENTOS FUNCIONALES:`**

Consultas: 

•	Dado un partido y una ciudad, mostrar la lista de sus candidatos al Concejo y el candidato a la alcaldía (nombre, edad, sexo).<br>
•	Dado un partido mostrar la lista de candidatos a alcaldías de cada una de las diferentes ciudades (ciudad, nombre del candidato, sexo, edad).<br>
•	Dado un partido mostrar las listas de candidatos a cada uno de los diferentes concejos. (ciudad: Nombre del candidato, edad, ciudad, de nacimiento, estado civil).<br>
•	Dada una ciudad, mostrar por cada partido, el candidato a la alcaldía y los candidatos al concejo.<br>
•	Dada una ciudad, mostrar el tarjetón de candidatos a la alcaldía. Incluye voto en blanco. (0.voto en blanco, 1. Candidato uno, 2. Candidato dos,…..)<br>
•	Dada una ciudad, mostrar el tarjetón de candidatos al concejo, incluye voto en blanco. Suponga que todas las listas aplican voto preferente. (0.voto en blanco, 1. Partido 1, 1.1. Candidato 1 del partido 1, etc. 2. Partido 2, 2.1 candidato 1 del partido 2, 2.2. candidato 2 del partido 2 , 3. Partido 3 …).<br>
•	Censo electoral. Por cada ciudad, mostrar la cantidad de personas habilitadas para votar.<br>
•	El programa debe estar en capacidad de calcular la edad de cada una de las personas, no es un atributo.<br>
Simulación de elecciones.

•	Creará las estructuras en memoria principal a partir de los archivos planos.<br>
•	Permitirá modificar los datos en memoria principal. Retirar un registro, agregar uno nuevo, modificar uno existente.<br>
•	Simulará el proceso electoral, generando aleatoriamente la cantidad de votos que obtiene cada candidato, incluyendo voto en blanco, votos nulos y  abstención. La suma total no puede superar el censo electoral.<br>
•	Para cada ciudad mostrará los resultados:<br>
Para alcaldía: votos por cada candidato, porcentaje. Votos en blanco, porcentaje. Votos nulos, porcentaje. GANADOR.<br>
Para concejo: un reporte: Nombre del candidato, partido, número de votos, porcentaje. Voto en blanco: cantidad y porcentaje, al igual para votos nulos.<br>
•	Estadísticas:<br>
	Reporte por ciudad: Total votos, total votos en blanco, total votos nulos, total abstención. En cantidad y porcentaje.<br>
	Por consejo: Totales por partido, totales hombres y totales mujeres. En número y porcentaje.<br>
	Totales nacional: Totales por partido, totales hombres y totales mujeres. En número y porcentaje.<br>
•	Finalizada la simulación actualizará los archivos planos con los cambios realizados en memoria principal. Lo cual permitirá nuevos procesos de simulación. Tenga en cuenta que una vez iniciada la simulación de las votaciones, no podrá eliminarse ni agregarse ningún candidato.<br>

Contará con los menús y submenús que faciliten la realización de cada una de las consultas y la simulación.

Debe aplicar programación orientada a objetos y el principio de alta cohesión y bajo acoplamiento.

Debe aplicar los conceptos de optimización estudiados en el curso. No limitarse a garantizar el funcionamiento del programa. 
