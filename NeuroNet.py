#My own version of a neuron

class Perceptron:
    parameters = []
    weights = []        #So you don't need to do this? (explicitly initialize)
    threshold_values = 0
    choice = 0
    def __init__(self, params, weight_list, thresholds):
        self.parameters = params
        self.weights = weight_list
        self.threshold_values = thresholds

    def run(self, threshold_values):
        determine = 0
        for num, weight in enumerate(weights):
            print(f"Multiplying {parameters[num]} by {weight}. Determine's value is {determine:_}")
            determine += parameters[num] * weight
        if determine > threshold_values:
            return 1
        else:
            return 0
        print("Calculated value was", determine)

    def print(self, choice):
        if choice == 0:
            print("Choice was 0")
        else:
            print("Choice was 1")




num = int(input("Enter the number of parameters"))
parameters = []
for i in range(num):
    parameters.append(float(input("Enter a number to put into the neuron as a parameter.")))

choice = input("Would you like to enter the weights manually (y/n)?")

if choice == 'y':
    weights = []
    for i in range(num):
        weights.append(float(input("Enter a weight.")))
else:
    print("Using default weight distribution.")

thres = float(input("Enter a threshold value:"))



perceptron = Perceptron(parameters, weights, thres)
choice = int(perceptron.run(thres))
print(choice)
perceptron.print(choice)