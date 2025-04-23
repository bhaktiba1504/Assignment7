# Online Python compiler (interpreter) to run Python online.
# Write Python 3 code in this online editor and run it.
class StatisticsCalculator:
    def __init__(self, data):
        self.data = sorted(data)

    def mean(self):
        return sum(self.data) / len(self.data)

    def median(self):
        n = len(self.data)
        mid = n // 2
        if n % 2 == 0:
            return (self.data[mid - 1] + self.data[mid]) / 2
        else:
            return self.data[mid]

    def mode(self):
        freq = {}
        for num in self.data:
            freq[num] = freq.get(num, 0) + 1
        max_freq = max(freq.values())
        return [k for k, v in freq.items() if v == max_freq]

# Runtime input
n = int(input("Enter number of elements: "))
data = []

print("Enter numbers:")
for _ in range(n):
    data.append(int(input()))

stats = StatisticsCalculator(data)
print("Mean:", round(stats.mean(), 2))
print("Median:", round(stats.median(), 2))
print("Mode:", stats.mode())
