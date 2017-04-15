import task4.calculator.IPercentileCalculator;
import task4.calculator.LinearInterpolationPercentileCalculator;
import task4.calculator.NearestRankPercentileCalculator;
import task4.generator.INumberGenerator;
import task4.generator.NumberSequenceGenerator;

import java.io.File;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Collection;

/**
 * testovi pojedinih komponenti
 */
public class Main {

    public static void main(String[] args) {
        // task4tests();
        task5tests();
    }

    private static void task4tests() {
        INumberGenerator generator = new NumberSequenceGenerator(15, 5, 50);
        IPercentileCalculator pc = new NearestRankPercentileCalculator();
        System.out.println(pc.calculatePercentile(50, generator.generate()));
        pc = new LinearInterpolationPercentileCalculator();
        System.out.println(pc.calculatePercentile(40, generator.generate()));
    }

    private static void task5tests() {
        testWritingToFile(Paths.get("res", "log.txt"));
    }

    private static void testWritingToFile(Path file) {
        File f = file.toFile();
        if(!f.exists() || !f.isFile()) {
            try {
                f.createNewFile();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        Collection<String> log = new ArrayList<>();
        log.add("---");
        log.add(LocalDateTime.now().toString());
        log.add("---");
        try {
            Files.write(file, log, Charset.forName("UTF-8"), StandardOpenOption.APPEND);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
