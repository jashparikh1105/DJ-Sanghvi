import random

# Parameters
POPULATION_SIZE = 8
GENOME_LENGTH = 8  # Number of bits per gene
MUTATION_RATE = 0.1
GENERATIONS = 2

# Function to convert binary to decimal
def binary_to_decimal(binary):
    return int(binary, 2)

# Fitness function: here it is simply the square of the decimal value
def fitness_function(genome):
    decimal_value = binary_to_decimal(genome)
    return decimal_value * decimal_value

# Generate initial population
def generate_population(size):
    return [''.join(random.choice('01') for _ in range(GENOME_LENGTH)) for _ in range(size)]

# Selection: Roulette wheel selection based on fitness
def calculate_probabilities(population):
    fitness_values = [fitness_function(genome) for genome in population]
    total_fitness = sum(fitness_values)
    probabilities = [fit / total_fitness for fit in fitness_values]
    return fitness_values, probabilities

def calculate_expected_counts(probabilities):
    avg_prob = sum(probabilities) / len(probabilities)
    expected_counts = [round(prob / avg_prob) for prob in probabilities]
    return expected_counts

# Crossover: Single-point crossover
def single_point_crossover(parent1, parent2):
    crosspoint = random.randint(1, GENOME_LENGTH - 1)
    print(f"Crosspoint for pair: {crosspoint}")
    child1 = parent1[:crosspoint] + parent2[crosspoint:]
    child2 = parent2[:crosspoint] + parent1[crosspoint:]
    return child1, child2

# Mutation: Flip a bit with a probability
def mutate(genome):
    return ''.join(bit if random.random() > MUTATION_RATE else '1' if bit == '0' else '0' for bit in genome)

# Main genetic algorithm
def genetic_algorithm():
    population = generate_population(POPULATION_SIZE)
    print(f"Initial Population: {population}\n")

    for generation in range(GENERATIONS):
        print(f"Generation {generation + 1}")

        # Calculate fitness and probabilities
        fitness_values, probabilities = calculate_probabilities(population)
        expected_counts = calculate_expected_counts(probabilities)

        print("\nGene        | Decimal | Fitness | Probability | Expected")
        print("-----------------------------------------------------------")
        for i, genome in enumerate(population):
            decimal_value = binary_to_decimal(genome)
            print(f"{genome} | {decimal_value:<7} | {fitness_values[i]:<7} | {probabilities[i]:<11.3f} | {expected_counts[i]:<7}")

        # Selection and crossover
        selected_population = []
        for i, count in enumerate(expected_counts):
            selected_population.extend([population[i]] * count)

        print(f"\nSelected Genes for Crossover: {selected_population}")

        # Perform crossover on selected genes
        new_population = []
        for i in range(0, len(selected_population) - 1, 2):
            parent1, parent2 = selected_population[i], selected_population[i + 1]
            child1, child2 = single_point_crossover(parent1, parent2)
            new_population.extend([child1, child2])

        # Apply mutation
        mutated_population = [mutate(genome) for genome in new_population]
        print(f"\nMutated Population: {mutated_population}\n")

        # Update population
        population = mutated_population

    # Final best solution
    best_genome = max(population, key=fitness_function)
    print(f"Best genome after {GENERATIONS} generations: {best_genome} with fitness: {fitness_function(best_genome)}")

if __name__ == "__main__":
    genetic_algorithm()
