//este calculador pide la cantidad de estudiantes y luego pide las calificaciones y segun el nivel cae en 2 brackets
//aprobados y reprobados, utiliza operaciones matematicas simples para descubrir cosas como promedios, sumas, promedios individuales

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    int cantidadEstudiantes, aprobados, reprobados;
    int i, j;
    double nota, sumaNotas, promedio;
    double sumaPromedios, promedioGeneral, mejorPromedio;
    string nombre, mejorEstudiante;
    char repetir;

    do
    {
        aprobados = 0;
        reprobados = 0;
        sumaPromedios = 0;
        mejorPromedio = -1;

        cout << "Cantidad de estudiantes: ";
        cin >> cantidadEstudiantes;

        while (cantidadEstudiantes <= 0)
        {
            cout << "Ingrese una cantidad valida: ";
            cin >> cantidadEstudiantes;
        }

        for (i = 1; i <= cantidadEstudiantes; i++)
        {
            cout << "\nEstudiante " << i << endl;
            cout << "Nombre: ";
            cin >> nombre;

            sumaNotas = 0;

            for (j = 1; j <= 4; j++)
            {
                cout << "Calificacion " << j << ": ";
                cin >> nota;

                while (nota < 0 || nota > 100)
                {
                    cout << "Nota invalida, intente de nuevo: ";
                    cin >> nota;
                }

                sumaNotas = sumaNotas + nota;
            }

            promedio = sumaNotas / 4;

            cout << fixed << setprecision(2);
            cout << "Promedio: " << promedio;

            if (promedio >= 70)
            {
                cout << " - Aprobado" << endl;
                aprobados++;
            }
            else
            {
                cout << " - Reprobado" << endl;
                reprobados++;
            }

            sumaPromedios = sumaPromedios + promedio;

            if (promedio > mejorPromedio)
            {
                mejorPromedio = promedio;
                mejorEstudiante = nombre;
            }
        }

        promedioGeneral = sumaPromedios / cantidadEstudiantes;

        cout << "\n===== RESUMEN =====" << endl;
        cout << "Aprobados: " << aprobados << endl;
        cout << "Reprobados: " << reprobados << endl;
        cout << "Promedio general: " << promedioGeneral << endl;
        cout << "Mejor estudiante: " << mejorEstudiante << endl;
        cout << "Mejor promedio: " << mejorPromedio << endl;

        cout << "\nDesea registrar otro grupo? (s/n): ";
        cin >> repetir;

    } while (repetir == 's' || repetir == 'S');

    cout << "\nPrograma finalizado." << endl;

    return 0;
}


