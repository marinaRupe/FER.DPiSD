package task4;

import task4.calculator.IPercentileCalculator;
import task4.generator.INumberGenerator;

import java.util.List;

public class DistributionTester {
    private INumberGenerator generator;
    private IPercentileCalculator percentileCalculator;

    public DistributionTester(INumberGenerator generator, IPercentileCalculator percentileCalculator) {
        this.generator = generator;
        this.percentileCalculator = percentileCalculator;
    }

    public INumberGenerator getGenerator() {
        return generator;
    }

    public void setGenerator(INumberGenerator generator) {
        this.generator = generator;
    }

    public IPercentileCalculator getPercentileCalculator() {
        return percentileCalculator;
    }

    public void setPercentileCalculator(IPercentileCalculator percentileCalculator) {
        this.percentileCalculator = percentileCalculator;
    }

    public void printDistributionPercentileValues() {
        List<Integer> list = generator.generate();

        System.out.println(generator.getClass() + " and " + percentileCalculator.getClass() + " :");
        System.out.println("  numbers: " + list);

        System.out.print("  percentiles: ");
        for (int i = 0; i <= 100; i += 10) {
            System.out.print(i + "th: " + percentileCalculator.calculatePercentile(i, list) + ", ");
        }
        System.out.println();
    }
}
