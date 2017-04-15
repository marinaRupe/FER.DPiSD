package task4;

import task4.calculator.LinearInterpolationPercentileCalculator;
import task4.calculator.NearestRankPercentileCalculator;
import task4.generator.FibonacciNumberGenerator;
import task4.generator.INumberGenerator;
import task4.generator.NormalDistributionNumberGenerator;
import task4.generator.NumberSequenceGenerator;

import java.util.Arrays;
import java.util.List;


public class Task4Main {

    public static void main(String[] args) {
        List<INumberGenerator> generators = Arrays.asList(
                new NumberSequenceGenerator(15, 50, 5),
                new NormalDistributionNumberGenerator(50, 10, 5),
                new FibonacciNumberGenerator(5)
        );
        DistributionTester tester = new DistributionTester(null, new NearestRankPercentileCalculator());
        testCalculator(tester, generators);

        System.out.println();

        tester.setPercentileCalculator(new LinearInterpolationPercentileCalculator());
        testCalculator(tester, generators);
    }

    public static void testCalculator(DistributionTester tester, List<INumberGenerator> generators) {
        for (INumberGenerator generator : generators) {
            tester.setGenerator(generator);
            tester.printDistributionPercentileValues();
        }
    }
}
