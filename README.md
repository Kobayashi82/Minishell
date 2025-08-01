<div align="center">

![System & Kernel](https://img.shields.io/badge/System-brown?style=for-the-badge)
![Shell](https://img.shields.io/badge/Shell-Bash-blue?style=for-the-badge)
![Protocol Command](https://img.shields.io/badge/Protocol-Shell-green?style=for-the-badge)
![C Language](https://img.shields.io/badge/Language-C-red?style=for-the-badge)

*Una implementación básica de un shell al estilo Bash*

</div>

# Minishell

Minishell es un proyecto de ```42 School``` que implementa las funcionalidades básicas de un shell tipo ```Bash```.  
Esta versión incluye todos los requisitos ```obligatorios``` del proyecto, los del ```bonus``` y algunas características ```adicionales```.

## ✨ Características

### 🔧 Funcionalidades Básicas
- **Línea de Comandos Interactiva**: Prompt limpio con historial de comandos
- **Ejecución de Comandos**: Resolución de PATH, ejecución con rutas absolutas/relativas
- **Gestión de Procesos**: Modelo fork/exec con manejo adecuado de señales
- **Variables de Entorno**: Soporte completo para expansión y manipulación de variables
- **Redirección I/O**: Redirección de entrada/salida con modo append
- **Pipes**: Encadenamiento de comandos con operadores de tubería
- **Heredoc**: Mecanismos avanzados de redirección de entrada
- **Verificación de Sintaxis**: Detección y reporte de errores sintácticos

### 🚀 Características Avanzadas

#### **Análisis Sintáctico Mejorado**
- **Expansión de Comandos**: `$()` para sustitución de comandos
- **Modo No-Interactivo**: Opción `-c` para ejecutar comandos directamente
- **Herestring**: `<<<` para entrada de cadena directa
- **Expansión en Heredoc**: Variables y comandos dentro de heredoc y herestring
- **Manejo de Comillas**: Procesamiento avanzado de comillas simples y dobles
- **Escape de Caracteres**: Soporte para `\` (barra invertida)
- **Tokens No Cerrados**: Muestra PS2 para continuación de línea

#### **Variables y Expansión**
- **Variables de Shell**: Variables locales además de las de entorno
- **Variables Especiales**:
  - `$$` - PID del shell
  - `$RANDOM` - Número aleatorio
  - `$TIME` - Timestamp actual
  - `$_` - Último argumento del comando anterior
  - `$?` - Último código de salida
- **Expansión de Tilde**: `~` se expande al directorio home
- **Expansión de Comodines**: `*`, `?` y `[a-z]` con patrones avanzados

#### **Operadores Lógicos y Control**
- **Operadores Lógicos**: `&&` y `||` con soporte de paréntesis para prioridades
- **Subshells**: `()` para ejecución en subprocesos
- **Ejecución Concurrente**: Manejo de múltiples procesos

### 🛠️ Comandos Built-in Mejorados

Todos los built-ins incluyen `--help` y `--version`:

- **`echo`** - Con opciones `-n` y `-e`
- **`cd`** - Con soporte para `cd -` (directorio anterior)
- **`pwd`** - Directorio actual
- **`export`** - Gestión de variables de entorno
- **`unset`** - Eliminación de variables
- **`env`** - Con `-s` para mostrar variables de shell
- **`exit`** - Salida del shell
- **`history`** - Gestión del historial de comandos
- **`help`** - Sistema de ayuda integrado
- **`banner`** - Mensaje de bienvenida

## 🔧 Instalación

```bash
git clone git@github.com:Kobayashi82/Minishell.git
cd minishell
make
```

## 🖥️ Uso

### Modo Interactivo
```bash
# Iniciar minishell
./minishell

# Ejemplo de uso básico
minishell$ echo "Hola Mundo"
Hola Mundo
```

### Modo No-Interactivo (Opción -c)
```bash
# Ejecutar comandos directamente
./minishell -c "echo 'Hola desde línea de comandos'"
./minishell -c "ls -la | grep '.c' | wc -l"
./minishell -c "export VAR=valor && echo \$VAR"

# Comandos complejos con pipes y redirección
./minishell -c "cat /etc/passwd | grep root > users.txt"
```

### Ejemplos de Uso Común
```bash
# Uso de pipes
minishell$ ls -la | grep ".c" | wc -l

# Redirección
minishell$ echo "contenido" > archivo.txt
minishell$ cat < archivo.txt

# Variables
minishell$ export VAR="valor"
minishell$ echo $VAR

# Heredoc
minishell$ cat << EOF
> línea 1
> línea 2
> EOF
```

## 📚 Ejemplos Avanzados

### Expansión de Comandos
```bash
minishell$ echo "Fecha actual: $(date)"
Fecha actual: Lun 26 May 2025 10:30:15 CEST

minishell$ files=$(ls *.c)
minishell$ echo $files
```

### Operadores Lógicos
```bash
minishell$ make && echo "Compilación exitosa" || echo "Error en compilación"

minishell$ (cd /tmp && pwd) && pwd
/tmp
/ruta/original
```

### Comodines Avanzados
```bash
minishell$ ls *.c           # Archivos .c
minishell$ ls file?.txt     # file1.txt, file2.txt, etc.
minishell$ ls [a-z]*.c      # Archivos .c que empiecen con minúscula
```

### Herestring
```bash
minishell$ cat <<< "Esta es una línea de texto"
Esta es una línea de texto

minishell$ bc <<< "2+2"
4
```

## 🧪 Características Técnicas

### **Gestión de Memoria**
- ✅ **Sin memory leaks**: Liberación completa de memoria heap
- ✅ **Sin file descriptors abiertos**: Cierre adecuado de todos los FDs
- ✅ **Gestión de señales**: Manejo robusto de SIGINT, SIGQUIT, EOF

### **Compatibilidad con Bash**
- ✅ **Manejo de errores idéntico**: Códigos de error y mensajes como Bash
- ✅ **Comportamiento de señales**: Ctrl-C, Ctrl-D, Ctrl-\ como en Bash
- ✅ **Variables especiales**: Comportamiento idéntico a Bash

### **Análisis Sintáctico Robusto**
- ✅ **Parser recursivo**: Análisis sintáctico completo
- ✅ **Manejo de errores**: Detección y reporte detallado de errores
- ✅ **Tokenización avanzada**: Soporte para tokens complejos

## 📄 Licencia

Este proyecto está licenciado bajo la WTFPL – [Do What the Fuck You Want to Public License](http://www.wtfpl.net/about/).

---

<div align="center">

**🌐 Desarrollado como parte del curriculum de 42 School 🌐**

*"In Minishell, the last feature is never really the last"*

</div>
