# EstacionCliente

Proyecto personal de meteorología basado en **ESP32** y un sensor de humedad/temperatura.  
Este código corresponde al **cliente** dentro de una arquitectura cliente-servidor, encargado de recopilar datos ambientales y enviarlos a un servidor para su procesamiento.

---

## ⚙️ Tecnologías utilizadas

- Lenguaje: **C**
- Librerías:
  - `DHT.h`
  - `WiFi.h`
  - `HTTPClient.h`

---

## 🚀 Instalación

1. Instalar el **IDE de Arduino**.  
2. Conectar una placa de desarrollo compatible (se utilizó un **ESP32** por su módulo WiFi integrado).  
3. Descargar este repositorio y abrir el archivo principal en el IDE.  
4. Configurar los parámetros de red en el código (SSID y contraseña WiFi).  
5. Compilar y cargar el programa en la placa.  

---

## ▶️ Ejecución

1. Conectar la placa a una fuente de alimentación (por ejemplo, batería de **5.5V**).  
2. El dispositivo se conectará automáticamente a la red WiFi configurada.  
3. Los datos del sensor se enviarán al servidor especificado en el código.  

---

## ✨ Características principales

- Obtención de datos de **temperatura** y **humedad**.  
- Conexión directa a través de **WiFi**.  
- Identificación mediante la **dirección MAC** del dispositivo, usada también como identificador en el servidor.  

---

## 📌 Estado del proyecto

- Versión: **0.9**  
- Estado: **Estable**, aunque se presentan errores ocasionales difíciles de replicar.  

---

## 👤 Autor

**be**

---

## 📜 Nota

Este es un proyecto **personal** y no cuenta con licencia de distribución.  
No está destinado a ser utilizado, modificado o redistribuido sin el permiso expreso del autor.
