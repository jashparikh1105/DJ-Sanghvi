import numpy as np
import pandas as pd

class PerceptronNetwork:
    def __init__(self, input_size):
        self.weights = np.random.randn(input_size)
        self.bias = np.random.rand(1)

    def predict(self, x):
        weighted_sum = np.dot(self.weights, x) + self.bias
        return 1 if weighted_sum >= 0 else 0

    def train(self, X, y, learning_rate, epochs):
        results = []
        for epoch in range(epochs):
            for i in range(len(X)):
                prediction = self.predict(X[i])
                error = y[i] - prediction
                self.weights += learning_rate * error * X[i]
                self.bias += learning_rate * error

                # Save training step info
                results.append({
                    "Epoch": epoch + 1,
                    "Sample": i,
                    "Input": X[i],
                    "Prediction": prediction,
                    "Expected": y[i],
                    "Error": error,
                    "Weights": self.weights.copy(),
                    "Bias": self.bias[0],
                    "Learning Rate": learning_rate
                })

        # Convert to DataFrame and print results
        df_results = pd.DataFrame(results)
        print("\nTraining Log:")
        print(df_results)

# XOR Dataset
X = np.array([[0, 0],
              [0, 1],
              [1, 0],
              [1, 1]])

y = np.array([0, 1, 1, 0])  # XOR output (not linearly separable)

# Create perceptron and train
perceptron = PerceptronNetwork(input_size=2)

# Initial training (1 epoch)
print("🔁 Initial Training (1 Epoch)")
perceptron.train(X, y, learning_rate=0.1, epochs=1)

# Predictions after 1 epoch
print("\n🔎 Predictions after 1 epoch:")
for x in X:
    print(f"Input: {x}, Prediction: {perceptron.predict(x)}")

# Further training (10 epochs)
print("\n🔁 Further Training (10 Epochs)")
perceptron.train(X, y, learning_rate=0.1, epochs=10)

# Final predictions
print("\n✅ Final Predictions after training:")
for x in X:
    print(f"Input: {x}, Prediction: {perceptron.predict(x)}")
