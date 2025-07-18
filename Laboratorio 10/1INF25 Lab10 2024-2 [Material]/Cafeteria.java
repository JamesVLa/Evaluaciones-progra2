import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Cafeteria {
    private final List<Pais> paises;
    private final Scanner archivo;
    //TODO: agregar miembros faltantes
    
    public Cafeteria() {
        paises = new ArrayList<>();
        archivo = new Scanner(System.in);
        //TODO: inicializar miembros faltantes
    }
    
    public Cafeteria(final String nombreArchivo) throws FileNotFoundException {
        archivo = new Scanner(new File(nombreArchivo));
        paises = new ArrayList<>();
        //TODO: inicializar miembros faltantes
    }
    
    public void cargarPaises() {
        while (archivo.hasNext()) {
            char tipo = archivo.next().charAt(0);
            if (!(tipo == 'I' || tipo == 'N')) break;
            
            Pais pais = new Pais();
            pais.cargar(archivo);
            paises.add(pais);
        }
    }
    
    public void cargarParticipantes() {
        //TODO: cargar participantes
    }
    
    public void cargarMenu() {
        //TODO: cargar menu
    }
    
    public void imprimirPaises() {
        System.out.println("==================LISTADO DE PAISES===================");
        System.out.println("------------------------------------------------------");
        System.out.println(String.format("%-15s\t%-10s\t%-10s\t%-10s", "NOMBRE", "MONEDA", "TIPO-CAMBIO", "IDIOMA"));
        System.out.println("------------------------------------------------------");
        for (Pais pais : paises) {
            pais.imprimir();
        }
        System.out.println("======================================================");
        System.out.println();
    }
    
    public void imprimirParticipantes() {
        //TODO: cargar participantes
    }
    
    public void imprimirMenuPredeterminado() {
        //TODO: imprimir menu predeterminado
    }
    
    public void imprimirMenusPersonalizados() {
        //TODO: imprimir menús personalizados
    }
    
    private Pais buscarPais(String nombre) {
        for (Pais pais : paises) {
            if (pais.getNombre().equals(nombre)) {
                return pais;
            }
        }
        
        return paises.get(0);
    }
}