package task5;

import task5.actions.*;
import task5.source.DatotecniIzvor;
import task5.source.TipkovnicniIzvor;
import java.io.File;
import java.nio.file.Paths;

public class Task5Main {

    public static void main(String[] args) {
        System.out.println("Postavljam izvor na datotečni izvor: ");
        File file = Paths.get("res", "brojevi.txt").toFile();
        SlijedBrojeva slijedBrojeva = new SlijedBrojeva(new DatotecniIzvor(file));

        Akcija prosjek = new Prosjek(slijedBrojeva);
        Akcija medijan = new Medijan(slijedBrojeva);
        Akcija suma = new Suma(slijedBrojeva);
        Akcija zapisUDatoteku = new ZapisUDatoteku(slijedBrojeva);
        slijedBrojeva.kreni();

        medijan.setSource(null);
        System.out.println("Postavljam izvor na tikovnicu: ");
        slijedBrojeva.setSource(new TipkovnicniIzvor());
        slijedBrojeva.kreni();
    }
}
