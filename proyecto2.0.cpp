#include <iostream>
#include <string>
using namespace std;

// Estructura para representar un recurso
struct Recurso {
    int codigo;
    string nombre;
    bool disponible;
};

// Estructura para representar un estudiante
struct Estudiante {
    int codigo;
    string nombre;
    bool registrado;
};

// Función para agregar un recurso
void agregarRecurso(Recurso recursos[], int& numRecursos);

// Función para agregar un estudiante
void agregarEstudiante(Estudiante estudiantes[], int& numEstudiantes);

// Función para encontrar el índice de un recurso dado su código
int buscarRecurso(Recurso recursos[], int numRecursos, int codigo);

// Función para encontrar el índice de un estudiante dado su código
int buscarEstudiante(Estudiante estudiantes[], int numEstudiantes, int codigo);

// Función para prestar un recurso a un estudiante
void prestarRecurso(Recurso recursos[], int numRecursos, Estudiante estudiantes[], int numEstudiantes);

// Función para consultar los préstamos de un estudiante
void consultarPrestamosEstudiante(Recurso recursos[], int numRecursos, Estudiante estudiantes[], int numEstudiantes);

// Función para consultar la información de un préstamo
void consultarPrestamo(Recurso recursos[], int numRecursos);

// Función para devolver un recurso prestado
void devolverRecurso(Recurso recursos[], int numRecursos);

int main() {
    int opcion;
    Recurso recursos[100];
    int numRecursos = 0;
    Estudiante estudiantes[100];
    int numEstudiantes = 0;
    
    do {
        cout << "----- Central de Prestamos de la Universidad -----" << endl;
        cout << "1. Agregar recurso" << endl;
        cout << "2. Agregar estudiante" << endl;
        cout << "3. Prestar recurso disponible" << endl;
        cout << "4. Consultar prestamos de un estudiante" << endl;
        cout << "5. Consultar informacion de un prestamo" << endl;
        cout << "6. Devolver recurso prestado" << endl;
        cout << "0. Salir" << endl;
        
        cout << "Ingrese su opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
            	agregarRecurso(recursos,numRecursos);
				break;
            case 2:
                agregarEstudiante(estudiantes,numEstudiantes);
                break;
            case 3:
                prestarRecurso(recursos,numRecursos,estudiantes,numEstudiantes);
                break;
            case 4:
                consultarPrestamosEstudiante(recursos,numRecursos,estudiantes,numEstudiantes);
                break;
            case 5:
                consultarPrestamo(recursos,numRecursos);
                break;
            case 6:
                devolverRecurso(recursos,numRecursos);
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 0);
    
    return 0;
}

// Función para agregar un recurso
void agregarRecurso(Recurso recursos[], int& numRecursos) {
    Recurso recurso;
    bool codigoExiste;
    do {
        codigoExiste = false;
        cout << "Ingrese el código del recurso: ";
        cin >> recurso.codigo;
        for (int i = 0; i < numRecursos; i++) {
            if (recursos[i].codigo == recurso.codigo) {
                cout << "El código ingresado ya existe. Por favor, ingrese otro código." << endl;
                codigoExiste = true;
                break;
            }
        }
    } while (codigoExiste);
    cout << "Ingrese el nombre del recurso: ";
    cin >> recurso.nombre;
    recurso.disponible = true;
    recursos[numRecursos++] = recurso;
    cout << "Recurso agregado exitosamente." << endl;
}

// Función para agregar un estudiante
void agregarEstudiante(Estudiante estudiantes[], int& numEstudiantes) {
    Estudiante estudiante;
    bool codigoExiste;
    do {
        codigoExiste = false;
        cout << "Ingrese el código del estudiante: ";
        cin >> estudiante.codigo;
        for (int i = 0; i < numEstudiantes; i++) {
            if (estudiantes[i].codigo == estudiante.codigo) {
                cout << "El código ingresado ya existe. Por favor, ingrese otro código." << endl;
                codigoExiste = true;
                break;
            }
        }
    } while (codigoExiste);
    cout << "Ingrese el nombre del estudiante: ";
    cin >> estudiante.nombre;
    estudiante.registrado = true;
    estudiantes[numEstudiantes++] = estudiante;
    cout << "Estudiante agregado exitosamente." << endl;
}


