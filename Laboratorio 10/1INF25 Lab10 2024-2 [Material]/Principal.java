import java.io.FileNotFoundException;

public class Principal {
    public static void main(String[] args) throws FileNotFoundException {
        Cafeteria cafeteria = new Cafeteria("datos.txt");
        cafeteria.cargarPaises();
        cafeteria.imprimirPaises();
        
        cafeteria.cargarParticipantes();
        cafeteria.imprimirParticipantes();
        
        cafeteria.cargarMenu();
        cafeteria.imprimirMenuPredeterminado();
        cafeteria.imprimirMenusPersonalizados();
    }
}