// Función para encontrar el índice de un recurso dado su código
int buscarRecurso(Recurso recursos[], int numRecursos, int codigo) {
    for (int i = 0; i < numRecursos; i++) {
        if (recursos[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

// Función para encontrar el índice de un estudiante dado su código
int buscarEstudiante(Estudiante estudiantes[], int numEstudiantes, int codigo) {
    for (int i = 0; i < numEstudiantes; i++) {
        if (estudiantes[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

// Función para prestar un recurso a un estudiante
void prestarRecurso(Recurso recursos[], int numRecursos, Estudiante estudiantes[], int numEstudiantes) {
    int codigoRecurso, codigoEstudiante;
    cout << "Ingrese el código del recurso que desea prestar: ";
    cin >> codigoRecurso;
    int indiceRecurso = buscarRecurso(recursos, numRecursos, codigoRecurso);
    if (indiceRecurso == -1) {
        cout << "El recurso con el código ingresado no existe." << endl;
        return;
    }
    if (!recursos[indiceRecurso].disponible) {
        cout << "El recurso seleccionado ya ha sido prestado." << endl;
        return;
    }
    cout << "Ingrese el código del estudiante al que desea prestar el recurso: ";
    cin >> codigoEstudiante;
    int indiceEstudiante = buscarEstudiante(estudiantes, numEstudiantes, codigoEstudiante);
    if (indiceEstudiante == -1) {
        cout << "El estudiante con el código ingresado no existe." << endl;
        return;
    }
    if (!estudiantes[indiceEstudiante].registrado) {
        cout << "El estudiante seleccionado no está registrado." << endl;
        return;
    }
    recursos[indiceRecurso].disponible = false;

    cout << "Recurso prestado exitosamente a " << estudiantes[indiceEstudiante].nombre << "." << endl;
}

// Función para consultar los préstamos de un estudiante
void consultarPrestamosEstudiante(Recurso recursos[], int numRecursos, Estudiante estudiantes[], int numEstudiantes) {
    int codigoEstudiante;
    cout << "Ingrese el código del estudiante que desea consultar: ";
    cin >> codigoEstudiante;
    int indiceEstudiante = buscarEstudiante(estudiantes, numEstudiantes, codigoEstudiante);
    if (indiceEstudiante == -1) {
        cout << "El estudiante con el código ingresado no existe." << endl;
        return;
    }
    if (!estudiantes[indiceEstudiante].registrado) {
        cout << "El estudiante seleccionado no está registrado." << endl;
        return;
    }
    bool tienePrestamos = false;
    for (int i = 0; i < numRecursos; i++) {
        if (!recursos[i].disponible && recursos[i].codigo == codigoEstudiante) {
            if (!tienePrestamos) {
                cout << "El estudiante " << estudiantes[indiceEstudiante].nombre << " tiene los siguientes préstamos:" << endl;
                tienePrestamos = true;
            }
            cout <<"Nombre		Codigo"<<endl<<endl;
            cout << recursos[i].nombre <<"		"<<recursos[i].codigo<<endl;
        }
    }
    if (!tienePrestamos) {
        cout << "El estudiante " << estudiantes[indiceEstudiante].nombre << " no tiene préstamos." << endl;
    }
}

// Función para consultar la información de un préstamo
void consultarPrestamo(Recurso recursos[], int numRecursos) {
    int codigoRecurso;
    cout << "Ingrese el código del recurso que desea consultar: ";
    cin >> codigoRecurso;
    int indiceRecurso = buscarRecurso(recursos, numRecursos, codigoRecurso);
    if (indiceRecurso == -1) {
        cout << "El recurso con el código ingresado no existe." << endl;
        return;
    }
    cout << "Código: " << recursos[indiceRecurso].codigo << endl;
    cout << "Nombre: " << recursos[indiceRecurso].nombre << endl;
    cout << "Disponible: " << (recursos[indiceRecurso].disponible ? "Sí" : "No") << endl;
}

// Función para devolver un recurso prestado
void devolverRecurso(Recurso recursos[], int numRecursos) {
    int codigoRecurso;
    cout << "Ingrese el código del recurso que desea devolver: ";
    cin >> codigoRecurso;
    int indiceRecurso = buscarRecurso(recursos, numRecursos, codigoRecurso);
    if (indiceRecurso == -1) {
        cout << "El recurso con el código ingresado no existe." << endl;
        return;
    }
    if (recursos[indiceRecurso].disponible) {
        cout << "El recurso seleccionado no ha sido prestado." << endl;
        return;
    }
    recursos[indiceRecurso].disponible = true;
    cout << "Recurso devuelto exitosamente." << endl;
}
